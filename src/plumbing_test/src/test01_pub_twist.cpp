#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "my_control");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Rate rate(10);
    geometry_msgs::Twist twist;
    twist.linear.x = 1;
    twist.linear.y = 0;
    twist.linear.z = 0;
    twist.angular.x = 0;
    twist.angular.y = 0;
    twist.angular.z = 0.5;
    while(ros::ok){
        pub.publish(twist);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}