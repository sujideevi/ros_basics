#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

using namespace std;
using namespace ros;
int main(int argc, char **argv)
{
    init(argc, argv, "talker1_node");
    NodeHandle nh;
    Publisher pub = nh.advertise<std_msgs::String>("talker_topic",1000);
    Rate rate_loop(0.5);

    int count =0;
    while(ok())
    {
        stringstream ss;
        ss << "Hello Senthil" << count;

        std_msgs::String msg;
        msg.data = ss.str();

        ROS_INFO("[talker1_node] Message: {%s}", msg.data.c_str());
        pub.publish(msg);

        spinOnce();
        rate_loop.sleep();
        count++;
    }
    return 0;
}