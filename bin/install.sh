#!/bin/bash

# install cmake
if ! [$(dpkg -l | grep cmake) -eq 0]; then
  sudo apt-get install cmake
fi

#install boost-python
if ! [$(dpkg -l | grep boost) -eq 0]; then 
  sudo apt-get install libboost-all-dev
fi