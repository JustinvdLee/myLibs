add_executable(${projectName} main.cpp)

set_target_properties(${projectName} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
    RUNTIME_OUTPUT_DIRECTORY "../../"   # !update this to you desired location!
)

# add the libraries that are needed
set(libList prime; ringbuffer; timing)  # !update this to use the libraries that are needed!

# add the libraries to the project
# TODO: Improve or clean this code
message("finding libraries:")
foreach(libName IN LISTS libList)
    string(TOUPPER ${libName} Lib)                  # create the variable for the library name in capital
    set(libPath "${LIB_DIR}/${libName}")            # create a variable of the path to the library
    find_library(${Lib} ${libName} PATH ${libPath}) # try to find the library
    if (NOT ${Lib})                                 # if not find, compile it with the project
        add_library(${Lib} OBJECT "${libPath}/${libName}.cpp")
        set(${Lib} ${Lib})
    endif()
    # message("${libName}\t: ${${Lib}}")            # debug output
    include_directories(${libPath})                 # add the directory
    target_link_libraries(${projectName} ${${Lib}}) # add the library
endforeach()

