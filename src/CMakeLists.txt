cmake_minimum_required(VERSION 3.13)

# CommandCalc pre-defined in root directory
include_directories(${CommandCalc_SOURCE_DIR}/include)

# Add any libraries similarily below.

# Define main executable's name.
add_executable(ccal main.cpp)

set_target_properties(
    ccal
    PROPERTIES
        OUTPUT_NAME "ccal"
        SUFFIX ""
)


