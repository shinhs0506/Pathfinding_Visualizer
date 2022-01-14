#!bin/bash

# install build essential 
sudo apt-get install build-essential -y

# install qt5
sudo apt-get install qt5-default=5.12.8 -y

# initialize qt project
qmake -project

# add configuration
echo -e "\nQT += gui widgets" >> Pathfinding_Visualizer.pro

# make
qmake Pathfinding_Visualizer.pro
make
