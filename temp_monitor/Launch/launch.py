from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='temp_monitor',
            executable='temperature_publisher',
            name='temperature_publisher',
            output='screen'
        ),
        Node(
            package='temp_monitor',
            executable='temperature_monitor',
            name='temperature_monitor',
            output='screen'
        ),
    ])
