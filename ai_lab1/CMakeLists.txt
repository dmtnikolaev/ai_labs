cmake_minimum_required(VERSION 3.20)
project(ai_lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(ai_lab1 src/main.cpp src/tag.cpp src/tag.h src/tree.cpp src/tree.h src/deep.cpp src/deep.h src/conditions.h src/iterative.cpp src/iterative.h src/host.cpp src/host.h src/fabric.cpp src/fabric.h)
