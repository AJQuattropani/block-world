set (blockworld_src_dir "${CMAKE_CURRENT_SOURCE_DIR}")

file (GLOB blockworld_src_headers "${blockworld_src_dir}/*.hpp")
file (GLOB blockworld_src "${blockworld_src_dir}/*.cpp")

add_executable(BlockWorld ${blockworld_src_headers} ${blockworld_src})

target_link_libraries(BlockWorld PRIVATE ParallelBitOps)

