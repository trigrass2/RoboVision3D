/*
 * dense_reconstruction.cpp
 *
 *  Created on: Sep 11, 2013
 *      Author: thomas
 */

#include <ros/ros.h>
#include <nodelet/loader.h>
#include <image_proc/advertisement_checker.h>


//Loading monucular nodelet already in ros
void loadMonocularNodelets(nodelet::Loader& manager, const std::string& side,
                           const XmlRpc::XmlRpcValue& rectify_params,
                           const nodelet::V_string& my_argv)
{
  nodelet::M_string remappings;

  // Explicitly resolve global remappings (wg-ros-pkg #5055).
  // Otherwise the internal remapping 'image_raw' -> 'left/image_raw' can hide a
  // global remapping from the launch file or command line.
  std::string image_raw_topic        = ros::names::resolve(side + "/image_raw");
  std::string image_mono_topic       = ros::names::resolve(side + "/image_mono");
  std::string image_color_topic      = ros::names::resolve(side + "/image_color");
  std::string image_rect_topic       = ros::names::resolve(side + "/image_rect");
  std::string image_rect_color_topic = ros::names::resolve(side + "/image_rect_color");
  std::string camera_info_topic      = ros::names::resolve(side + "/camera_info");

  // Debayer nodelet: image_raw -> image_mono, image_color
  remappings["image_raw"]   = image_raw_topic;
  remappings["image_mono"]  = image_mono_topic;
  remappings["image_color"] = image_color_topic;
  std::string debayer_name = ros::this_node::getName() + "_debayer_" + side;
  manager.load(debayer_name, "image_proc/debayer", remappings, my_argv);

  // Rectify nodelet: image_mono -> image_rect
  remappings.clear();
  remappings["image_mono"]  = image_mono_topic;
  remappings["camera_info"] = camera_info_topic;
  remappings["image_rect"]  = image_rect_topic;
  std::string rectify_mono_name = ros::this_node::getName() + "_rectify_mono_" + side;
  if (rectify_params.valid())
    ros::param::set(rectify_mono_name, rectify_params);
  manager.load(rectify_mono_name, "image_proc/rectify", remappings, my_argv);

  // Rectify nodelet: image_color -> image_rect_color
  remappings.clear();
  remappings["image_mono"]  = image_color_topic;
  remappings["camera_info"] = camera_info_topic;
  remappings["image_rect"]  = image_rect_color_topic;
  std::string rectify_color_name = ros::this_node::getName() + "_rectify_color_" + side;
  if (rectify_params.valid())
    ros::param::set(rectify_color_name, rectify_params);
  manager.load(rectify_color_name, "image_proc/rectify", remappings, my_argv);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "dense_reconstruction");

  // Check for common user errors
  if (ros::names::remap("camera") != "camera")
  {
    ROS_WARN("Remapping 'camera' has no effect! Start dense_reconstruction in the "
             "stereo namespace instead.\nExample command-line usage:\n"
             "\t$ ROS_NAMESPACE=%s rosrun dense_reconstruction dense_reconstruction",
             ros::names::remap("camera").c_str());
  }
  if (ros::this_node::getNamespace() == "/")
  {
    ROS_WARN("Started in the global namespace! This is probably wrong. Start "
             "dense_reconstruction in the stereo namespace.\nExample command-line usage:\n"
             "\t$ ROS_NAMESPACE=my_stereo rosrun dense_reconstruction dense_reconstruction");
  }

  // Shared parameters to be propagated to nodelet private namespaces
  ros::NodeHandle private_nh("~");
  XmlRpc::XmlRpcValue shared_params;
  int queue_size;
  if (private_nh.getParam("queue_size", queue_size))
    shared_params["queue_size"] = queue_size;

  nodelet::Loader manager(false); // Don't bring up the manager ROS API
  nodelet::M_string remappings;
  nodelet::V_string my_argv;

  // Load equivalents of image_proc for left and right cameras
  ROS_INFO("Loading Monocular Nodelets!!");
  loadMonocularNodelets(manager, "left",  shared_params, my_argv);
  loadMonocularNodelets(manager, "right", shared_params, my_argv);

  // Stereo nodelets also need to know the synchronization policy
  bool approx_sync;
  if (private_nh.getParam("approximate_sync", approx_sync))
    shared_params["approximate_sync"] = XmlRpc::XmlRpcValue(approx_sync);

  int algorithm = 1;
  // Disparity nodelet
  // Inputs: left/image_rect, left/camera_info, right/image_rect, right/camera_info
  // Outputs: disparity
  // NOTE: Using node name for the disparity nodelet because it is the only one using
  // dynamic_reconfigure so far, and this makes us backwards-compatible with cturtle.

  private_nh.getParam("algorithm", algorithm);

  if(algorithm == 0)
  {
	  ROS_INFO("Loading Disparity BM Nodelets!!");
	  std::string disparity_name = ros::this_node::getName();
	  manager.load(disparity_name, "dense_reconstruction/DisparityNodelet", remappings, my_argv);
  }else
  {
	  ROS_INFO("Loading Disparity SGBM Nodelets!!");
	  std::string disparity_name = ros::this_node::getName();
	  manager.load(disparity_name, "dense_reconstruction/DisparitySGBMNodelet", remappings, my_argv);
  }
  // PointCloud2 nodelet
  // Inputs: left/image_rect_color, left/camera_info, right/camera_info, disparity
  // Outputs: points2
  ROS_INFO("Loading Point_cloud2 Nodelets!!");
  std::string point_cloud2_name = ros::this_node::getName() + "_point_cloud2";
  if (shared_params.valid())
    ros::param::set(point_cloud2_name, shared_params);
  manager.load(point_cloud2_name, "dense_reconstruction/PointCloud2Nodelet", remappings, my_argv);
/*
  // PointCloud (deprecated) nodelet
  // Inputs: left/image_rect_color, left/camera_info, right/camera_info, disparity
  // Outputs: points
  std::string point_cloud_name = ros::this_node::getName() + "_point_cloud";
  if (shared_params.valid())
    ros::param::set(point_cloud_name, shared_params);
  manager.load(point_cloud_name, "stereo_image_proc/point_cloud", remappings, my_argv);
*/

  // Check for only the original camera topics
  ros::V_string topics;
  topics.push_back(ros::names::resolve("left/image_raw"));
  topics.push_back(ros::names::resolve("left/camera_info"));
  topics.push_back(ros::names::resolve("right/image_raw"));
  topics.push_back(ros::names::resolve("right/camera_info"));
  image_proc::AdvertisementChecker check_inputs(ros::NodeHandle(), ros::this_node::getName());
  check_inputs.start(topics, 60.0);

  ros::spin();
  return 0;
}



