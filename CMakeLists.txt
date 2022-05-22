cmake_minimum_required(VERSION 3.13)
project(CommandCalc VERSION 0.1.0)

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
    src/rpnstack.cpp
)

set_target_properties(
    ccal
    PROPERTIES
        OUTPUT_NAME "ccal"
        SUFFIX ""
)

# Definition for installing to /usr/local/bin.
install(TARGETS ccal
    DESTINATION /usr/local/bin
)
 
# Tell LSPs where include files are.
add_compile_definitions(VERSION="${CMAKE_PROJECT_VERSION}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

