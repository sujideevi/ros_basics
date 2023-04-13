#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <tf/tf.h>

void odom_pose_extract(const nav_msgs::Odometry::ConstPtr msg)
{
    tf::Quaternion q(
        msg->pose.pose.orientation.x,
        msg->pose.pose.orientation.y,
        msg->pose.pose.orientation.z,
        msg->pose.pose.orientation.w
    );

    tf::Matrix3x3 m(q);

    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    std::cout << "r =" <<roll << " p=" << pitch << " y=" << yaw << std::endl;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pose_extraction");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("odom", 10, odom_pose_extract);
    ros::spin();
    return 0;
}