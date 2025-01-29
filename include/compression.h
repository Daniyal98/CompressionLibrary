#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <vector>
#include <string>

class CompressionAlgorithm
{
public:
    virtual ~CompressionAlgorithm() = default;

    // Compress data
    virtual std::vector<uint8_t> compress(const std::vector<uint8_t> &data) = 0;

    // Decompress data
    virtual std::vector<uint8_t> decompress(const std::vector<uint8_t> &compressedData) = 0;
};

#endif // COMPRESSION_H