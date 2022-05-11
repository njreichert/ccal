cmake_minimum_required(VERSION 3.13)
project(CommandCalc VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CommandCalc_SOURCE_DIR}/bin)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

# CommandCalc pre-defined in root directory
include_directories(${CommandCalc_SOURCE_DIR}/include)

# Add any libraries similarily below.

# Define main executable's name.
add_executable(ccal 
    src/main.cpp
    src/io.cpp
    src/ops.cpp
    src/util.cpp
    src/command_line.cpp
)

set_target_properties(
    ccal
    PROPERTIES
        OUTPUT_NAME "ccal"
        SUFFIX ""
)

add_compile_definitions(VERSION="${CMAKE_PROJECT_VERSION}")

