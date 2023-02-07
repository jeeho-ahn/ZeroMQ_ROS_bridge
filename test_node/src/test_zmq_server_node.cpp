/*
* Sample zeroMQ ROS bridge
* This node is a sample ZeroMQ server that publishes received string message as a ROS std_msgs/String topic.
* created by Ahn, Jeeho
* 2023.02.06
*/

//ROS
#include <ros/ros.h>
#include <ros/package.h>
#include <std_msgs/String.h>
//std libraries
#include <iostream>
#include <vector>

#include <zmq.hpp>
#include <string>

//print in color
#include <color_print.h>

#ifdef _WIN32
#include<Windows.h>
#elif defined __unix__
#include <unistd.h>
#endif

void my_pub_func(std::string str_to_pub, ros::Publisher& p)
{
    std_msgs::String out_msg = std_msgs::String();
    out_msg.data = str_to_pub;
    p.publish(out_msg);
}

int main(int argc, char** argv)
{
    //prompt welcome message
    color::println("Test ZeroMQ ROS Bridge Node - Server Side", color::BLUE, color::BG_YELLOW);

    // ros initialization
    ros::init(argc, argv, "test_zmq_server_node");
    ros::NodeHandle nh;

    ros::Publisher my_publisher = nh.advertise<std_msgs::String>
        ("/my_pub_str",2);

    ros::Rate rate(5); //5 hz while loop
    ros::Duration(0.5).sleep(); //for debug attach

    //  Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    // define port number to access this zmq server
    socket.bind("tcp://*:7777");

    while(ros::ok()) //repeat until exit cmd is received
    {
        //ros communication update
        ros::spinOnce();

        zmq::message_t request;
        //wait for a message
        socket.recv(&request);
        //convert msg to std string
        std::string msg_in = std::string(static_cast<char*>(request.data()), request.size());
        //publish string
        my_pub_func(msg_in,my_publisher);
        //return response
        std::string out_str("thanks, AIR");
        zmq::message_t reply(out_str.size());
        memcpy((void*)reply.data(), out_str.c_str(), out_str.size());
        socket.send(reply);

        //sleep to meet update frequency
        rate.sleep();
    }

    return 0;
}