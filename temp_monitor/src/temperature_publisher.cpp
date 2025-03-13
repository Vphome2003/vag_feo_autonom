#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include <random>

class TemperaturePublisher : public rclcpp::Node {
public:
    TemperaturePublisher() : Node("temperature_publisher"), gen(rd()), dist(20.0, 30.0) {
        publisher_ = this->create_publisher<std_msgs::msg::Float32>("temperature_data", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&TemperaturePublisher::publish_temperature, this));
    }

private:
    void publish_temperature() {
        auto message = std_msgs::msg::Float32();
        message.data = dist(gen);
        RCLCPP_INFO(this->get_logger(), "Published temperature: %.2f °C", message.data);
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dist;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TemperaturePublisher>());
    rclcpp::shutdown();
    return 0;
}
