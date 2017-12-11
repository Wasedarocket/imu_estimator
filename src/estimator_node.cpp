#include <ros/ros.h>

#include <std_msgs/String.h>
#include <Eigen>
#include "sensor_msgs/Imu.h"




void imuCallback(const sensor_msgs::ImuConstPtr &imu_msg)

{

  ROS_INFO("I heard: [%f]", imu_msg->linear_acceleration.z);
}

int main(int argc, char **argv)

{

  ros::init(argc, argv, "imu_estimator");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("imu", 1000, imuCallback);

  ros::spin();

  return 0;
}