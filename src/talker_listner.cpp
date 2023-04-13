#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void chatter_callback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    /*ros::init(argc, argv, "talker_listner_node");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter", 1000);
    ros::Subscriber sub = nh.subscribe("chatter", 1000, chatter_callback);
    ros::Rate rate_loop(0.5);

    int count = 0;
    while(ros::ok())
    {
        std::stringstream ss;
        ss << " Hello: " << count;

        std_msgs::String msg;
        msg.data = ss.str();
        ROS_INFO("I am publishing: %s", msg.data.c_str());

        pub.publish(msg);
        ros::spinOnce();
        rate_loop.sleep();

        count++;
    }*/
    return 0;
}