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
find_library(TIMING_LIB timingLib PATH ${LIB_DIR}/timingLib)
find_library(PRIME_LIB primeLib PATH ${LIB_DIR}/primeLib)

# link all the libraries and header files
include_directories(${LIB_DIR}/timingLib ${LIB_DIR}/primeLib)
target_link_libraries(${projectName} ${TIMING_LIB} ${PRIME_LIB})

