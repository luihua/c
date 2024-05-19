#cmake -G"MinGW Makefiles" ..  
#使用cmake插件默认将Makefile文件生成到{workfolder}/build

cmake_minimum_required(VERSION 3.15)



# set the project name
project(Tutorial VERSION 1.0.1)

configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the executable
add_executable(${PROJECT_NAME} bitree.cpp)

string(TIMESTAMP COMPILE_TIME %Y%m%d-%H%M%S)
#add the sub directory 
add_subdirectory(data_struct)
target_link_libraries(${PROJECT_NAME} PUBLIC yy.hpp)
target_include_directories(${PROJECT_NAME} PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${PROJECT_SOURCE_DIR}/data_struct
                           )
