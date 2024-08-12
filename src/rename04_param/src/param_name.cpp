#include"ros/ros.h"

int main(int argc, char *argv[]){
    ros::init(argc, argv, "test_param");
    ros::NodeHandle nh;

    ros::param::set("/radiusA", 100);
    ros::param::set("radiusB", 100);
    ros::param::set("~radiusC", 100);

    return 0;
}