set(SRCS "example.cpp")
xxd_embed(${CMAKE_CURRENT_SOURCE_DIR}/resource SRCS)

add_executable(xxd_example ${SRCS})
target_link_libraries(xxd_example xxd::xxd)

