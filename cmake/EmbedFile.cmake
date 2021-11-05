cmake_minimum_required(VERSION 3.0)

# Read the resulting HEX content into variable
file(READ ${FILE_HEX} CONTENT_HEX)

string(SHA256 FILE_NAME_HASH ${FILE_NAME})

execute_process(COMMAND xdg-mime query filetype ${FILE_PATH} OUTPUT_VARIABLE FILE_MIME)

# Substitute encoded HEX content into template source file
configure_file("${CMAKE_CURRENT_INCLUDE_DIR}/xxd.in" ${EMBED_FILE_PATH})

