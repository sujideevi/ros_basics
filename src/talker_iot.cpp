#include "ros/ros.h"
#include "ros_basics/iotSensor.h"

using namespace ros;
int count = 0;
int main(int argc, char** argv)
{
    init(argc, argv, "iotTalkerNode");
    NodeHandle nh;
    Publisher pub = nh.advertise<ros_basics::iotSensor>("iot_pub", 1000);
    Rate loop_rate(0.5);

    while(ok())
    {
        ros_basics::iotSensor msg;
        msg.id = count;
        msg.name = "sensor1";
        msg.temperature = 30;
        msg.humidity = 10;

        ROS_INFO("[IOT_PUB] id:<%d> name:<%s> temperature: <%f> humidity:<%f>", 
                        msg.id, msg.name.c_str(), msg.temperature, msg.humidity);
        pub.publish(msg);
        spinOnce();
        loop_rate.sleep();
        count++;
    }
    return 0;
}