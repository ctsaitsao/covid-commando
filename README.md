# Covid Commando Project 
### Authors: Anuj Karnik, Christopher Tsai, Di Wu, Tomasz Trzpit 


## Overview 
The Covid Commando is a Baxter robot that takes a person's temperature and indicates if the individual has normal or high temperature. We showcased its use by having it screen individuals that wish to enter the Center of Robotics and Biosystems at Northwestern, where the Baxter robot resides. The robot accomplishes the following tasks: 1) detects the location of a person's forehead, 2) moves the IR thermometer to in front that location, 3) takes the temperature, 4) displays the temperature and corresponding message on screen, 5) blocks or allows the person to pass, and 6) finally returns to the first state. 

```Shell
├── CMakeLists.txt
├── hardware_io
│   └── thermometer_controller.ino
├── motion
│   ├── CMakeLists.txt
│   ├── config
│   │   └── coordinates.yaml
│   ├── launch
│   │   └── mover.launch
│   ├── nodes
│   │   └── mover
│   ├── package.xml
│   └── srv
│       ├── GetPose.srv
│       └── GoToPose.srv
├── README.md
├── state_machine
│   ├── CMakeLists.txt
│   ├── images
│   │   ├── face_found.png
│   │   ├── move_to_face.png
│   │   ├── search_for_face.png
│   │   ├── take_temperature.png
│   │   ├── temp_high.png
│   │   ├── temp_normal.png
│   │   └── temp.png
│   ├── launch
│   │   └── state_machine.launch
│   ├── nodes
│   │   └── state_machine_node
│   ├── package.xml
│   ├── README.md
│   ├── src
│   │   └── state_machine
│   │       ├── displays.py
│   │       └── __init__.py
│   └── srv
│       └── SetState.srv
└── vision
    ├── CMakeLists.txt
    ├── config
    │   ├── face_detection.rviz
    │   └── thermometer_calibration.yaml
    ├── launch
    │   ├── face_detection.launch
    │   └── temperature_detection.launch
    ├── nodes
    │   ├── face_detection
    │   ├── read_digit
    │   └── read_temperature
    ├── package.xml
    └── README.md 
```

## System Architecture 

### Facial Detection and Temperature Reading
[Vision package](vision/README.md)

### Motion Planning 
[Motion package](motion/README.md)

### State Machine 
[State machine package](state_machine/README.md)

## Startup Guide 
1. Create a workspace <br>
   `mkdir -p ws/src`
2. Clone this repo into the src folder
3. `catkin make` in the ws folder
4. `source devel/setup.bash` in the ws folder
5. Connect to Baxter robot 
6. `roslaunch state_machine state_machine.launch` 

## Nodes and Launchfiles 





## Videos 
- Final demo: https://www.youtube.com/watch?v=Jk9b8oqRLSs&t=52s
- Demos of other stages of the project can be found in the Covid Commando YouTube channel: \
https://www.youtube.com/channel/UCiMYOwYpeRzvlzgUHT3ue5A
