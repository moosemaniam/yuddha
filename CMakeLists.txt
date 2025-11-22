# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(yuddha)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add raylib as a subdirectory
# This will configure and build raylib
add_subdirectory(raylib)

# Add the executable
add_executable(yuddha src/main.cpp src/soul.cpp src/mote.cpp src/world.cpp)

# Link raylib to the executable
target_link_libraries(yuddha PRIVATE raylib)
