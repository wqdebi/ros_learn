#include "ros/ros.h"

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "change_bgColor");
    ros::param::set("/turtlesim/background_r", 0);
    ros::param::set("/turtlesim/background_g", 0);
    ros::param::set("/turtlesim/background_b", 0);

    return 0;
}