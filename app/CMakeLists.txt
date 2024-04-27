add_executable(${projectName} main.cpp)

set_target_properties(${projectName} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
    RUNTIME_OUTPUT_DIRECTORY "../"
)

target_link_libraries(${projectName} primeLib timingLib)

