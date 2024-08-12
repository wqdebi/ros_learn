#include"ros/ros.h"

int main(int argc, char * argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "get_param_c");
    ros::NodeHandle nh;

    //1.param
    int radius = nh.param("radius", 0.5);
    ROS_INFO("radius=%d", radius);

    return 0;
}