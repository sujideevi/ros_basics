#include <ros/ros.h>
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

const double x_min = 0.0;
const double x_max = 11.0;
const double y_min = 0.0;
const double y_max = 11.0;

ros::Publisher velocityPublisher;
ros::Subscriber poseSubscriber;
turtlesim::Pose turtlesimPose;

double getDistance(double goal_x, double goal_y)
{
    ros::spinOnce();
    return sqrt(pow((turtlesimPose.x-goal_x),2) + pow((turtlesimPose.y-goal_y),2));
}

int goToGoal(turtlesim::Pose robotGoalPose, double distanceTolerance)
{
    ROS_INFO("Goal-x:%f Goal-y:%f Goal-theta:%f", robotGoalPose.x, robotGoalPose.y, robotGoalPose.theta);
    geometry_msgs::Twist velocityMsg;

    double kp = 1.0;
    double ki = 0.02;
    double distanceToGoal = 0;

    velocityMsg.linear.x = 0;
    velocityMsg.linear.y = 0;
    velocityMsg.linear.z = 0;

    velocityMsg.angular.x = 0;
    velocityMsg.angular.y = 0;
    velocityMsg.angular.z = 0;

    do
    {
        distanceToGoal = getDistance(robotGoalPose.x, robotGoalPose.y);

        velocityMsg.linear.x = kp * distanceToGoal;
        velocityMsg.angular.z = 4 * (atan2(robotGoalPose.y - turtlesimPose.y, robotGoalPose.x-turtlesimPose.x)-turtlesimPose.theta);
        velocityPublisher.publish(velocityMsg);
    }while(getDistance(robotGoalPose.x, robotGoalPose.y) > distanceTolerance);
    //DEFECT: Just checking the goal reachablity. no orientation check.

    velocityMsg.linear.x = 0;
    velocityMsg.angular.z = 0;
    velocityPublisher.publish(velocityMsg);
    return 0;
}

void pose_callback(const turtlesim::Pose::Ptr turtlesimPosePtr)
{
    turtlesimPose.x = turtlesimPosePtr->x;
    turtlesimPose.y = turtlesimPosePtr->y;
    turtlesimPose.theta = turtlesimPosePtr->theta;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "simple_gotogoal");
    int x = 3, y = 3;
    turtlesim::Pose robotGoalPose;
    ros::NodeHandle nh;
    velocityPublisher = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
    poseSubscriber = nh.subscribe("/turtle1/pose",10, pose_callback);
    ros::Rate loopFreq(0.5);
    ros::spinOnce();

    robotGoalPose.x = 1;
    robotGoalPose.y = 1;
    robotGoalPose.theta = 0.75;

    goToGoal(robotGoalPose, 0.01);

    return 0;
}