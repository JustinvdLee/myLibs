cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_DIR /home/justin/myLibs)    # !change this to where your library folder is located!
set(projectName example)            # !change this to a proper name!

# project initialisation
project(${projectName} VERSION 1.0.0 LANGUAGES CXX)
add_subdirectory(app)

