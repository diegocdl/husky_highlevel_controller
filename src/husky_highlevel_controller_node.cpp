#include <ros/ros.h>
#include "husky_highlevel_controller/HuskyHighlevelController.hpp"

int main(int argc, char **argv) {
  ros::init(argc, argv, "husky_highlevel_controller");
  ros::NodeHandle nodeHandle;

//
//  std::string topic_name;
//  int queue_size;
//  nodeHandle.getParam("scan_topic_name", topic_name);
//  nodeHandle.getParam("scan_topic_queue_size", queue_size);
//  ros::Subscriber subscriber = nodeHandle.subscribe(topic_name, queue_size, &scanCallback);
  //ros::Subscriber subscriber = nodeHandle.subscribe("/scan", 10, scanCallback);

  husky_highlevel_controller::HuskyHighlevelController huskyHighlevelController(nodeHandle);

  ros::spin();
  return 0;
}
