#include "husky_highlevel_controller/HuskyHighlevelController.hpp"
#include <ros/ros.h>

namespace husky_highlevel_controller {
  HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle)
      : nodeHandle_(nodeHandle)
  {
    if (!(nodeHandle.getParam("scan_topic_name", topic_name_)
            & nodeHandle.getParam("scan_topic_queue_size", topic_size_queue_))) {
      ROS_ERROR("Could not read parameters.");
      ros::requestShutdown();
    }
    subscriber_ = nodeHandle_.subscribe(topic_name_, 1,
                                        &HuskyHighlevelController::scanCallback, this);
    ROS_INFO("Successfully launched node.");
  }

  HuskyHighlevelController::~HuskyHighlevelController()
  {
  }


  void HuskyHighlevelController::scanCallback(const sensor_msgs::LaserScan& msg) {
    std::vector<float> ranges = msg.ranges;
    float small = ranges[0];
    for (float v:ranges) {
      if(small > v) {
        small = v;
      }
    }
    ROS_INFO_STREAM("Min range: " + std::to_string(small));

  }
}
