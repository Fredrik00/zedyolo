;; Auto-generated. Do not edit!


(when (boundp 'ros_dnn_msgs::Predictions)
  (if (not (find-package "ROS_DNN_MSGS"))
    (make-package "ROS_DNN_MSGS"))
  (shadow 'Predictions (find-package "ROS_DNN_MSGS")))
(unless (find-package "ROS_DNN_MSGS::PREDICTIONS")
  (make-package "ROS_DNN_MSGS::PREDICTIONS"))

(in-package "ROS")
;;//! \htmlinclude Predictions.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ros_dnn_msgs::Predictions
  :super ros::object
  :slots (_header _image_header _predictions ))

(defmethod ros_dnn_msgs::Predictions
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:image_header __image_header) (instance std_msgs::Header :init))
    ((:predictions __predictions) (let (r) (dotimes (i 0) (push (instance ros_dnn_msgs::Prediction :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _image_header __image_header)
   (setq _predictions __predictions)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:image_header
   (&rest __image_header)
   (if (keywordp (car __image_header))
       (send* _image_header __image_header)
     (progn
       (if __image_header (setq _image_header (car __image_header)))
       _image_header)))
  (:predictions
   (&rest __predictions)
   (if (keywordp (car __predictions))
       (send* _predictions __predictions)
     (progn
       (if __predictions (setq _predictions (car __predictions)))
       _predictions)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/Header _image_header
    (send _image_header :serialization-length)
    ;; ros_dnn_msgs/Prediction[] _predictions
    (apply #'+ (send-all _predictions :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/Header _image_header
       (send _image_header :serialize s)
     ;; ros_dnn_msgs/Prediction[] _predictions
     (write-long (length _predictions) s)
     (dolist (elem _predictions)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/Header _image_header
     (send _image_header :deserialize buf ptr-) (incf ptr- (send _image_header :serialization-length))
   ;; ros_dnn_msgs/Prediction[] _predictions
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _predictions (let (r) (dotimes (i n) (push (instance ros_dnn_msgs::Prediction :init) r)) r))
     (dolist (elem- _predictions)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get ros_dnn_msgs::Predictions :md5sum-) "e8f2722f41345af9af48afda89620cb9")
(setf (get ros_dnn_msgs::Predictions :datatype-) "ros_dnn_msgs/Predictions")
(setf (get ros_dnn_msgs::Predictions :definition-)
      "Header header
Header image_header
Prediction[] predictions

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: ros_dnn_msgs/Prediction
string[] classes
float64[] probabilities
int64 xmin
int64 ymin
int64 xmax
int64 ymax

")



(provide :ros_dnn_msgs/Predictions "e8f2722f41345af9af48afda89620cb9")


