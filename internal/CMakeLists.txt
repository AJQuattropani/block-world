set (parallel_bit_ops_dir "${CMAKE_CURRENT_SOURCE_DIR}/parallelbitops/")

file (GLOB parallel_source_files "${parallel_bit_ops_dir}/*.cpp")
file (GLOB parallel_header_files "${parallel_bit_ops_dir}/*.hpp")

add_library(
	ParallelBitOps
	
	${parallel_header_files}
	${parallel_source_files}
	)

target_include_directories(ParallelBitOps PUBLIC ${parallel_bit_ops_dir})
