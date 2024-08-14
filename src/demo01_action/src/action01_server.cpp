#include "ros/ros.h"
#include "actionlib/server/simple_action_server.h"
#include "demo01_action/AddIntsAction.h"

typedef actionlib::SimpleActionServer<demo01_action::AddIntsAction> Server;
void cb(const demo01_action::AddIntsGoalConstPtr &goal,Server* server){
    //获取目标值
    int num = goal->num;
    ROS_INFO("目标值:%d",num);
    //累加并响应连续反馈
    int result = 0;
    demo01_action::AddIntsFeedback feedback;//连续反馈
    ros::Rate rate(10);//通过频率设置休眠时间
    for (int i = 1; i <= num; i++)
    {
        result += i;
        //组织连续数据并发布
        feedback.progress_bar = i / (double)num;
        server->publishFeedback(feedback);
        rate.sleep();
    }
    //设置最终结果
    demo01_action::AddIntsResult r;
    r.result = result;
    server->setSucceeded(r);
    ROS_INFO("最终结果:%d",r.result);
}
int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "addInts_server");
    ros::NodeHandle nh;
    Server server(nh, "addInts", boost::bind(&cb, _1, &server), false);
    server.start();
    ROS_INFO("服务启动...");
    ros::spin();
    return 0;
}