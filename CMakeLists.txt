cmake_minimum_required(VERSION 3.1)

project(xxd)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(xxd ${CMAKE_CURRENT_SOURCE_DIR}/src/xxd.c)

add_library(libxxd SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/xxd.cpp)
target_include_directories(libxxd PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(libxxd PROPERTIES OUTPUT_NAME xxd)
add_library(xxd::xxd ALIAS libxxd)

set(CMAKE_CURRENT_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE STRING "" FORCE)

# Convert file into a binary blob and embed it into a C++ source file.
macro(xxd_embed FILE_KEY FILE_PATH SOURCES)
	# Translate content into comma-separated byte codes.
	set(FILE_HEX "${CMAKE_CURRENT_BINARY_DIR}/${FILE_KEY}.hex")
	add_custom_command(
		OUTPUT ${FILE_HEX}
		COMMAND $<TARGET_FILE:xxd> -i < ${FILE_PATH} > ${FILE_HEX}
		COMMENT "Generating hex representation of ${FILE_PATH} file content"
		DEPENDS ${FILE_PATH} xxd)
	set_source_files_properties("${FILE_HEX}" PROPERTIES GENERATED TRUE) 
	set(EMBED_FILE_PATH "${CMAKE_CURRENT_BINARY_DIR}/${FILE_KEY}.cpp")
	add_custom_command(
		OUTPUT ${EMBED_FILE_PATH}
		COMMAND ${CMAKE_COMMAND} -DCMAKE_CURRENT_INCLUDE_DIR=${CMAKE_CURRENT_INCLUDE_DIR} -DFILE_HEX=${FILE_HEX} -DFILE_KEY=${FILE_KEY} -DFILE_PATH=${FILE_PATH} -DEMBED_FILE_PATH=${EMBED_FILE_PATH} -P ${CMAKE_CURRENT_INCLUDE_DIR}/../cmake/EmbedFile.cmake
		COMMENT "Embedding file ${FILE_PATH}"
		DEPENDS ${FILE_HEX} "${CMAKE_CURRENT_INCLUDE_DIR}/xxd.in")
	set_source_files_properties("${EMBED_FILE_PATH}" PROPERTIES GENERATED TRUE) 

	# Submit the resulting source file for compilation
	list(APPEND ${SOURCES} ${EMBED_FILE_PATH})

	# Disable optimization for this source file, as it would otherwise take too long
	# to compile, in case of big files.
	set_source_files_properties(${EMBED_FILE_PATH} PROPERTIES COMPILE_FLAGS ${CMAKE_CXX_FLAGS_DEBUG})

	message(STATUS "Source file ${EMBED_FILE_PATH} shall be added to ${SOURCES}")
endmacro()

add_subdirectory(example)
