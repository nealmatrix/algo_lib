cmake_minimum_required(VERSION 3.15)
project(demo)
add_executable(${PROJECT_NAME} demo.cpp)

find_package(cpp_lib 0.1.2 REQUIRED)
target_link_libraries(${PROJECT_NAME} cpp_lib::cpp_lib)