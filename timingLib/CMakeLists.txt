cmake_minimum_required(VERSION 3.26)

set (LIB_NAME timingLib)
project(${LIB_NAME})

add_library(${LIB_NAME} STATIC ${LIB_NAME}.cpp)
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

