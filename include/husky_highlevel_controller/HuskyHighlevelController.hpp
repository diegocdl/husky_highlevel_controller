#pragma once
// ROS
#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"

namespace husky_highlevel_controller {

/*!
 * Main class for the node to handle the ROS interfacing.
 */
class HuskyHighlevelController
{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  HuskyHighlevelController(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~HuskyHighlevelController();

 private:


  /*!
   * ROS topic callback method.
   * @param message the received message.
   */
  void scanCallback(const sensor_msgs::LaserScan& msg);

 
  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS topic subscriber.
  ros::Subscriber subscriber_;

  std::string topic_name_;
  std::int32_t topic_size_queue_;

};

} /* namespace */
