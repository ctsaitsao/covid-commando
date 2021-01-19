# State Machine Node

## Overview
The state machine is the main node which is used to launch the enitre program.

## Diagram
The figure below shows all states and the actions to transition between states. 
![state machine img](../images/state_machine_web.png)

## Nodes
`state_machine_node`: Uses services provided by other nodes to check and update robot state.

## Launchfiles
`state_machine.launch`: Launches the state_machine_node. 

## Usage
To launch the whole project:
```
roslaunch state_machine state_machine.launch
```
