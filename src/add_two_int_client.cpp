#include <ros/ros.h>
#include <ros_basics/addTwoInt.h>


int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_int_client");

    if(argc != 3)
    {
        ROS_INFO("Usage: addTwoInt X Y");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<ros_basics::addTwoInt>("myAddTwoInt");

    ros_basics::addTwoInt srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    if(client.call(srv))
    {
        ROS_INFO("AddTwoInt Result: <%ld>", srv.response.sum);
    }
    else
    {
        ROS_ERROR("Unable to call addTwoInt");
        return 1;
    }
    return 0;
}