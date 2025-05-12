#include "Trajetoria_fixa.h"

Trajetoria_fixa::Trajetoria_fixa(string name, string ns, NodeOptions options) : Node(name, ns, options)
{
    QoS qos_profile(KeepLast(10));
    qos_profile.reliability(ReliabilityPolicy::Reliable);
    qos_profile.durability(DurabilityPolicy::TransientLocal);

    subscription = this->create_subscription<std_msgs::msg::Bool>("/decolou", 10, bind(&Trajetoria_fixa::dronePronto_callback, this, _1));

    publisherVelocity = this->create_publisher<geometry_msgs::msg::Twist>("/offboard_velocity_cmd", qos_profile);
    publisherAmr = this->create_publisher<std_msgs::msg::Bool>("/arm_message", qos_profile);

    this->decolarDrone();

    RCLCPP_INFO(this->get_logger(), "control has been started");
}

Trajetoria_fixa::~Trajetoria_fixa()
{
}

void Trajetoria_fixa::dronePronto_callback(const std_msgs::msg::Bool::SharedPtr msg)
{
    if (msg->data == true)
    {
        RCLCPP_INFO(this->get_logger(), "Drone decolou e está estável");
        sleep_for(3s);
        this->moveDrone();
    }
}

void Trajetoria_fixa::decolarDrone()
{
    auto arm = std_msgs::msg::Bool();
    arm.data = true;
    publisherAmr->publish(arm);
}

void Trajetoria_fixa::moveDrone()
{
    auto msg = geometry_msgs::msg::Twist();

    msg.linear.z = 20;
    publisherVelocity->publish(msg);
    RCLCPP_INFO(this->get_logger(), "(0,0,20)");
    sleep_for(10s);

    msg.linear.x = 100;
    msg.linear.y = 0;
    publisherVelocity->publish(msg);
    RCLCPP_INFO(this->get_logger(), "(100,0,20)");
    sleep_for(10s);

    msg.linear.x = 100;
    msg.linear.y = 100;
    publisherVelocity->publish(msg);
    RCLCPP_INFO(this->get_logger(), "(100,100,20)");
    sleep_for(10s);

    msg.linear.x = 0;
    msg.linear.y = 100;
    publisherVelocity->publish(msg);
    RCLCPP_INFO(this->get_logger(), "(0,100,20)");
    sleep_for(10s);

    msg.linear.x = 0;
    msg.linear.y = 0;
    publisherVelocity->publish(msg);
    RCLCPP_INFO(this->get_logger(), "(0,0,20)");
    sleep_for(10s);
}

int main(int argc, char **argv)
{
    NodeOptions options;
    init(argc, argv);                                                                 // inicializado o ROS
    auto node = make_shared<Trajetoria_fixa>("trajetoria", "/px4_offboard", options); // criação do nó usando ponteiro compartilhado e o nomeando
    spin(node);                                                                       // gira o nó (o mantem vivo até ctrl + c)
    shutdown();                                                                       // desliga o nó
    return 0;
}


// Consegui colocar no nameespace
// delay apos comando de posição


