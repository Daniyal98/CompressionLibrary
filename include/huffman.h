#include "compression.h"
#include <queue>
#include <unordered_map>
#include <iostream>
#include <bitset>

class HuffmanNode
{
public:
    char ch;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}

    // Comparator for priority queue (min-heap)
    struct Compare
    {
        bool operator()(HuffmanNode *a, HuffmanNode *b)
        {
            return a->freq > b->freq;
        }
    };
};

class HuffmanCoding : public CompressionAlgorithm
{
private:
    std::unordered_map<char, std::string> huffmanCode;
    std::unordered_map<std::string, char> reverseHuffmanCode;

    void buildHuffmanTree(const std::unordered_map<char, int>& freqMap);
    void generateHuffmanCodes(HuffmanNode* node, const std::string& str);

public:
    std::vector<uint8_t> compress(const std::vector<uint8_t>& data) override;
    std::vector<uint8_t> decompress(const std::vector<uint8_t>& compressedData) override;
};