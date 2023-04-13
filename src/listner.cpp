#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("[Listner] I heard: [%s]\n", msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener_node");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);
    ros::spin();
    return 0;
}