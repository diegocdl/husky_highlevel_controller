#include "husky_highlevel_controller/HuskyHighlevelController.hpp"
#include <ros/ros.h>

namespace husky_highlevel_controller {

  HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle)
      : nodeHandle_(nodeHandle)
  {
    // check if the parameters exists, and if not exists send error and shutdown
    if (!(nodeHandle.getParam("scan_topic_name", topic_name_)
            & nodeHandle.getParam("scan_topic_queue_size", topic_size_queue_))) {
      ROS_ERROR("Could not read parameters.");
      ros::requestShutdown();
    }

    // create a subscriber to the topic_name
    subscriber_ = nodeHandle_.subscribe(topic_name_, 1,
                                        &HuskyHighlevelController::scanCallback, this);
    ROS_INFO("Successfully launched node.");
  }

  HuskyHighlevelController::~HuskyHighlevelController()
  {
  }

  void HuskyHighlevelController::scanCallback(const sensor_msgs::LaserScan& msg) {
    // search for the min value in the vector of msg.ranges
    std::vector<float> ranges = msg.ranges;
    float small = ranges[0];
    for (float v:ranges) {
      if(small > v) {
        small = v;
      }
    }

    // display the ming value
    ROS_INFO_STREAM("Min range: " + std::to_string(small));

  }
}
