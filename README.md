## Personal Libraries
This is a folder that contains general libraries, started by JustinvdLee.
All the folders are made to work with cmake.
It also serves as a cmake framework, to quickstart a project by copying a few files

### Disclaimer
This repository is not made by a professional.
All of the on this is done with good intent, but there is NO guarantee that it will work, even for the intended purpose.
If problems / improvements are spotted, please contact the maintainer.

### Copyright
You are free to use this repository for non-commercial purposes, as long as you credit the original source.
For commercial use, please contact the current maintainer of the repository.

### Tutorial
#### use a library
1. Copy the library you want to use.
2. Add the following lines to your CMakeLists.txt:
```CMake
set(LIB_DIR /the/directory/of/the/library)
find_library(NAME_LIB nameLib PATH ${LIB_DIR}/nameLib)
target_link_libraries(${projectName} ${NAME_LIB})
```
```text
Note1: ${LIB_DIR} should equal to the location of this folder, either replace it or use set()
```
Or you can use the following lines if you don't mind the library being rebuild for ever project:
```CMake
set(LIB_DIR /the/directory/of/the/library)
add_subdirectory(${LIB_DIR}/nameLib nameLib)
```
```text
Note1: If the library is a subdirectory of your project root, you can omit the first argument of the second line.
```

#### use the framework
1. Copy the CMakeLists.txt and main.cpp to the project root.
2. Look through the CMakeLists.txt and follow the instructions of the comments.
    Please remove the comments when you have executed their instructions
3. From there, modify the files to include what is needed for the project.
4. The advised way to build the project is to use a build/ directory. For this, use the commands below:
```shell
mkdir build && cd build
cmake ../. && make
```
5. The project root should contain the ./projectName.exe file. This can be changed in the main CMakeLists.txt
6. Run the .exe file with the following command (in the build directory):
```shell
../projectName
```
