# Q-Robot

Q-Robot is a versatile open-source Quadruped Robot developed with affordable electronic devices, with structural parts printed in PLA from 3D printers, integrating Robot Operating System (ROS) and Wi-Fi connection. The project aims to present a model with significantly reduced cost, to use only standard components and straightforward fabrication, aiming its use for educational purposes.

Inspired by the famous fourlegged robot from Boston Dynamics, Spot Mini, Q-Robot is an adaptation of a model developed by Kim Deok-Yeon, named Spot Micro.

Q-Robot uses ROS packages [rosserial](http://wiki.ros.org/rosserial) and [CHAMP](https://github.com/chvmp/champ#champ-) to works.

![image](https://user-images.githubusercontent.com/70664574/177605353-7f97da58-9b27-49bd-bea6-c06beedf7953.png)

Tested on Ubuntu 18.04 with ROS Melodic 1.14.13

## Instructions

1 - Install rosserial package folowing this instructions [here](http://wiki.ros.org/rosserial);

2 - Install CHAMP package folowing this instructions [here](https://github.com/chvmp/champ#champ-);

3 - Follow the instructions to create your own robot using [champ_setup_assistent](https://github.com/chvmp/champ_setup_assistant);

4 - Running the rosserial package:

* cd <your_ws>/
* catkin_make
* source devel/setup.bash
* roslaunch rosserial_server socket.launch

5 - Open another terminal and running the CHAMP package of your robot configuration:

* cd <your_ws>/
* catkin_make
* source devel/setup.bash
* roslaunch <myrobot_config> bringup.launch

6 - To control your robot by laptop's keybord, run the teleop node:

* cd <your_ws>/
* catkin_make
* source devel/setup.bash
* roslaunch champ_teleop teleop.launch

If you want to use a joystick add joy:=true as an argument on the last command line:

* roslaunch champ_teleop teleop.launch joy:=true

7 - To autonoumus mode, with the Fuzzy obstacle avoidance, run the Matlab code
