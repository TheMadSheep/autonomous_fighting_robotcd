#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"

class ProcessNode : public rclcpp::Node
{
public:
    ProcessNode() : Node("process_node")
    {
        // Criando os assinantes para os sensores de distâncias e reflectância
        sensor_reflectancia_1_sub_ = this->create_subscription<std_msgs::msg::Bool>(
            "/sensor_reflectancia_1", 10, std::bind(&ProcessNode::reflectancia_callback, this, std::placeholders::_1));

        sensor_reflectancia_2_sub_ = this->create_subscription<std_msgs::msg::Bool>(
            "/sensor_reflectancia_2", 10, std::bind(&ProcessNode::reflectancia_callback, this, std::placeholders::_1));

        sensor_distancia_1_sub_ = this->create_subscription<std_msgs::msg::Bool>(
            "/sensor_distancia_1", 10, std::bind(&ProcessNode::distancia_callback, this, std::placeholders::_1));

        sensor_distancia_2_sub_ = this->create_subscription<std_msgs::msg::Bool>(
            "/sensor_distancia_2", 10, std::bind(&ProcessNode::distancia_callback, this, std::placeholders::_1));
    }

private:
    void reflectancia_callback(const std_msgs::msg::Bool::SharedPtr msg)
    {
        // Processamento dos dados de reflectância (decisão com base em linha detectada ou não)
        RCLCPP_INFO(this->get_logger(), "Sensor de Reflectância recebeu: %s", msg->data ? "True" : "False");
        // Aqui você pode adicionar a lógica para tomar decisões com base nos dados
    }

    void distancia_callback(const std_msgs::msg::Bool::SharedPtr msg)
    {
        // Processamento dos dados de distância (decisão com base na proximidade)
        RCLCPP_INFO(this->get_logger(), "Sensor de Distância recebeu: %s", msg->data ? "True" : "False");
        // Aqui você pode adicionar a lógica para tomar decisões com base nos dados
    }

    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr sensor_reflectancia_1_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr sensor_reflectancia_2_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr sensor_distancia_1_sub_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr sensor_distancia_2_sub_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ProcessNode>());
    rclcpp::shutdown();
    return 0;
}
