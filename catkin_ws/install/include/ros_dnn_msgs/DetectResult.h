// Generated by gencpp from file ros_dnn_msgs/DetectResult.msg
// DO NOT EDIT!


#ifndef ROS_DNN_MSGS_MESSAGE_DETECTRESULT_H
#define ROS_DNN_MSGS_MESSAGE_DETECTRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sensor_msgs/Image.h>
#include <ros_dnn_msgs/Predictions.h>

namespace ros_dnn_msgs
{
template <class ContainerAllocator>
struct DetectResult_
{
  typedef DetectResult_<ContainerAllocator> Type;

  DetectResult_()
    : id(0)
    , detection_image()
    , predictions()  {
    }
  DetectResult_(const ContainerAllocator& _alloc)
    : id(0)
    , detection_image(_alloc)
    , predictions(_alloc)  {
  (void)_alloc;
    }



   typedef int16_t _id_type;
  _id_type id;

   typedef  ::sensor_msgs::Image_<ContainerAllocator>  _detection_image_type;
  _detection_image_type detection_image;

   typedef  ::ros_dnn_msgs::Predictions_<ContainerAllocator>  _predictions_type;
  _predictions_type predictions;





  typedef boost::shared_ptr< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> const> ConstPtr;

}; // struct DetectResult_

typedef ::ros_dnn_msgs::DetectResult_<std::allocator<void> > DetectResult;

typedef boost::shared_ptr< ::ros_dnn_msgs::DetectResult > DetectResultPtr;
typedef boost::shared_ptr< ::ros_dnn_msgs::DetectResult const> DetectResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_dnn_msgs::DetectResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ros_dnn_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/lunar/share/std_msgs/cmake/../msg'], 'ros_dnn_msgs': ['/home/nvidia/catkin_ws/src/ros_dnn/ros_dnn_msgs/msg', '/home/nvidia/catkin_ws/devel/share/ros_dnn_msgs/msg'], 'geometry_msgs': ['/opt/ros/lunar/share/geometry_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/lunar/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/lunar/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6f30ee3e8519a3f52a75a14d29ec691c";
  }

  static const char* value(const ::ros_dnn_msgs::DetectResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6f30ee3e8519a3f5ULL;
  static const uint64_t static_value2 = 0x2a75a14d29ec691cULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_dnn_msgs/DetectResult";
  }

  static const char* value(const ::ros_dnn_msgs::DetectResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Result\n\
int16 id\n\
sensor_msgs/Image detection_image\n\
ros_dnn_msgs/Predictions predictions\n\
\n\
\n\
================================================================================\n\
MSG: sensor_msgs/Image\n\
# This message contains an uncompressed image\n\
# (0, 0) is at top-left corner of image\n\
#\n\
\n\
Header header        # Header timestamp should be acquisition time of image\n\
                     # Header frame_id should be optical frame of camera\n\
                     # origin of frame should be optical center of cameara\n\
                     # +x should point to the right in the image\n\
                     # +y should point down in the image\n\
                     # +z should point into to plane of the image\n\
                     # If the frame_id here and the frame_id of the CameraInfo\n\
                     # message associated with the image conflict\n\
                     # the behavior is undefined\n\
\n\
uint32 height         # image height, that is, number of rows\n\
uint32 width          # image width, that is, number of columns\n\
\n\
# The legal values for encoding are in file src/image_encodings.cpp\n\
# If you want to standardize a new string format, join\n\
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n\
\n\
string encoding       # Encoding of pixels -- channel meaning, ordering, size\n\
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n\
\n\
uint8 is_bigendian    # is this data bigendian?\n\
uint32 step           # Full row length in bytes\n\
uint8[] data          # actual matrix data, size is (step * rows)\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: ros_dnn_msgs/Predictions\n\
Header header\n\
Header image_header\n\
Prediction[] predictions\n\
\n\
================================================================================\n\
MSG: ros_dnn_msgs/Prediction\n\
string[] classes\n\
float64[] probabilities\n\
int64 xmin\n\
int64 ymin\n\
int64 xmax\n\
int64 ymax\n\
";
  }

  static const char* value(const ::ros_dnn_msgs::DetectResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.detection_image);
      stream.next(m.predictions);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DetectResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_dnn_msgs::DetectResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_dnn_msgs::DetectResult_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<int16_t>::stream(s, indent + "  ", v.id);
    s << indent << "detection_image: ";
    s << std::endl;
    Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "  ", v.detection_image);
    s << indent << "predictions: ";
    s << std::endl;
    Printer< ::ros_dnn_msgs::Predictions_<ContainerAllocator> >::stream(s, indent + "  ", v.predictions);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_DNN_MSGS_MESSAGE_DETECTRESULT_H