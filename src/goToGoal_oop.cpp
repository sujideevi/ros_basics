#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include "boost/bind.hpp"

struct botController
{
    double kp;
    double ki;
};
class MyTurtle
{
    public:
        void goToGoal();
        MyTurtle();
    private:
        void pose_callback(turtlesim::Pose::Ptr botPosePtr);
        double getDistanceToGoal();

        turtlesim::Pose m_goal;
        turtlesim::Pose m_botPose;
        ros::Publisher m_velocityPublisher;
        ros::Subscriber m_poseSubscriber;
        ros::NodeHandle m_nh;
};

MyTurtle::MyTurtle()
{
    m_velocityPublisher = m_nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    m_poseSubscriber = m_nh.subscribe("/turtle1/pose",1000, &MyTurtle::pose_callback, this);
}

void MyTurtle::pose_callback(turtlesim::Pose::Ptr botPosePtr)
{
    m_botPose.x = botPosePtr->x;
    m_botPose.y = botPosePtr->y;
    m_botPose.theta = botPosePtr->theta;
}
double MyTurtle::getDistanceToGoal()
{
    ros::spinOnce();
    return sqrt(pow((m_botPose.x - m_goal.x),2)+pow((m_botPose.y-m_goal.y),2));
}

void MyTurtle::goToGoal()
{

}

int main(int argc, char **argv)
{
    return 0;
}