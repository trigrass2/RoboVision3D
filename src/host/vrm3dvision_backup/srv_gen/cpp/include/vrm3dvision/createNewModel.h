/* Auto-generated by genmsg_cpp for file /home/jeppe/workspace-d3/robovision3d/host/vrm3dvision/srv/createNewModel.srv */
#ifndef VRM3DVISION_SERVICE_CREATENEWMODEL_H
#define VRM3DVISION_SERVICE_CREATENEWMODEL_H
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

#include "vrm3dvision/SurfaceModelParams.h"
#include "vrm3dvision/AlignmentPrerejectiveParams.h"



namespace vrm3dvision
{
template <class ContainerAllocator>
struct createNewModelRequest_ {
  typedef createNewModelRequest_<ContainerAllocator> Type;

  createNewModelRequest_()
  : model_name()
  , cad_path()
  , smp()
  , app()
  {
  }

  createNewModelRequest_(const ContainerAllocator& _alloc)
  : model_name(_alloc)
  , cad_path(_alloc)
  , smp(_alloc)
  , app(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _model_name_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  model_name;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _cad_path_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  cad_path;

  typedef  ::vrm3dvision::SurfaceModelParams_<ContainerAllocator>  _smp_type;
   ::vrm3dvision::SurfaceModelParams_<ContainerAllocator>  smp;

  typedef  ::vrm3dvision::AlignmentPrerejectiveParams_<ContainerAllocator>  _app_type;
   ::vrm3dvision::AlignmentPrerejectiveParams_<ContainerAllocator>  app;


  typedef boost::shared_ptr< ::vrm3dvision::createNewModelRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vrm3dvision::createNewModelRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct createNewModelRequest
typedef  ::vrm3dvision::createNewModelRequest_<std::allocator<void> > createNewModelRequest;

typedef boost::shared_ptr< ::vrm3dvision::createNewModelRequest> createNewModelRequestPtr;
typedef boost::shared_ptr< ::vrm3dvision::createNewModelRequest const> createNewModelRequestConstPtr;



template <class ContainerAllocator>
struct createNewModelResponse_ {
  typedef createNewModelResponse_<ContainerAllocator> Type;

  createNewModelResponse_()
  : success(false)
  {
  }

  createNewModelResponse_(const ContainerAllocator& _alloc)
  : success(false)
  {
  }

  typedef uint8_t _success_type;
  uint8_t success;


  typedef boost::shared_ptr< ::vrm3dvision::createNewModelResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vrm3dvision::createNewModelResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct createNewModelResponse
typedef  ::vrm3dvision::createNewModelResponse_<std::allocator<void> > createNewModelResponse;

typedef boost::shared_ptr< ::vrm3dvision::createNewModelResponse> createNewModelResponsePtr;
typedef boost::shared_ptr< ::vrm3dvision::createNewModelResponse const> createNewModelResponseConstPtr;


struct createNewModel
{

typedef createNewModelRequest Request;
typedef createNewModelResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct createNewModel
} // namespace vrm3dvision

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::vrm3dvision::createNewModelRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::vrm3dvision::createNewModelRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::vrm3dvision::createNewModelRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "0289611c348901a03687721922924c36";
  }

  static const char* value(const  ::vrm3dvision::createNewModelRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x0289611c348901a0ULL;
  static const uint64_t static_value2 = 0x3687721922924c36ULL;
};

template<class ContainerAllocator>
struct DataType< ::vrm3dvision::createNewModelRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vrm3dvision/createNewModelRequest";
  }

  static const char* value(const  ::vrm3dvision::createNewModelRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::vrm3dvision::createNewModelRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "string model_name\n\
string cad_path\n\
SurfaceModelParams smp\n\
AlignmentPrerejectiveParams app\n\
\n\
================================================================================\n\
MSG: vrm3dvision/SurfaceModelParams\n\
#### Common parameters\n\
float64 rel_sampling_distance\n\
\n\
#### Creation parameters\n\
int8 	model_invert_normals\n\
float64 pose_ref_rel_sampling_distance\n\
float64 feat_step_size_rel\n\
uint16 feat_angle_resolution\n\
\n\
#### Detection parameters\n\
\n\
## Approximate matching\n\
float64 key_point_fraction\n\
float64 min_score\n\
int8 	return_result_handle\n\
int8 	num_matches\n\
float64 max_overlap_dist_rel\n\
\n\
## Sparse pose refinement\n\
int8 	sparse_pose_refinement\n\
string 	score_type\n\
int8 	pose_ref_use_scene_normals\n\
\n\
## Dense pose refinement\n\
int8 	dense_pose_refinement\n\
uint16 	pose_ref_num_steps\n\
uint16 	pose_ref_sub_sampling\n\
float64 pose_ref_dist_threshold_rel\n\
float64 pose_ref_scoring_dist_rel\n\
\n\
## Evaluation\n\
float64 min_score_threshold\n\
bool 	reset_to_default\n\
\n\
\n\
\n\
================================================================================\n\
MSG: vrm3dvision/AlignmentPrerejectiveParams\n\
#### Common parameters\n\
float64 leaf_size\n\
float64 normal_radius_ratio_leaf\n\
float64 feature_radius_ratio_leaf\n\
uint32 	correspondence_randomness\n\
float64 similarity_threshold\n\
uint32 	max_iterations\n\
float64 max_correspondence_distance_ratio_leaf\n\
float64 inlier_fraction\n\
\n\
## ICP\n\
uint32 	icp_max_iterations\n\
float64 icp_max_correspondence_distance_ratio_leaf\n\
\n\
# Alignment Prerejective\n\
float64 min_score\n\
float64 min_score_threshold\n\
\n\
\n\
\n\
\n\
\n\
";
  }

  static const char* value(const  ::vrm3dvision::createNewModelRequest_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::vrm3dvision::createNewModelResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::vrm3dvision::createNewModelResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::vrm3dvision::createNewModelResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const  ::vrm3dvision::createNewModelResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::vrm3dvision::createNewModelResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vrm3dvision/createNewModelResponse";
  }

  static const char* value(const  ::vrm3dvision::createNewModelResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::vrm3dvision::createNewModelResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "bool success\n\
\n\
\n\
";
  }

  static const char* value(const  ::vrm3dvision::createNewModelResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::vrm3dvision::createNewModelResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::vrm3dvision::createNewModelRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.model_name);
    stream.next(m.cad_path);
    stream.next(m.smp);
    stream.next(m.app);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct createNewModelRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::vrm3dvision::createNewModelResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.success);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct createNewModelResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<vrm3dvision::createNewModel> {
  static const char* value() 
  {
    return "5b06b70d26b98c2e4972576e2b4a1d1a";
  }

  static const char* value(const vrm3dvision::createNewModel&) { return value(); } 
};

template<>
struct DataType<vrm3dvision::createNewModel> {
  static const char* value() 
  {
    return "vrm3dvision/createNewModel";
  }

  static const char* value(const vrm3dvision::createNewModel&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<vrm3dvision::createNewModelRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "5b06b70d26b98c2e4972576e2b4a1d1a";
  }

  static const char* value(const vrm3dvision::createNewModelRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<vrm3dvision::createNewModelRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vrm3dvision/createNewModel";
  }

  static const char* value(const vrm3dvision::createNewModelRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<vrm3dvision::createNewModelResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "5b06b70d26b98c2e4972576e2b4a1d1a";
  }

  static const char* value(const vrm3dvision::createNewModelResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<vrm3dvision::createNewModelResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "vrm3dvision/createNewModel";
  }

  static const char* value(const vrm3dvision::createNewModelResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // VRM3DVISION_SERVICE_CREATENEWMODEL_H
