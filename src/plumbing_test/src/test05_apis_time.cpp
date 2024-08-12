#include"ros/ros.h"

void dosomething(const ros::TimerEvent& event){
    static int i = 0;
    ROS_INFO("i=%d", i);
    ++i;
}

int main(int argc, char *argv[]){
    ros::init(argc, argv, "hello_time");
    ros::NodeHandle nh;
    ros::Timer timer = nh.createTimer(ros::Duration(1), dosomething, false, false);
    timer.start();
    ros::spin();
    return 0;
}