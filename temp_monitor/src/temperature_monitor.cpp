	#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

#define THRESHOLD 28.0  

class TemperatureMonitor : public rclcpp::Node {
public:
    TemperatureMonitor() : Node("temperature_monitor") {
        subscription_ = this->create_subscription<std_msgs::msg::Float32>(
            "temperature_data", 10, std::bind(&TemperatureMonitor::temperature_callback, this, std::placeholders::_1));
    }

private:
    void temperature_callback(const std_msgs::msg::Float32::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Received temperature: %.2f °C", msg->data);
        if (msg->data > THRESHOLD) {
            RCLCPP_WARN(this->get_logger(), "WARNING! High temperature detected: %.2f °C", msg->data);
        }
    }

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TemperatureMonitor>());
    rclcpp::shutdown();
    return 0;
}
