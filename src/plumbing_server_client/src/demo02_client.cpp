#include"ros/ros.h"
#include "plumbing_server_client/AddInts.h"
    

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    if(argc != 3){
        ROS_INFO("参数过少");
        return 1;
    }
    ros::init(argc, argv, "daBao");
    ros::NodeHandle nh;
    ros::ServiceClient client =  nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    client.waitForExistence();
    bool flag = client.call(ai);
    if(flag){
        ROS_INFO("相应成功");
        ROS_INFO("结果: %d", ai.response.sum);
    }else{
        ROS_INFO("相应失败");
    }
    ros::spin();
    return 0; 
}