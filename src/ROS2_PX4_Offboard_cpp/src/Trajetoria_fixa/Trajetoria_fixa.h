#ifndef TRAJETORIA_H
#define TRAJETORIA_H

#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/bool.hpp"

using namespace std;
using namespace rclcpp;

using placeholders::_1;

class Trajetoria_fixa : public Node
{
private:
    Publisher<geometry_msgs::msg::Twist>::SharedPtr publisherVelocity;
    Publisher<std_msgs::msg::Bool>::SharedPtr publisherAmr;
    TimerBase::SharedPtr timer;
    void moveDrone();
   
public:
    Trajetoria_fixa(string name, string ns, NodeOptions options);
    ~Trajetoria_fixa();
};

#endif