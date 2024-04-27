cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# change this to where your library folder is located
set(LIB_DIR /home/justin/myLibs) 
# change this to a proper name
set(projectName example) 
project(${projectName} VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(app)
#  Add / remove the specific libraries you (don't) need
add_subdirectory(${LIB_DIR}/timingLib timingLib)
add_subdirectory(${LIB_DIR}/primeLib primeLib)

