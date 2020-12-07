# Motion Package 

## Overview 
The motion package handles all Baxter robot arm controls. It uses the Moveit package for motion planning.

## Node - mover 
The mover node creates the services for robot arm movements. These services are called by the state machine node in the state machine package.

Main Services:<br/>
- "/go_to_joint_angle"<br/>
      - Called at startup and end of each cycle. Moves right arm to neutral position with thermometer pointing down, and streatches out left arm to block passage past robot.<br/>
- "/go_to_pose"<br/>
      - Called after a face pose has been published, moves right arm to a temperature-taking pose.<br/>
- "/go_to_pose_left"<br/>
      - <tab/> Called after results are displayed, moves left arm out of the way to let a subejct with normal temperature pass.
  
## Launchfile - mover.launch 
Launches mover node, moveit node, joint trajectory server, loads saved coordinate parameters, and optionally launches gazebo if using simulation.

## Usage for motion package only
To launch: <br/>
`roslaunch motion motion.launch` 

Options: <br/>
`gazebo:="true"` to launch Baxter gazebo model.


## Motion Planning Algorithm 
1. Compute cartesian trajectory to target pose
2. If fraction of trajectory followed > 0.90
3.   Execute trajectory 
4.   Return fraction
5. Else 
6.   Move arm to either left or right saved poses, 
     depending on horizontal position of target 
7.   Compute cartesian trajectory again
8.   Execute this trajectory regardless 
9.   Return fraction

Our motion planning method was developed to workaround some issues we were facing. The inverse kinematics service does not always succeed in return a path to the target pose. To mitigate this problem, we determined poses that were good positions for the arm to start planning towards a target pose. These poses were found through trial and error, and we saved the joint positions of these poses, so that we can directly go to these poses when we need. In addition, we also added a cylindrical collision object around the Baxter’s head to reduce the likelihood of the arms colliding with the screen.

We first compute a cartesian trajectory to the target pose, using moveit’s function, which returns a fraction of how of the trajectory the robot can follow. If this fraction is above 90% we execute this first plan. Otherwise, the arm moves towards one of the two saved poses, depending on where the subject is standing relative to the robot. After reaching the saved pose, we plan another cartesian trajectory and execute this trajectory regardless. If the fraction is below 50%, the state machine will send go back to the searching for face state, and the subject should adjust their position for the robot to try again. 

The two thresholds for the fraction were determine during our testing to ensure both sufficient accuracy and efficiency.

Once the arm has reached its target pose, we are now ready for temperature taking.

