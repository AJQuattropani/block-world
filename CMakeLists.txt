cmake_minimum_required(VERSION 3.25)
project(BlockWorld LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

file(COPY Resources DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB VENDOR_FILES ${PROJECT_SOURCE_DIR}/src/vendor/*.h)

if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(#[[-Wall]] #[[-Wextra]] #[[-Wpedantic]] -g #[[-mavx -mavx2]] -march=native)
endif()

add_compile_definitions(#[[DIST]] DEBUGGER BW_DEBUGGING GL_DEBUGGING)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${VENDOR_FILES})
add_subdirectory(dependencies)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/vendor/)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm glfw glad)