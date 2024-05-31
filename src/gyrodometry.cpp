/**
 * @file gyrodometry.cpp
 * @author Toshiki Nakamura
 * @brief C++ implementation of Gyrodometry
 * @copyright Copyright (c) 2024
 */

#include <nav_msgs/Odometry.h>
#include <optional>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <tf2_ros/transform_broadcaster.h>

/**
 * @class Gyrodometry
 * @brief Class for estimating odometry using gyroscope
 */
class Gyrodometry
{
public:
  /**
   * @brief Construct a new Gyrodometry object
   */
  Gyrodometry(void) : private_nh_("~")
  {
    gyrodom_pub_ = nh_.advertise<nav_msgs::Odometry>("/gyrodom", 1);
    imu_sub_ =
        nh_.subscribe("/imu", 1, &Gyrodometry::imu_callback, this, ros::TransportHints().reliable().tcpNoDelay());
    odom_sub_ =
        nh_.subscribe("/odom", 1, &Gyrodometry::odom_callback, this, ros::TransportHints().reliable().tcpNoDelay());
    ROS_INFO_STREAM(ros::this_node::getName() << " node has started..");
  }

private:
  /**
   * @brief Callback function for imu
   * @param msg imu message
  */
  void imu_callback(const sensor_msgs::Imu::ConstPtr &msg)
  {

  }

  /**
   * @brief Callback function for odom
   * @param msg odom message
   */
  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg)
  {

  }

  ros::NodeHandle nh_;
  ros::NodeHandle private_nh_;
  ros::Publisher gyrodom_pub_;
  ros::Subscriber imu_sub_;
  ros::Subscriber odom_sub_;

  std::optional<sensor_msgs::Imu> prev_imu_;
  std::optional<sensor_msgs::Imu> last_imu_;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "gyrodometry");
  Gyrodometry gyrodometry;
  ros::spin();

  return 0;
}
