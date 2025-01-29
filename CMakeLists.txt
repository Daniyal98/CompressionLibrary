cmake_minimum_required(VERSION 3.10)
project(CompressionLibrary)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add source files
add_executable(CompressionLibrary src/main.cpp src/huffman.cpp)

# Link libraries if necessary (e.g., zlib, etc.)