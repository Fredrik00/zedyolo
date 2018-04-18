
(cl:in-package :asdf)

(defsystem "ros_dnn_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :actionlib_msgs-msg
               :sensor_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "DetectAction" :depends-on ("_package_DetectAction"))
    (:file "_package_DetectAction" :depends-on ("_package"))
    (:file "DetectActionFeedback" :depends-on ("_package_DetectActionFeedback"))
    (:file "_package_DetectActionFeedback" :depends-on ("_package"))
    (:file "DetectActionGoal" :depends-on ("_package_DetectActionGoal"))
    (:file "_package_DetectActionGoal" :depends-on ("_package"))
    (:file "DetectActionResult" :depends-on ("_package_DetectActionResult"))
    (:file "_package_DetectActionResult" :depends-on ("_package"))
    (:file "DetectFeedback" :depends-on ("_package_DetectFeedback"))
    (:file "_package_DetectFeedback" :depends-on ("_package"))
    (:file "DetectGoal" :depends-on ("_package_DetectGoal"))
    (:file "_package_DetectGoal" :depends-on ("_package"))
    (:file "DetectResult" :depends-on ("_package_DetectResult"))
    (:file "_package_DetectResult" :depends-on ("_package"))
    (:file "Prediction" :depends-on ("_package_Prediction"))
    (:file "_package_Prediction" :depends-on ("_package"))
    (:file "Predictions" :depends-on ("_package_Predictions"))
    (:file "_package_Predictions" :depends-on ("_package"))
  ))