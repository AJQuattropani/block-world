cmake_minimum_required(VERSION 3.28)
project(BlockWorld VERSION 1.0.0)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")

add_subdirectory(internal)
add_subdirectory(src)
