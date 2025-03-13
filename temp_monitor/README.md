--------------------------------------------
Hőmérséklet-szimulátor (ROS 2)
--------------------------------------------

Ez a projekt egy egyszerű ROS 2 alkalmazás, amely egy hőmérséklet-generátor és egy monitorozó csomópont segítségével figyeli a hőmérsékleti értékeket. Ha a hőmérséklet egy adott küszöbérték fölé emelkedik, egy figyelmeztetést küld a konzolra.

--------------------------------------------
Telepítés
--------------------------------------------

Navigálj a ROS 2 workspace-be:

cd ~/ros2_ws/src

Klónozd a repository-t:

git clone https://github.com/Felhasznalonev/temp_monitor.git

Lépj a workspace gyökerébe, majd buildeld a csomagot:

cd ~/ros2_ws
colcon build --packages-select temp_monitor
source install/setup.bash

--------------------------------------------
Futtatás
--------------------------------------------

Indítsd el a hőmérséklet-generátor node-ot:

ros2 run temp_monitor temperature_publisher

Indítsd el a monitorozó node-ot:

ros2 run temp_monitor temperature_subscriber

Opcionalisan indíthatod a launch file-t is:

ros2 launch temp_monitor temperature.launch.py

--------------------------------------------
Felépítés
--------------------------------------------

A rendszer két ROS 2 csomópontból (
node-ból) áll:

temperature_publisher: Generál egy véletlenszerű hőmérsékleti értéket 20-30 °C között, majd közreadja a /temperature topicon.

temperature_subscriber: Figyeli a /temperature topicot, és ha a hőmérséklet meghaladja a 25 °C-ot, kiír egy figyelmeztetést.