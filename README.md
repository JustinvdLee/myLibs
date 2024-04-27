# Personal Libraries
This is a folder that contains general libraries made by me (JustinvdLee).
All the folders are made to work with cmake.
It also serves as a cmake framework, to quickstart a project by copying a few files

### Copyright
You are free to use this repository for non-commercial purposes, as long as you credit the original source.
For commercial use, please contact the current maintainer of the repository.

### use one library
1. Copy the library you want to use.
2. Add the following two lines to your CMakeLists.txt
    
```CMake
set(LIB_DIR /the/directory/of/the/library)
add_subdirectory(${LIB_DIR}/nameLib nameLib)
```

```text
Note1: ${LIB_DIR} should equal to the location of this folder, either replace it or use set()
Note2: If this directory is your ${CMAKE_CURRENT_SOURCE_DIR}, you can omit the first argument in the second command
Note3: If you want to make a one-time library, you can also copy a lib-folder and modify the files there.
```

### use the framework
1. Copy the CMakeLists.txt and app/ to where you would like to start your project.
2. Look through the main CMakeLists to see what you need to change.
    Please remove the comments when you have executed their instructions
3. From there, you can modify the files to include what you need for your project.
