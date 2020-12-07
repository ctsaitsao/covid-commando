# Vision Package 

## Overview 
The vision package handles all Baxter vision tasks, which include facial detection, pose estimation, and temperature reading.

## Nodes
- `face_detection`: Uses RealSense RGB-D lenses' data to detect a person's face and, once the person stands still, estimate their forehead's 3D pose in space.
- `read_temperature`: Uses an image from Baxter hand camera feed to identify whether the IR thermometer has shown a green (safe temperature) result or red (unsafe temperature) result on the LED screen
- `read_digit`: Reads an image frame from a ROS image_raw message, allows the user to highlight a region of interest (capture window), then attempts to read a 7-segment LED display using image segmentation.
  
## Launchfiles
- `face_detection.launch`: Launches `face_detection` node, `rs_camera.launch` (ROS's interface with the RealSense), and RViz.
- `temperature_detection.launch`: Launches `read_temperature` and `read_digit` nodes from this package as well as `camera_control`, a Baxter node that is used to configure the right arm camera.

## Usage for motion package only
To launch: <br/>
```Shell
roslaunch vision face_detection.launch
roslaunch vision temperature_detection.launch
```


More edits soon...
