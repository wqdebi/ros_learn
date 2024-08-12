#include "ros/ros.h"
#include "plumbing_head/hello.h"

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "hello_head");
    hello_ns::MyHello myhello;
    myhello.run();
    return 0;
}