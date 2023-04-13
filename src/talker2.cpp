#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

using namespace std;
using namespace ros;
int main(int argc, char **argv)
{
    init(argc, argv, "talker_node");
    NodeHandle nh;
    Publisher pub = nh.advertise<std_msgs::String>("chatter",1000);
    Rate loop_rate(0.5);
    ROS_INFO("Initialization done");

    int count = 0;
    while(ok())
    {
        stringstream ss;
        ss << "Hello :" << count;

        std_msgs::String msg;

        msg.data = ss.str();
        ROS_INFO("I am publishing: {%s}", msg.data.c_str());
        pub.publish(msg);
        spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}