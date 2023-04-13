#include "ros/ros.h"
#include "ros_basics/iotSensor.h"

using namespace ros;

void iotPub_callback(const ros_basics::iotSensor::ConstPtr& msg)
{
    ROS_INFO("[listnerIot_node] I heard: id:<%d> temp:<%f>", msg->id, msg->temperature);
}

int main(int argc, char** argv)
{
    init(argc, argv, "listnerIot_node");
    NodeHandle nh;
    Subscriber sub = nh.subscribe("iot_pub", 1000, iotPub_callback);
    spin();
    return 0;
}