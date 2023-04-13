#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

using namespace ros;
int main(int argc, char **argv)
{
    init(argc, argv, "talker_node");
    NodeHandle nh;
    Publisher publisher = nh.advertise<std_msgs::String>("chatter", 1000);
    Rate loop_rate(0.5);

    int count = 0;
    while(ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello " << count;
        msg.data = ss.str();
        ROS_INFO("[Talker] I published %s\n", msg.data.c_str());
        publisher.publish(msg);
        spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}