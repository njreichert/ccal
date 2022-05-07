cmake_minimum_required(VERSION 3.13)
project(CommandCalc)

# Actual definitions in this directory
add_subdirectory(src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

