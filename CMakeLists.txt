cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_DIR /home/justin/myLibs) # change this to where your library folder is located
set(projectName example) # change this to a proper name

project(${projectName} VERSION 1.0.0 LANGUAGES CXX)
add_executable(${projectName} main.cpp)

set_target_properties(${projectName} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

#  Add / remove the specific libraries you (don't) need
add_subdirectory(${LIB_DIR}/timingLib timingLib)
add_subdirectory(${LIB_DIR}/primeLib primeLib)

target_link_libraries(${projectName} primeLib timingLib)

