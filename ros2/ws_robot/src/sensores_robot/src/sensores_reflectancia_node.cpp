//sensores_reflectancia
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"
#include <cstdlib>
#include <ctime>

class SensoresReflectancia : public rclcpp::Node
{
public:
    SensoresReflectancia() : Node("sensores_reflectancia_node")
    {
        // criando publicadores para os sensores de reflectancia
        sensor1_pub_ = this->create_publisher<std_msgs::msg::Bool>("/sensor_reflectancia_1", 10);
        sensor2_pub_ = this->create_publisher<std_msgs::msg::Bool>("/sensor_reflectancia_2", 10);

        // criando o timer para publicar dados a cada 0.05 segundo
        timer_ = this->create_wall_timer(
            // para funcionar em millisegundos std::chrono::milliseconds(50)
            std::chrono::seconds(1), std::bind(&SensoresReflectancia::timer_callback, this));
    }

private:
    void timer_callback()
    {
        // Gera valores aleatórios (True ou False) para simular a detecção de linha
        bool linha1 = rand() % 2 == 0;
        bool linha2 = rand() % 2 == 0;

        // Publica os dados nos tópicos
        auto msg1 = std_msgs::msg::Bool();
        msg1.data = linha1;
        sensor1_pub_->publish(msg1);

        auto msg2 = std_msgs::msg::Bool();
        msg2.data = linha2;
        sensor2_pub_->publish(msg2);

        // Log de informações
        RCLCPP_INFO(this->get_logger(), "Linha Sensor 1: %s, Linha Sensor 2: %s", linha1 ? "True" : "False", linha2 ? "True" : "False");
    }

    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr sensor1_pub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr sensor2_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    srand(time(0)); // Inicializa o gerador de números aleatórios

    rclcpp::spin(std::make_shared<SensoresReflectancia>());
    rclcpp::shutdown();
    return 0;
}
