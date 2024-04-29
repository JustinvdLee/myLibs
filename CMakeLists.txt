cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_DIR /home/justin/myLibs)    # !change this to where your library folder is located!
set(projectName example)            # !change this to a proper name!

# project initialisation
project(${projectName} VERSION 1.0.0 LANGUAGES CXX)
add_executable(${projectName} main.cpp)

set_target_properties(${projectName} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
    RUNTIME_OUTPUT_DIRECTORY "../"  # !update this to you desired location!
)

# add the libraries that are needed
find_library(TIMING timing PATH ${LIB_DIR}/timing)
if (NOT TIMING)
    add_subdirectory(${LIB_DIR}/timing timing)
endif()

find_library(PRIME prime PATH ${LIB_DIR}/prime)
if (NOT PRIME)
    add_subdirectory(${LIB_DIR}/prime prime)
endif()

# link all the libraries and header files
include_directories(${LIB_DIR}/timing ${LIB_DIR}/prime)
target_link_libraries(${projectName} ${TIMING} ${PRIME})

