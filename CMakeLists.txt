cmake_minimum_required(VERSION 3.28)

#find_package(glfw3 3.4 REQUIRED)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
project(BlockWorld VERSION 0.1.0)

add_executable(BlockWorld src/main.cpp)

target_link_libraries(BlockWorld PRIVATE glfw)

