cmake_minimum_required(VERSION 3.15)

# set the project name
project(Tutorial VERSION 1.0.1)

configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the executable
add_executable(${PROJECT_NAME} tutorial.cpp)

string(TIMESTAMP COMPILE_TIME %Y%m%d-%H%M%S)