//sensores_distancia
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include <cstdlib>
#include <ctime>

class SensoresDistancia : public rclcpp::Node
{
public:
    SensoresDistancia() : Node("sensores_distancia_node")
    {
        // Criar publicadores para os sensores de distância
        sensor1_pub_ = this->create_publisher<std_msgs::msg::Float32>("/sensor_distancia_1", 10);
        sensor2_pub_ = this->create_publisher<std_msgs::msg::Float32>("/sensor_distancia_2", 10);

        // Criar o timer para publicar dados a cada 50 ms
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1), std::bind(&SensoresDistancia::timer_callback, this));
    }

private:
    void timer_callback()
    {
        // gera valores aleatórios para a distância (0 a 5 metros)
        float distancia1 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 5.0f;
        float distancia2 = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 5.0f;

        // publica os dados nos tópicos
        auto msg1 = std_msgs::msg::Float32();
        msg1.data = distancia1;
        sensor1_pub_->publish(msg1);

        auto msg2 = std_msgs::msg::Float32();
        msg2.data = distancia2;
        sensor2_pub_->publish(msg2);

        // log de informações
        RCLCPP_INFO(this->get_logger(), "Distância Sensor 1: %.2f m, Sensor 2: %.2f m", distancia1, distancia2);
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr sensor1_pub_;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr sensor2_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    srand(time(0)); // Inicializa o gerador de números aleatórios

    rclcpp::spin(std::make_shared<SensoresDistancia>());
    rclcpp::shutdown();
    return 0;
}
