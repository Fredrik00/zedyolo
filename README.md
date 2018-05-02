# zedyolo

This project is designed to run on a Nvidia Jetson TX2 development kit combined with ZED stereo camera from Stereolabs in order to perform object detecion combined with depth data, and place objects in a coordinate system relative to itself. The program publishes both camera and object data to a ROS network, using the ZED ROS Wrapper from Stereolabs for retreiving left camera image and a depth map from the camera. Inside the object_detection package is located the actual source code for general object detection, using pyyolo as a python wrapper to YOLOv2. The python files zedyolo.py and zedyolo_draw.py handle the full loop of image retrieval, object detection, depth calculation and determining coordinates for each object. The code is written for Python 2.7 but should be transferrable for Python 3 with a compatible version of OpenCV.

For installation instructions we first direct to the external resources, follow their instructions to set up the environment.
https://www.stereolabs.com/developers/release/2.3/ 
http://wiki.ros.org/lunar/Installation/Ubuntu
http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment
https://github.com/stereolabs/zed-ros-wrapper (source code included in the project)
https://github.com/digitalbrain79/pyyolo (source code included in the project)

Refer to general instructions for installation of ROS packages, as well as running them.
Once the project is fully set up and the ROS ZED Wrapper is running, the project can be launched from either of the aforementioned python files. Output can then for example be read in the terminal using "rostopic echo /objdet/predictions".
