#!/usr/bin/env python

import cv2
import rospy
import roslib
import sys, time
import numpy as np
from sensor_msgs.msg import Image
import pyyolo
from cv_bridge import CvBridge, CvBridgeError

VERBOSE=False

class image_retriever:

	def __init__(self):
		self.subscriber = rospy.Subscriber('/zed/left/image_rect_color', Image, self.callback, queue_size = 1)
		self.subscriber2 = rospy.Subscriber('/zed/depth/depth_registered', Image, self.callback2, queue_size = 1)
		self.image = None
		self.depth = None
		self.h = 376
		self.w = 672
		self.bridge = CvBridge()
		if VERBOSE :
			print 'subscribed to zed camera'

	def callback(self, ros_data):
		thresh = 0.7
		hier_thresh = 0.5
		self.image = np.fromstring(ros_data.data, np.uint8)
		image = self.image
		depth = self.depth
		image = image.reshape((self.h, self.w, 3))
		image = image.transpose(2,0,1)
    		c, h, w = image.shape[0], image.shape[1], image.shape[2]
		data = image.ravel()/255.0
		data = np.ascontiguousarray(data, dtype=np.float32)
			
		outputs = pyyolo.detect(w, h, c, data, thresh, hier_thresh)

		for output in outputs:
			l = output['left']
			r = output['right']
			t = output['top']
			b = output['bottom']
			mid = (r-(r-l)//2, b-(b-t)//2)
			print mid
			print("median", np.nanmedian(depth[l:r, t:b]))

	def callback2(self, ros_data):
		self.depth = self.bridge.imgmsg_to_cv2(ros_data, desired_encoding="passthrough")
			

def main(args):
	darknet_path = './darknet'
	datacfg = 'cfg/coco.data'
	cfgfile = 'cfg/yolov2.cfg'
	weightfile = '../yolov2.weights'
	filename = darknet_path + '/data/person.jpg'

	pyyolo.init(darknet_path, datacfg, cfgfile, weightfile)

	'''Initializes and cleanup ros node'''
	ir = image_retriever()
	rospy.init_node('image_retriever', anonymous=True)
   	try:
		rospy.spin()
	except KeyboardInterrupt: 
		print "Shutting down ROS Image feature detector module"
	
	# free model
	pyyolo.cleanup()

if __name__ == "__main__":
	main(sys.argv)
