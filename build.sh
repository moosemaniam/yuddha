#!/bin/bash

# Create a build directory if it doesn't exist
mkdir -p build

# Change to the build directory
cd build

# Run CMake to configure the project
cmake ..

# Build the project
cmake --build .
