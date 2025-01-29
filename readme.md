# Data Compression Library

A C++ library that implements various data compression algorithms, including **Huffman Coding**. This library provides a flexible and extensible interface for compressing and decompressing data, with the ability to add more compression algorithms in the future.

## Features

- **Huffman Coding**: A lossless compression algorithm that uses a frequency-based binary tree to compress data.
- **Extensible Interface**: Easily extendable to support other compression algorithms (e.g., LZ77, Deflate, Zstandard).
- **Compression and Decompression**: Functions for compressing and decompressing data using supported algorithms.
- **C++11+ Support**: Designed with modern C++ features and standards.

## Requirements

- C++17 or later
- CMake 3.10 or later

## Installation

### Clone the repository
```bash
git clone https://github.com/yourusername/CompressionLibrary.git
cd CompressionLibrary

### Build the project using CMake
```bash
mkdir build
cd build

### Run CMake to generate the build files
```bash
cmake ..

### Compile the project
```bash
make

### Run the tests
```bash
#include "compression.h"
#include "huffman.cpp"
#include <iostream>

int main() {
    // Example string to compress
    std::string text = "this is an example of huffman coding in c++";

    // Convert string to vector of bytes
    std::vector<uint8_t> inputData(text.begin(), text.end());

    // Create an object for Huffman Coding
    HuffmanCoding huffman;
    
    // Compress the data
    std::vector<uint8_t> compressedData = huffman.compress(inputData);
    std::cout << "Compressed data size: " << compressedData.size() << " bytes" << std::endl;

    // Decompress the data
    std::vector<uint8_t> decompressedData = huffman.decompress(compressedData);
    
    // Convert decompressed data back to a string
    std::string decompressedString(decompressedData.begin(), decompressedData.end());
    std::cout << "Decompressed data: " << decompressedString << std::endl;

    return 0;
}