# Motion Package 

## Overview 
The motion package handles all Baxter robot arm controls. It uses the Moveit package for motion planning.

## Nodes
- `mover`: Creates the services for robot arm movements. These services are called by the state machine node in the state machine package. Its services are:
   - `/go_to_joint_angle`: Called at startup and end of each cycle. Moves right arm to neutral position with thermometer pointing down, and streatches out left arm to block passage past robot.
   - `/go_to_pose`: Called after a face pose has been published, moves right arm to a temperature-taking pose.
   - `/go_to_pose_left`: Called after results are displayed, moves left arm out of the way to let a subejct with normal temperature pass.
  
## Launchfiles
- `mover.launch`: Launches mover node, moveit node, joint trajectory server, loads saved coordinate parameters, and optionally launches gazebo if using simulation.

## Usage 
To launch the motion package only: 
```
roslaunch motion motion.launch
```

Options: <br/>
- `gazebo:="true"` to launch Baxter gazebo model.


## Motion Planning Algorithm 
```
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
```

The motion planning methodology was developed to work around some of the issues that were faced during development. The inverse kinematics service does not always succeed in returning a path to the target pose. To mitigate this problem, pre-determined poses were added. These poses were good positions for the arm to start in when planning towards a target pose in different areas of the workspace (e.g. left or right of the robot) and were found through trial and error. In addition, a cylindrical collision object was also added around the Baxter’s head to reduce the likelihood of the arms colliding with the screen.

A cartesian trajectory to the target pose is first computed using MoveIt!’s functions, which return a percentage of the trajectory that the robot can successfully plan and execute. If this value is above 90%, the first plan is executed. Otherwise, the arm moves towards one of the two saved poses, depending on where the subject is standing relative to the robot. After reaching the saved pose, another cartesian trajectory is planned and executed, regardless of its success percentage. If the percentage is below 50%, the state machine will send go back to the "searching for face" state, and the subject should adjust their position for the robot to try again. 

The two thresholds for the fraction were determined during testing to ensure both sufficient accuracy and efficiency.

Once the arm reaches its target pose, the robot is ready for temperature-taking.
