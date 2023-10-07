cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(algo_lib VERSION 0.1.2)

set(ALGO_LIB algo_lib)
set(ALGO_LIB_PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/)

add_subdirectory(cmake)
add_subdirectory(src)
add_subdirectory(tests)