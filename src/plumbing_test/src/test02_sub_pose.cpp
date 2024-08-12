#include "ros/ros.h"
#include "turtlesim/Pose.h"

void doPose(const turtlesim::Pose::ConstPtr &pose){
    ROS_INFO("乌龟位姿信息：\n坐标(%.2f, %.2f)\n朝向(%.2f)\n线速度(%.2f)角速度(%.2f)",
    pose->x, pose->y, pose->theta, pose->linear_velocity, pose->angular_velocity);
}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "sub_pose");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 100, doPose);
    ros::spin();
    return 0;
}