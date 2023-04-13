#include "ros/ros.h"
#include "ros_basics/addTwoInt.h"

using namespace ros;

bool add(ros_basics::addTwoInt::Request &req,
         ros_basics::addTwoInt::Response &res)
{
    res.sum = req.a + req.b;
    ROS_INFO("a:<%ld> b:<%ld> sum:<%ld>", (long int)req.a, (long int)req.b, (long int)res.sum);
    return true;
}
int main(int argc, char** argv)
{
    init(argc, argv, "add_two_int_server");
    NodeHandle nh;
    ServiceServer srv = nh.advertiseService("myAddTwoInt", add);
    ROS_INFO("Ready to add two ints");
    spin();
    return 0;
}