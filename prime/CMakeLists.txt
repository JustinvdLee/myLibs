cmake_minimum_required(VERSION 3.26)
set (LIB_NAME prime)

# initialise a project to compile the library on its own and add the .cpp file(s)
project(${LIB_NAME})
add_library(${LIB_NAME} STATIC ${LIB_NAME}.cpp)

# include the header file(s) and the compiled library in the working directory
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(${LIB_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "../")

