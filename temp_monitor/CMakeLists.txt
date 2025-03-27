cmake_minimum_required(VERSION 3.5)
project(temp_monitor)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(temperature_publisher src/temperature_publisher.cpp)
ament_target_dependencies(temperature_publisher rclcpp std_msgs)

add_executable(temperature_monitor src/temperature_monitor.cpp)
ament_target_dependencies(temperature_monitor rclcpp std_msgs)

install(TARGETS
  temperature_publisher
  temperature_monitor
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

ament_package()
