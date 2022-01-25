
#!/bin/sh

# Define workspace variable
path_catkin_ws="/home/workspace/HomeService/catkin_ws"

# Open the workspace, source and launch turtlebot_world.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch my_robot world.launch" &
sleep 5
# Open the workspace, source and launch gmapping_demo.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch my_robot gmapping.launch" &
sleep 10
# Open the workspace, source and launch keyboard_teleop.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch my_robot teleop.launch"

