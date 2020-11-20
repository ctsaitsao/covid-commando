import os 
from pathlib import Path
import cv2
import cv_bridge
from enum import Enum, auto


import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Pose
from state_machine.srv import SetState, SetStateResponse
from sensor_msgs.msg import (
    Image,
)
from std_srvs.srv import Empty,EmptyRequest,EmptyResponse

# path = os.path.dirname(os.path.realpath(__file__))+'/images/green_background.jpg'
path = str(Path(os.path.realpath(__file__)).parents[1])+'/images/green_background.jpg'
print(path)
img = cv2.imread(path)
print(img)
# msg = cv_bridge.CvBridge().cv2_to_imgmsg(img, encoding="bgr8")
