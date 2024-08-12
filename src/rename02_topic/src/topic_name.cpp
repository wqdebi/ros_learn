#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char* argv[]){
    ros::init(argc, argv, "hello");
    ros::NodeHandle nh("~");

    ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter", 1000);

    while(ros::ok()){

    }

    return 0;
}