
#!/bin/sh

# Define workspace variable
path_catkin_ws="/home/workspace/HomeService/catkin_ws"

# Open the workspace, source and launch turtlebot_world.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch my_robot world.launch" &
sleep 5
# Open the workspace, source and launch amcl_demo.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch my_robot amcl.launch" &
sleep 5
# Open the workspace, source and launch view_navigation.launch
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && roslaunch add_markers view_home_service_navigation.launch rviz_path:=${path_catkin_ws}/src/rvizConfig/home_service_rvizConfig.rviz" &
sleep 10
# Open the workspace, source and launch add_markers add_markers
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun add_markers add_markers" &

# Open the workspace, source and launch pick_objects pick_objects
xterm -e "cd ${path_catkin_ws} && source devel/setup.bash && rosrun pick_objects pick_objects" 

