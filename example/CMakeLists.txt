set(SRCS "example.cpp")
add_source_file(${CMAKE_CURRENT_SOURCE_DIR}/resource SRCS)

add_executable(example ${SRCS})
target_link_libraries(example xxd::xxd)

