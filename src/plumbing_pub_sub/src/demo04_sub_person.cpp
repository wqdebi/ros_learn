#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

/*
    发布方：发布人信息
    1.包含头文件
    2.初始化ROS节点
    3.创建节点句柄
    4.创建订阅者对象
    5.处理订阅数据
    6.spin()
*/
void doPerson(const plumbing_pub_sub::Person::ConstPtr & ptr){
    ROS_INFO("发布的消息: %s, %d, %.2f",ptr->name.c_str(), ptr->age, ptr->height);
}
int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "jiazhang");
    ros::NodeHandle nh;
    ros::Subscriber pub = nh.subscribe("liaotian", 10, doPerson);
    ros::spin();
    return 0;
}