#include "Trajetoria_fixa.h"

Trajetoria_fixa::Trajetoria_fixa(string name) : Node(name)
{
    QoS qos_profile(KeepLast(10));
    qos_profile.durability(DurabilityPolicy::TransientLocal); // Setando para BEST_EFFORT

    publisher = this->create_publisher<geometry_msgs::msg::Twist>("offboard_velocity_cmd", qos_profile);
    this->moveDrone();
    RCLCPP_INFO(this->get_logger(), "control has been started");
}

Trajetoria_fixa::~Trajetoria_fixa()
{
}

void Trajetoria_fixa::moveDrone()
{
    auto msg = geometry_msgs::msg::Twist();

    msg.linear.x = 2;
    msg.linear.y = 0;
    msg.linear.z = 0;
    publisher->publish(msg);
    sleep_for(3s);

    msg.linear.x = 0;
    msg.linear.y = 2;
    msg.linear.z = 0;
    publisher->publish(msg);
    sleep_for(3s);

    msg.linear.x = -2;
    msg.linear.y = 0;
    msg.linear.z = 0;
    publisher->publish(msg);
    sleep_for(3s);

    msg.linear.x = 0;
    msg.linear.y = -2;
    msg.linear.z = 0;
    publisher->publish(msg);
    sleep_for(3s);

    msg.linear.x = 0;
    msg.linear.y = 0;
    msg.linear.z = 0;
    publisher->publish(msg);
}

int main(int argc, char **argv)
{
    init(argc, argv);                                       // inicializado o ROS
    auto node = make_shared<Trajetoria_fixa>("trajetoria"); // criação do nó usando ponteiro compartilhado e o nomeando
    spin(node);                                             // gira o nó (o mantem vivo até ctrl + c)
    shutdown();                                             // desliga o nó
    return 0;
}