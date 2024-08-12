#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "tfs_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    ros::Rate rate(1);

    //座标点
    geometry_msgs::PointStamped psAtSon1;
    psAtSon1.header.stamp = ros::Time::now();
    psAtSon1.header.frame_id = "son1";
    psAtSon1.point.x = 1.0;
    psAtSon1.point.y = 2.0;
    psAtSon1.point.z = 3.0;

    while(ros::ok()){
        try{
            geometry_msgs::TransformStamped son1Toson2 = buffer.lookupTransform("son3", "son1", ros::Time(0));
            ROS_INFO("son1相对于son3关系: 父:%s, 子:%s, 偏移量(%.2f,%.2f,%.2f)",
                son1Toson2.header.frame_id.c_str(),
                son1Toson2.child_frame_id.c_str(),
                son1Toson2.transform.translation.x,
                son1Toson2.transform.translation.y,
                son1Toson2.transform.translation.z);

            geometry_msgs::PointStamped psAtSon2  = buffer.transform(psAtSon1, "son2");
            ROS_INFO("座标点在son3中的值(%.2f, %.2f, %.2f)",
                psAtSon2.point.x, psAtSon2.point.y, psAtSon2.point.z);
        }catch(const std::exception& e){
            ROS_INFO("错误提示:%s", e.what());
        }
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}