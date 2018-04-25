#!/usr/bin/env python

import cv2
import rospy
import roslib
import sys, time
import numpy as np
from sensor_msgs.msg import Image
from object_detection.msg import Prediction, Predictions
import pyyolo
from cv_bridge import CvBridge, CvBridgeError

VERBOSE=False

class image_retriever:

	def __init__(self):
		rospy.init_node('image_retriever', anonymous=True)
		# The first subscriber retrieves image data from the left image and passes it to the callback function
		self.subscriber = rospy.Subscriber('/zed/left/image_rect_color', Image, self.callback, queue_size = 1)
		# The second subscriber retrieves depth data from the camera as 32 bit floats with values in meters and maps this onto an image structure, which is passed to callback2
		self.subscriber2 = rospy.Subscriber('/zed/depth/depth_registered', Image, self.callback2, queue_size = 1)
		# Create a topic to publish prediction data
		self.pred_topic = rospy.Publisher('objdet/predictions', Predictions, queue_size=1)
		self.image = None
		self.depth = None
		self.c = 3
		self.h = 376
		self.w = 672
		self.fov = np.pi/2
		self.thresh = 0.5
		self.hier_thresh = 0.8
		self.bridge = CvBridge()
		fourcc = cv2.VideoWriter_fourcc(*'XVID')
		self.video = cv2.VideoWriter('predictions.avi', fourcc, 5.0, (672,376))
		if VERBOSE :
			print 'subscribed to zed camera'
	

	# The callback functions are handled asynchronously, which probably introduces an added overhead
	def callback(self, ros_data):
		start = time.time()
		# The retrieved image in ros_data is reshaped from a flat structure and normalized
		self.image = np.fromstring(ros_data.data, np.uint8)
		image = self.image
		image = image.reshape((self.h, self.w, 3))
		data = image.transpose(2,0,1)
		data = data.ravel()/255.0
		data = np.ascontiguousarray(data, dtype=np.float32)
		
		# The image, width, height, channels and thresholds are passed into the object detection network
		outputs = pyyolo.detect(self.w, self.h, self.c, data, self.thresh, self.hier_thresh)
		preds = Predictions()	
		# The edges of the bounding boxes of each object is read and depth values calculated, the median of the depth values inside the box is determined as the objects distance
		for output in outputs:
			self.calculate_depth(output)
			self.calculate_coordinates(output)
			#print output
			
			pred = Prediction()			

			pred.probabilities.append(output['prob'])
			pred.classes.append(output['class'])
			
			pred.xmin               = output['left']
			pred.ymin               = output['top']
			pred.xmax               = output['right']
			pred.ymax               = output['bottom']

			pred.distance           = output['distance']
			pred.angle		= output['angle']
			pred.xcoord		= output['x']
			pred.ycoord 		= output['y']

			# self.pred_topic.publish(pred)
		
			preds.predictions.append(pred)

			label = output['class'] + " " + str(output['distance'])

			cv2.rectangle(image, (output['left'],output['top']), (output['right'],output['bottom']), (0,255,0), 2)
			font = cv2.FONT_HERSHEY_SIMPLEX
			cv2.putText(image, label, (output['left'],output['top']+15), font, 0.5,(255,255,255),1,cv2.LINE_AA)

		cv2.imshow("image", image)
		self.video.write(image)
		cv2.waitKey(35)
		
		self.pred_topic.publish(preds)
		end = time.time()
		print("Total cycle time: ", end - start)
		

	def callback2(self, ros_data):
		self.depth = self.bridge.imgmsg_to_cv2(ros_data, desired_encoding="passthrough")

	
	def calculate_depth(self, output):
		l = output['left']
		r = output['right']
		t = output['top']
		b = output['bottom']
		center = (r-(r-l)//2, b-(b-t)//2)
		output['center'] = center
		depth = np.nanmedian(self.depth[l:r, t:b].astype(np.float32))
		if np.isnan(depth):
			depth = self.depth[center[1], center[0]] 
		output['distance'] = depth # Distance between camera and object
	

	def calculate_coordinates(self, output):
		c = output['center']
		d = output['distance']
		St = d*self.fov  # Total lenght of arc at distance from camera
		S = (float(c[0]-self.w/2)/self.w)*St  # Length of arc between center of picture and center of object
		angle = S/d  # Angle in radians towards object, relative to center of image, calculated from the piece of the arc and it's distance
		x = np.sin(angle)*d  # x coordinates (left/right) in meters, relative to center of camera
		y = np.cos(angle)*d  # y coordinates (forwards/backwards) in meters, relative to center of camera
		output["angle"] = (angle/(2*np.pi))*360
		output["x"] = x
		output["y"] = y
			

def main(args):
	darknet_path = './darknet'
	datacfg = 'cfg/coco.data'
	cfgfile = 'cfg/yolov2.cfg'
	weightfile = '../yolov2.weights'
	filename = darknet_path + '/data/person.jpg'

	pyyolo.init(darknet_path, datacfg, cfgfile, weightfile)
	
	'''Initializes and cleanup ros node'''
	ir = image_retriever()	

   	try:
		rospy.spin()
	except KeyboardInterrupt: 
		print "Shutting down ROS Image feature detector module"
	
	# free model
	pyyolo.cleanup()

if __name__ == "__main__":
	main(sys.argv)
