## Personal Libraries
This is a folder that contains general libraries that can also be adapted to specific needs.
All the folders are made to work with cmake.
It also serves as a cmake framework, to quickstart a project by copying a few files.

### Disclaimer
This project is started by JustinvdLee.
This repository is not made by a professional.
All of the on this is done with good intent, but there is NO guarantee that it will work, even for the intended purpose.
If problems / improvements are spotted, please contact the maintainer.

### Copyright
You are free to use this repository for non-commercial purposes, as long as you credit the original source.
For commercial use, please contact the current maintainer of the repository.

### Tutorial
#### Building
To build a library or project, use the following commands:
```shell
mkdir .build && cd .build
```
```shell
cmake ../.
```
```shell
make
```
```shell
cd .. && rm -rf .build/
```

>Note1: Beware of the dangers of 'rm', the folder doesn't need to be deleted, this is only done for the purpose of clean structure

#### use a library
1. Copy the library you want to use.
2. Add the following lines to your CMakeLists.txt:
```CMake
set(LIB_DIR /the/libraries/directory)
find_library(NAME_LIB nameLib PATH ${LIB_DIR}/nameLib)
target_link_libraries(${projectName} ${NAME_LIB})
```
>Note1: ${LIB_DIR} should equal to the location of this folder, either replace it or use set()

Or you can use the following line instead of the find_library command if you don't mind the library being rebuild for ever project:
```CMake
add_subdirectory(${LIB_DIR}/nameLib nameLib)
```
>Note1: If the library is a subdirectory of your project root, you can omit the first argument of the second line.

#### modify a library
If you want to copy a library and modify it to your specific needs, you can follow the next steps:
1. Copy the library you want to use
2. Modify the .cpp and .h files as you like
3. Rebuild the library as described earlier

#### use the framework
1. Copy the CMakeLists.txt and the app/ directory to the project root.
2. Look through the CMakeLists.txt and follow the instructions of the comments.
    Please remove the comments when you have executed their instructions
3. From there, modify the files to include what is needed for the project.
4. The advised way to build the project is to use a .build/ directory. (see above commands) 
5. The project root should contain the ./projectName.exe file. This can be changed in the app/CMakeLists.txt
6. Run the .exe file with the following command (in the build directory):
```shell
../projectName
```

### Project Structure and naming convention
This chapter shows the layout and naming convention of this repository:
```text
repo root
|- CMakeLists.txt
|- pojectName.exe
|- README.md
|
|- app/
|   |-CMakeLists.txt
|   |-main.cpp
|
|- name1/
|   |- CMakeLists.txt
|   |- name1.cpp
|   |- name1.h
|   |- libname1.a
|
|- name2/
|   |- CMakeLists.txt
|   |- /inc
|   |   |- name2a.h
|   |   |- name2b.h
|   |- libname1.a
|   |- /src
|   |   |- name2a.cpp
|   |   |- name2b.cpp
|
|- etc.
```
