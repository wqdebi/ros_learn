#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"
#include <string>
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
std::string turtle_name;

void doPose(const turtlesim::Pose::ConstPtr& pose){
    static tf2_ros::TransformBroadcaster pub;
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.child_frame_id = turtle_name;
    ts.header.stamp = ros::Time::now();
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    pub.sendTransform(ts);
}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    if(argc != 4){
        ROS_ERROR("%d,%s,%s,%s",argc,argv[1],argv[2],argv[3]);
        return 1;
    }else{
        turtle_name = argv[1];
    }
    ros::init(argc, argv, "dynamic1");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe(turtle_name + "/pose", 100, doPose);
    ros::spin();
    return 0;
}