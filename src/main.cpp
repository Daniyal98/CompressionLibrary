#include "compression.h"
#include "huffman.h"
#include <iostream>

int main()
{
    std::string text = "this is an example of huffman coding in c++";

    // Convert string to a vector of bytes
    std::vector<uint8_t> inputData(text.begin(), text.end());

    // Create a HuffmanCoding object
    HuffmanCoding huffman;

    // Compress the data
    std::vector<uint8_t> compressedData = huffman.compress(inputData);
    std::cout << "Compressed data size: " << compressedData.size() << " bytes" << std::endl;

    // Decompress the data
    std::vector<uint8_t> decompressedData = huffman.decompress(compressedData);

    // Convert the decompressed data back to a string
    std::string decompressedString(decompressedData.begin(), decompressedData.end());
    std::cout << "Decompressed data: " << decompressedString << std::endl;
    std::cout << "Decompressed data size: " << decompressedData.size() << " bytes" << std::endl;

    return 0;
}