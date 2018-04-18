// Generated by gencpp from file ros_dnn_msgs/Prediction.msg
// DO NOT EDIT!


#ifndef ROS_DNN_MSGS_MESSAGE_PREDICTION_H
#define ROS_DNN_MSGS_MESSAGE_PREDICTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_dnn_msgs
{
template <class ContainerAllocator>
struct Prediction_
{
  typedef Prediction_<ContainerAllocator> Type;

  Prediction_()
    : classes()
    , probabilities()
    , xmin(0)
    , ymin(0)
    , xmax(0)
    , ymax(0)  {
    }
  Prediction_(const ContainerAllocator& _alloc)
    : classes(_alloc)
    , probabilities(_alloc)
    , xmin(0)
    , ymin(0)
    , xmax(0)
    , ymax(0)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _classes_type;
  _classes_type classes;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _probabilities_type;
  _probabilities_type probabilities;

   typedef int64_t _xmin_type;
  _xmin_type xmin;

   typedef int64_t _ymin_type;
  _ymin_type ymin;

   typedef int64_t _xmax_type;
  _xmax_type xmax;

   typedef int64_t _ymax_type;
  _ymax_type ymax;





  typedef boost::shared_ptr< ::ros_dnn_msgs::Prediction_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_dnn_msgs::Prediction_<ContainerAllocator> const> ConstPtr;

}; // struct Prediction_

typedef ::ros_dnn_msgs::Prediction_<std::allocator<void> > Prediction;

typedef boost::shared_ptr< ::ros_dnn_msgs::Prediction > PredictionPtr;
typedef boost::shared_ptr< ::ros_dnn_msgs::Prediction const> PredictionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_dnn_msgs::Prediction_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_dnn_msgs::Prediction_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ros_dnn_msgs::Prediction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_dnn_msgs::Prediction_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_dnn_msgs::Prediction_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_dnn_msgs::Prediction_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_dnn_msgs::Prediction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_dnn_msgs::Prediction_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_dnn_msgs::Prediction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "85c71b28980aa0f9ec143fbe776478bf";
  }

  static const char* value(const ::ros_dnn_msgs::Prediction_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x85c71b28980aa0f9ULL;
  static const uint64_t static_value2 = 0xec143fbe776478bfULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_dnn_msgs::Prediction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_dnn_msgs/Prediction";
  }

  static const char* value(const ::ros_dnn_msgs::Prediction_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_dnn_msgs::Prediction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] classes\n\
float64[] probabilities\n\
int64 xmin\n\
int64 ymin\n\
int64 xmax\n\
int64 ymax\n\
";
  }

  static const char* value(const ::ros_dnn_msgs::Prediction_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_dnn_msgs::Prediction_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.classes);
      stream.next(m.probabilities);
      stream.next(m.xmin);
      stream.next(m.ymin);
      stream.next(m.xmax);
      stream.next(m.ymax);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Prediction_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_dnn_msgs::Prediction_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_dnn_msgs::Prediction_<ContainerAllocator>& v)
  {
    s << indent << "classes[]" << std::endl;
    for (size_t i = 0; i < v.classes.size(); ++i)
    {
      s << indent << "  classes[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.classes[i]);
    }
    s << indent << "probabilities[]" << std::endl;
    for (size_t i = 0; i < v.probabilities.size(); ++i)
    {
      s << indent << "  probabilities[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.probabilities[i]);
    }
    s << indent << "xmin: ";
    Printer<int64_t>::stream(s, indent + "  ", v.xmin);
    s << indent << "ymin: ";
    Printer<int64_t>::stream(s, indent + "  ", v.ymin);
    s << indent << "xmax: ";
    Printer<int64_t>::stream(s, indent + "  ", v.xmax);
    s << indent << "ymax: ";
    Printer<int64_t>::stream(s, indent + "  ", v.ymax);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_DNN_MSGS_MESSAGE_PREDICTION_H
