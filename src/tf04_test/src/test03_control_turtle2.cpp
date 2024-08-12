#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "tfs_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    ros::Rate rate(1);

    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 100);

    while(ros::ok()){
        try{
            geometry_msgs::TransformStamped son1Toson2 = buffer.lookupTransform("turtle2", "turtle1", ros::Time(0));
            // ROS_INFO("turtle1相对于turtle2关系: 父:%s, 子:%s, 偏移量(%.2f,%.2f,%.2f)",
            //     son1Toson2.header.frame_id.c_str(),
            //     son1Toson2.child_frame_id.c_str(),
            //     son1Toson2.transform.translation.x,
            //     son1Toson2.transform.translation.y,
            //     son1Toson2.transform.translation.z);
            geometry_msgs::Twist twist;
            twist.linear.x = 0.5 * sqrt(pow(son1Toson2.transform.translation.x, 2) 
            + pow(son1Toson2.transform.translation.y, 2));
            twist.angular.z = 0.5 * atan2(son1Toson2.transform.translation.y, son1Toson2.transform.translation.x);
            pub.publish(twist);
        }catch(const std::exception& e){
            ROS_INFO("错误提示:%s", e.what());
        }
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}