#include"ros/ros.h"
#include "plumbing_server_client/AddInts.h"

bool doNums(plumbing_server_client::AddInts::Request &request,
                plumbing_server_client::AddInts::Response & response){

    int num1 = request.num1;
    int num2 = request.num2;
    ROS_INFO("受到的请求数据,num1=%d num2=%d", num1, num2);
    int sum = num1 + num2;
    response.sum = sum;
    ROS_INFO("求和结果,sum=%d", sum);
    return true;
}

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "heiShui");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("addInts", doNums);

    ros::spin();
    return 0; 
}