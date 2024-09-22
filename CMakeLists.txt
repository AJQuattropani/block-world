cmake_minimum_required(VERSION 3.28)

set (dependencies_dir "${CMAKE_SOURCE_DIR}/dependencies")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
project(BlockWorld VERSION 0.1.0)

file (GLOB dependencies "${dependencies_dir}/*.h" "${dependencies_dir}/*.c")

add_executable(BlockWorld src/main.cpp ${dependencies})

target_include_directories(BlockWorld PRIVATE ${dependencies_dir})

target_link_libraries(BlockWorld PRIVATE glfw)

