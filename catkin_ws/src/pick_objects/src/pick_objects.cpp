#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

//remember in map frame coordinates are different

//in odom frame
//float start[3] = {1.0, 1.0, 1.0};  
//float goal[3] = {5.0, 1.0, 1.0};


// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "odom";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 1.0;
  goal.target_pose.pose.position.y = 1.0;
  goal.target_pose.pose.orientation.w = 1.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending pick-up");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
     
     ROS_INFO("Reached Pick-up!");
     ros::Duration(5.0).sleep();
     //Go to drop off point
     // Define a position and orientation for the robot to reach
     goal.target_pose.pose.position.x = 5.0;
     goal.target_pose.pose.position.y = 1.0;
     goal.target_pose.pose.orientation.w = 1.0;
     // Send the goal position and orientation for the robot to reach
     ROS_INFO("Sending drop-off");
     ac.sendGoal(goal);
     // Wait an infinite time for the results
     ac.waitForResult();

     if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
        ROS_INFO("Reached Drop-off!");
        ros::Duration(5.0).sleep();
     }
     else{
        ROS_INFO("Robot failed to reach Dropoff zone for some reason");
     }
   }

  else{
     ROS_INFO("Robot failed to reach Pickup zone for some reason");
  }

  return 0;
}
