#include "Trajetoria_fixa.h"

Trajetoria_fixa::Trajetoria_fixa(string name, string ns, NodeOptions options) : Node(name, ns, options)
{
    QoS qos_profile(KeepLast(10));
    qos_profile.durability(DurabilityPolicy::TransientLocal); // Setando para BEST_EFFORT

    publisherVelocity = this->create_publisher<geometry_msgs::msg::Twist>("/offboard_velocity_cmd", qos_profile);
    publisherAmr = this->create_publisher<std_msgs::msg::Bool>("/arm_message", qos_profile);

    RCLCPP_INFO(this->get_logger(), "control has been started");

    this->moveDrone();
    RCLCPP_INFO(this->get_logger(), "control has been finished");      
}

Trajetoria_fixa::~Trajetoria_fixa()
{
    
}

void Trajetoria_fixa::moveDrone()
{
    auto msg = geometry_msgs::msg::Twist();
    auto arm = std_msgs::msg::Bool();

    arm.data=true;
    publisherAmr->publish(arm);
    sleep_for(20s);
    RCLCPP_INFO(this->get_logger(), "Decolouuu");

    msg.linear.x = 2;
    msg.linear.y = 0;
    msg.linear.z = 0;
    publisherVelocity->publish(msg);
    sleep_for(3s);

    msg.linear.x = 2;
    msg.linear.y = 2;
    msg.linear.z = 0;
    publisherVelocity->publish(msg);
    sleep_for(3s);

    msg.linear.x = 0;
    msg.linear.y = 2;
    msg.linear.z = 0;
    publisherVelocity->publish(msg);
    sleep_for(3s);

    msg.linear.x = 0;
    msg.linear.y = 0;
    msg.linear.z = 0;
    publisherVelocity->publish(msg);
    sleep_for(3s);


    arm.data=false;
    publisherAmr->publish(arm);
}

int main(int argc, char **argv)
{
    NodeOptions options;
    init(argc, argv);                                                                 // inicializado o ROS
    auto node = make_shared<Trajetoria_fixa>("trajetoria", "/px4_offboard", options); // criação do nó usando ponteiro compartilhado e o nomeando
    //spin(node);                                                                       // gira o nó (o mantem vivo até ctrl + c)
    shutdown();                                                                       // desliga o nó
    return 0;
}