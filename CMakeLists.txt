cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE "Release")

set(LIB_DIR ~/myLibs)       # !change this to where your library folder is located!
set(projectName example)    # !change this to a proper name!

# project initialisation
project(${projectName} VERSION 1.0.0 LANGUAGES CXX)
add_subdirectory(app)

