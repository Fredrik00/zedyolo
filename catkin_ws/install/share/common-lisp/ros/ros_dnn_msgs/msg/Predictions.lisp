; Auto-generated. Do not edit!


(cl:in-package ros_dnn_msgs-msg)


;//! \htmlinclude Predictions.msg.html

(cl:defclass <Predictions> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (image_header
    :reader image_header
    :initarg :image_header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (predictions
    :reader predictions
    :initarg :predictions
    :type (cl:vector ros_dnn_msgs-msg:Prediction)
   :initform (cl:make-array 0 :element-type 'ros_dnn_msgs-msg:Prediction :initial-element (cl:make-instance 'ros_dnn_msgs-msg:Prediction))))
)

(cl:defclass Predictions (<Predictions>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Predictions>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Predictions)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_dnn_msgs-msg:<Predictions> is deprecated: use ros_dnn_msgs-msg:Predictions instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Predictions>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_dnn_msgs-msg:header-val is deprecated.  Use ros_dnn_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'image_header-val :lambda-list '(m))
(cl:defmethod image_header-val ((m <Predictions>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_dnn_msgs-msg:image_header-val is deprecated.  Use ros_dnn_msgs-msg:image_header instead.")
  (image_header m))

(cl:ensure-generic-function 'predictions-val :lambda-list '(m))
(cl:defmethod predictions-val ((m <Predictions>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_dnn_msgs-msg:predictions-val is deprecated.  Use ros_dnn_msgs-msg:predictions instead.")
  (predictions m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Predictions>) ostream)
  "Serializes a message object of type '<Predictions>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'image_header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'predictions))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'predictions))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Predictions>) istream)
  "Deserializes a message object of type '<Predictions>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'image_header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'predictions) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'predictions)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'ros_dnn_msgs-msg:Prediction))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Predictions>)))
  "Returns string type for a message object of type '<Predictions>"
  "ros_dnn_msgs/Predictions")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Predictions)))
  "Returns string type for a message object of type 'Predictions"
  "ros_dnn_msgs/Predictions")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Predictions>)))
  "Returns md5sum for a message object of type '<Predictions>"
  "e8f2722f41345af9af48afda89620cb9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Predictions)))
  "Returns md5sum for a message object of type 'Predictions"
  "e8f2722f41345af9af48afda89620cb9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Predictions>)))
  "Returns full string definition for message of type '<Predictions>"
  (cl:format cl:nil "Header header~%Header image_header~%Prediction[] predictions~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: ros_dnn_msgs/Prediction~%string[] classes~%float64[] probabilities~%int64 xmin~%int64 ymin~%int64 xmax~%int64 ymax~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Predictions)))
  "Returns full string definition for message of type 'Predictions"
  (cl:format cl:nil "Header header~%Header image_header~%Prediction[] predictions~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: ros_dnn_msgs/Prediction~%string[] classes~%float64[] probabilities~%int64 xmin~%int64 ymin~%int64 xmax~%int64 ymax~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Predictions>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'image_header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'predictions) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Predictions>))
  "Converts a ROS message object to a list"
  (cl:list 'Predictions
    (cl:cons ':header (header msg))
    (cl:cons ':image_header (image_header msg))
    (cl:cons ':predictions (predictions msg))
))
