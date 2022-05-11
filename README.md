# RobotND - Project5: Home Service Robot

Project 5 of Udacity Robotics Software Engineer Nanodegree

![Overview](/home.gif)  

## Overview  
In this project, everything learned in the Nanodegree Program will be gathered and used to build a Home Service Robot in ROS.
Steps:
### Mapping  
Create a `test_slam.sh` script file and launch it to manually test SLAM.  
A functional map of the environment should be created which would be used for localization and navigation tasks.  
### Localization and Navigation  
Create a `test_navigation.sh` script file to launch it for manual navigation test.  
Your robot should be able to navigate in the environment after a 2D Nav Goal command is issued.  
Create a `pick_objects.sh` file that will send multiple goals for the robot to reach.  
The robot travels to the desired pickup zone, displays a message that it reached its destination, waits 5 seconds, travels to the desired drop off zone, and displays a message that it reached the drop off zone.  
### Home Service Functions  
Create a `add_marker.sh` file that will publish a marker to rviz.  
The marker should initially be published at the pickup zone. After 5 seconds it should be hidden. Then after another 5 seconds it should appear at the drop off zone.
The student should write a home_service.sh file that will run all the nodes in this project.  
The student's home service robot should be simulated as follow:  
* Initially show the marker at the pickup zone.
* Hide the marker once your robot reach the pickup zone.
* Wait 5 seconds to simulate a pickup.
* Show the marker at the drop off zone once your robot reaches it.


## Prerequisites/Dependencies  
* Gazebo >= 7.0  
* ROS Kinetic  
* ROS navigation package  
```
sudo apt-get install ros-kinetic-navigation
```
* ROS map_server package  
```
sudo apt-get install ros-kinetic-map-server
```
* ROS move_base package  
```
sudo apt-get install ros-kinetic-move-base
```
* ROS amcl package  
```
sudo apt-get install ros-kinetic-amcl
```

## Setup Instructions
1. Meet the `Prerequisites/Dependencies`  
2. Open Ubuntu Bash and clone the project repository  
3. On the command line and execute  
```bash
sudo apt-get update && sudo apt-get upgrade -y
```
4. Build and run your code.  

## Project Description  
Directory Structure  
```
.Home-Sevice-Robot                                        # Home Service Robot Project
/home/workspace/HomeService
├── catkin_ws
│   ├── build
│   │   ├── add_markers
│   │   │   ├── catkin_generated
│   │   │   ├── CMakeFiles
│   │   │   ├── cmake_install.cmake
│   │   │   ├── CTestTestfile.cmake
│   │   │   └── Makefile
│   │   ├── atomic_configure
│   │   │   ├── env.sh
│   │   │   ├── local_setup.bash
│   │   │   ├── local_setup.sh
│   │   │   ├── local_setup.zsh
│   │   │   ├── setup.bash
│   │   │   ├── setup.sh
│   │   │   ├── _setup_util.py
│   │   │   └── setup.zsh
│   │   ├── catkin
│   │   │   └── catkin_generated
│   │   ├── catkin_generated
│   │   │   ├── env_cached.sh
│   │   │   ├── generate_cached_setup.py
│   │   │   ├── installspace
│   │   │   ├── metapackages
│   │   │   ├── order_packages.cmake
│   │   │   ├── order_packages.py
│   │   │   ├── setup_cached.sh
│   │   │   └── stamps
│   │   ├── CATKIN_IGNORE
│   │   ├── catkin_make.cache
│   │   ├── CMakeCache.txt
│   │   ├── CMakeFiles
│   │   │   ├── 3.5.1
│   │   │   ├── clean_test_results.dir
│   │   │   ├── cmake.check_cache
│   │   │   ├── CMakeDirectoryInformation.cmake
│   │   │   ├── CMakeError.log
│   │   │   ├── CMakeOutput.log
│   │   │   ├── CMakeRuleHashes.txt
│   │   │   ├── CMakeTmp
│   │   │   ├── download_extra_data.dir
│   │   │   ├── doxygen.dir
│   │   │   ├── feature_tests.bin
│   │   │   ├── feature_tests.c
│   │   │   ├── feature_tests.cxx
│   │   │   ├── Makefile2
│   │   │   ├── Makefile.cmake
│   │   │   ├── progress.marks
│   │   │   ├── run_tests.dir
│   │   │   ├── TargetDirectories.txt
│   │   │   └── tests.dir
│   │   ├── cmake_install.cmake
│   │   ├── CTestConfiguration.ini
│   │   ├── CTestCustom.cmake
│   │   ├── CTestTestfile.cmake
│   │   ├── gtest
│   │   │   ├── CMakeFiles
│   │   │   ├── cmake_install.cmake
│   │   │   ├── CTestTestfile.cmake
│   │   │   ├── gtest
│   │   │   └── Makefile
│   │   ├── Makefile
│   │   ├── my_robot
│   │   │   ├── catkin_generated
│   │   │   ├── CMakeFiles
│   │   │   ├── cmake_install.cmake
│   │   │   ├── CTestTestfile.cmake
│   │   │   └── Makefile
│   │   ├── pick_objects
│   │   │   ├── catkin_generated
│   │   │   ├── CMakeFiles
│   │   │   ├── cmake_install.cmake
│   │   │   ├── CTestTestfile.cmake
│   │   │   └── Makefile
│   │   ├── slam_gmapping
│   │   │   ├── gmapping
│   │   │   └── slam_gmapping
│   │   ├── teleop_twist_keyboard
│   │   │   ├── catkin_generated
│   │   │   ├── CMakeFiles
│   │   │   ├── cmake_install.cmake
│   │   │   ├── CTestTestfile.cmake
│   │   │   └── Makefile
│   │   ├── test_results
│   │   ├── turtlebot
│   │   │   ├── turtlebot
│   │   │   ├── turtlebot_bringup
│   │   │   ├── turtlebot_capabilities
│   │   │   ├── turtlebot_description
│   │   │   └── turtlebot_teleop
│   │   ├── turtlebot_interactions
│   │   │   ├── turtlebot_dashboard
│   │   │   ├── turtlebot_interactions
│   │   │   ├── turtlebot_interactive_markers
│   │   │   └── turtlebot_rviz_launchers
│   │   └── turtlebot_simulator
│   │       ├── turtlebot_gazebo
│   │       ├── turtlebot_simulator
│   │       ├── turtlebot_stage
│   │       └── turtlebot_stdr
│   ├── devel
│   │   ├── cmake.lock
│   │   ├── env.sh
│   │   ├── etc
│   │   │   └── catkin
│   │   ├── lib
│   │   │   ├── add_markers
│   │   │   ├── gmapping
│   │   │   ├── libslam_gmapping_nodelet.so
│   │   │   ├── pick_objects
│   │   │   ├── pkgconfig
│   │   │   ├── turtlebot_description
│   │   │   ├── turtlebot_interactive_markers
│   │   │   └── turtlebot_teleop
│   │   ├── local_setup.bash
│   │   ├── local_setup.sh
│   │   ├── local_setup.zsh
│   │   ├── setup.bash
│   │   ├── setup.sh
│   │   ├── _setup_util.py
│   │   ├── setup.zsh
│   │   └── share
│   │       ├── add_markers
│   │       ├── gmapping
│   │       ├── my_robot
│   │       ├── pick_objects
│   │       ├── teleop_twist_keyboard
│   │       ├── turtlebot_bringup
│   │       ├── turtlebot_capabilities
│   │       ├── turtlebot_dashboard
│   │       ├── turtlebot_description
│   │       ├── turtlebot_gazebo
│   │       ├── turtlebot_interactive_markers
│   │       ├── turtlebot_rviz_launchers
│   │       ├── turtlebot_stage
│   │       ├── turtlebot_stdr
│   │       └── turtlebot_teleop
│   └── src
│       ├── add_markers
│       │   ├── CMakeLists.txt
│       │   ├── launch
│       │   ├── package.xml
│       │   └── src
│       ├── CMakeLists.txt -> /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
│       ├── map
│       │   ├── map.pgm
│       │   └── map.yaml
│       ├── my_robot
│       │   ├── CMakeLists.txt
│       │   ├── config
│       │   ├── launch
│       │   ├── maps
│       │   ├── meshes
│       │   ├── package.xml
│       │   ├── urdf
│       │   └── worlds
│       ├── pick_objects
│       │   ├── CMakeLists.txt
│       │   ├── package.xml
│       │   └── src
│       ├── rvizConfig
│       │   └── home_service_rvizConfig.rviz
│       ├── scripts
│       │   ├── add_marker.sh
│       │   ├── home_service.sh
│       │   ├── launch.sh
│       │   ├── pick_objects.sh
│       │   ├── test_navigation.sh
│       │   └── test_slam.sh
│       ├── slam_gmapping
│       │   ├── gmapping
│       │   ├── README.md
│       │   └── slam_gmapping
│       ├── teleop_twist_keyboard
│       │   ├── CHANGELOG.rst
│       │   ├── CMakeLists.txt
│       │   ├── package.xml
│       │   ├── README.md
│       │   └── teleop_twist_keyboard.py
│       ├── turtlebot
│       │   ├── LICENSE
│       │   ├── README.md
│       │   ├── setup_create.sh
│       │   ├── setup_kobuki.sh
│       │   ├── turtlebot
│       │   ├── turtlebot_bringup
│       │   ├── turtlebot_capabilities
│       │   ├── turtlebot_capabilities.rosinstall
│       │   ├── turtlebot_description
│       │   ├── turtlebot.rosinstall
│       │   └── turtlebot_teleop
│       ├── turtlebot_interactions
│       │   ├── README.md
│       │   ├── turtlebot_dashboard
│       │   ├── turtlebot_interactions
│       │   ├── turtlebot_interactive_markers
│       │   └── turtlebot_rviz_launchers
│       └── turtlebot_simulator
│           ├── README.md
│           ├── turtlebot_gazebo
│           ├── turtlebot_simulator
│           ├── turtlebot_simulator.rosinstall
│           ├── turtlebot_stage
│           └── turtlebot_stdr
├── home.gif
└── README.md
```

## Run the project  
* Clone this repository
```
git clone https://github.com/margrammas/RobotND_HomeService_Project5.git
```
* Navigate to the `src` folder and clone the necessary repositories if needed (you might be able to skip this step if rep is cloned properly) 
```
cd /home/workspace/HomeService/catkin_ws/src  
git clone https://github.com/ros-perception/slam_gmapping.git  
git clone https://github.com/turtlebot/turtlebot.git  
git clone https://github.com/turtlebot/turtlebot_interactions.git  
git clone https://github.com/turtlebot/turtlebot_simulator.git  
```
* Open the repository, make and source  
```
cd /home/workspace/HomeService/catkin_ws
catkin_make
source devel/setup.bash
```
* Launch the home service robot
```
./src/scripts/home_service.sh
```
* Done. 

Enjoy!

## Tips  
1. It's recommended to update and upgrade your environment before running the code.  
```bash
sudo apt-get update && sudo apt-get upgrade -y
```
