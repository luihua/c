#cmake -G"MinGW Makefiles" .. 接cmakefile.txt路径 ,
#使用cmake插件默认将Makefile文件生成到{workfolder}/build
set(CMAKE_C_COMPILER "D:\\MSYS2\\ucrt64\\bin\\gcc.exe")
set(CMAKE_CXX_COMPILER "D:\\MSYS2\\ucrt64\\bin\\g++.exe")


cmake_minimum_required(VERSION 3.15)



# set the project name
project(Tutorial VERSION 1.0.1)

configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the executable
add_executable(${PROJECT_NAME}  main.cpp)

string(TIMESTAMP COMPILE_TIME %Y%m%d-%H%M%S)
#add the sub directory 
# add_subdirectory(data_struct)
# target_link_libraries(${PROJECT_NAME} PUBLIC yy.hpp)
# target_include_directories(${PROJECT_NAME} PUBLIC
#                            ${PROJECT_BINARY_DIR}
#                            ${PROJECT_SOURCE_DIR}/data_struct
#                            )

#添加头文件目录,target 可以是project和library
#include_directories(./data_struct)
target_include_directories(${PROJECT_NAME} PUBLIC ./data_struct)

# 添加链接库
target_link_libraries(${PROJECT_NAME} MathFunctions)

#add the sub directory 
add_subdirectory(data_struct)
# CMAKE_SOURCE_DIR cmakelists所在目录