#!/bin/bash
set -x
mkdir lib
cd lib && git clone --branch=master https://github.com/pybind/pybind11.git
cd ..
mkdir build
cd ./build
cmake CC=gcc CXX=g++ -DPYTHON_EXECUTABLE:FILEPATH=C:/Users/corbi/AppData/Local/Programs/Python/Python37/python.exe ../
cmake --build .