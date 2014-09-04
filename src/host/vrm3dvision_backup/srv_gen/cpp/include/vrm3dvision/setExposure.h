/* Auto-generated by genmsg_cpp for file /home/jeppe/workspace-d3/robovision3d/host/vrm3dvision/srv/setExposure.srv */
#ifndef VRM3DVISION_SERVICE_SETEXPOSURE_H
#define VRM3DVISION_SERVICE_SETEXPOSURE_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "ros/service_traits.h"




namespace vrm3dvision
{
template <class ContainerAllocator>
struct setExposureRequest_ {
  typedef setExposureRequest_<ContainerAllocator> Type;

  setExposureRequest_()
  : camera(0)
  , exposure()
  {
  }

  setExposureRequest_(const ContainerAllocator& _alloc)
  : camera(0)
  , exposure(_alloc)
  {
  }

  typedef int32_t _camera_type;
  int32_t camera;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _exposure_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  exposure;

  enum { LEFT_CAMERA = 1 };
  enum { RIGHT_CAMERA = 2 };
  enum { LEFT_AND_RIGHT_CAMERA = 3 };
  enum { COLOR_CAMERA = 4 };
  enum { ALL_CAMERAS = 7 };

  typedef boost::shared_ptr< ::vrm3dvision::setExposureRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vrm3dvision::setExposureRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct setExposureRequest
typedef  ::vrm3dvision::setExposureRequest_<std::allocator<void> > setExposureRequest;

typedef boost::shared_ptr< ::vrm3dvision::setExposureRequest> setExposureRequestPtr;
typedef boost::shared_ptr< ::vrm3dvision::setExposureRequest const> setExposureRequestConstPtr;



template <class ContainerAllocator>
struct setExposureResponse_ {
  typedef setExposureResponse_<ContainerAllocator> Type;

  setExposureResponse_()
  : success(false)
  {
  }

  setExposureResponse_(const ContainerAllocator& _alloc)
  : success(false)
  {
  }

  typedef uint8_t _success_type;
  uint8_t success;


  typedef boost::shared_ptr< ::vrm3dvision::setExposureResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vrm3dvision::setExposureResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct setExposureResponse
typedef  ::vrm3dvision::setExposureResponse_<std::allocator<void> > setExposureResponse;

typedef boost::shared_ptr< ::vrm3dvision::setExposureResponse> setExposureResponsePtr;
typedef boost::shared_ptr< ::vrm3dvision::setExposureResponse const> setExposureResponseConstPtr;


struct setExposure
{

typedef setExposureRequest Request;
typedef setExposureResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct setExposure
} // namespace vrm3dvision

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::vrm3dvision::setExposureRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::vrm3dvision::setExposureRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::vrm3dvision::setExposureRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "74690dad3b322aa8761f4ad7fe2c58c2";
  }

  static const char* value(const  ::vrm3dvision::setExposureRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x74690dad3b322aa8ULL;
  static const uint64_t static_value2 = 0x761f4ad7fe2c58c2ULL;
};

template<class ContainerAllocator>
struct DataType< ::vrm3dvision::setExposureRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vrm3dvision/setExposureRequest";
  }

  static const char* value(const  ::vrm3dvision::setExposureRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::vrm3dvision::setExposureRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int32 LEFT_CAMERA = 1\n\
int32 RIGHT_CAMERA = 2\n\
int32 LEFT_AND_RIGHT_CAMERA = 3\n\
int32 COLOR_CAMERA = 4\n\
int32 ALL_CAMERAS = 7\n\
\n\
int32 camera\n\
string exposure\n\
\n\
";
  }

  static const char* value(const  ::vrm3dvision::setExposureRequest_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::vrm3dvision::setExposureResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::vrm3dvision::setExposureResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::vrm3dvision::setExposureResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const  ::vrm3dvision::setExposureResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::vrm3dvision::setExposureResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vrm3dvision/setExposureResponse";
  }

  static const char* value(const  ::vrm3dvision::setExposureResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::vrm3dvision::setExposureResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "bool success\n\
\n\
\n\
";
  }

  static const char* value(const  ::vrm3dvision::setExposureResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::vrm3dvision::setExposureResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::vrm3dvision::setExposureRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.camera);
    stream.next(m.exposure);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct setExposureRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::vrm3dvision::setExposureResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.success);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct setExposureResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<vrm3dvision::setExposure> {
  static const char* value() 
  {
    return "5ba508c10b2f392acb59bcd971e154d8";
  }

  static const char* value(const vrm3dvision::setExposure&) { return value(); } 
};

template<>
struct DataType<vrm3dvision::setExposure> {
  static const char* value() 
  {
    return "vrm3dvision/setExposure";
  }

  static const char* value(const vrm3dvision::setExposure&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<vrm3dvision::setExposureRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "5ba508c10b2f392acb59bcd971e154d8";
  }

  static const char* value(const vrm3dvision::setExposureRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<vrm3dvision::setExposureRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vrm3dvision/setExposure";
  }

  static const char* value(const vrm3dvision::setExposureRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<vrm3dvision::setExposureResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "5ba508c10b2f392acb59bcd971e154d8";
  }

  static const char* value(const vrm3dvision::setExposureResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<vrm3dvision::setExposureResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vrm3dvision/setExposure";
  }

  static const char* value(const vrm3dvision::setExposureResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // VRM3DVISION_SERVICE_SETEXPOSURE_H
