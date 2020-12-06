"""
    Python function for selecting images, and creating images to display to the Baxter screen 
"""

import cv2

def get_image(images_dir,state):
    """
        Gets a image for the screen 

        Args: 
            images_dir: folders that contains images 
            state
            
        Returns:
            img
    """
    path = images_dir + state + '.png'
    img = cv2.imread(path)
    return img 

def create_temp_image(images_dir, temp, temp_level):
    """
        Creates a image for the screen based on temperature and temperature level 

        Args:
            images_dir: folders that contains images 
            temp: temperature in Celsius 
            temp_level: normal or high 
        
        Returns:
            img

    """
    if temp_level.data == 'GREEN':
            path = images_dir + 'temp_normal.png' # temp_high.png or temp_normal.png
    elif temp_level.data == 'RED':
        path = images_dir + 'temp_high.png'
    else:
        path = images_dir + 'temp_normal.png' # temp_high.png or temp_normal.png
    base_image = cv2.imread(path)
    outputString = temp.data + "C"
    cv2.putText(base_image, outputString , (300, 490), cv2.FONT_HERSHEY_DUPLEX, 5.0, (0, 0, 0), 4)
    cv2.imwrite(images_dir + 'temp.png',base_image)

    img = cv2.imread(images_dir + 'temp.png')
    return img 