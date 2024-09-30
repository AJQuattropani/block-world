cmake_minimum_required(VERSION 3.20)
project(BlockWorld LANGUAGES CXX VERSION 0.0.1)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
add_subdirectory(dependencies)

target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm glfw glad)