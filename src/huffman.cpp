#include "huffman.h"

void HuffmanCoding::buildHuffmanTree(const std::unordered_map<char, int> &freqMap)
{
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, HuffmanNode::Compare> pq;

    // Build the min-heap (priority queue)
    for (const auto &pair : freqMap)
    {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Build the Huffman Tree
    while (pq.size() > 1)
    {
        HuffmanNode *left = pq.top();
        pq.pop();
        HuffmanNode *right = pq.top();
        pq.pop();

        HuffmanNode *merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    // Generate Huffman codes
    generateHuffmanCodes(pq.top(), "");
}

void HuffmanCoding::generateHuffmanCodes(HuffmanNode *node, const std::string &str)
{
    if (node == nullptr)
        return;

    if (node->ch != '\0')
    { // Leaf node
        huffmanCode[node->ch] = str;
        reverseHuffmanCode[str] = node->ch;
    }

    generateHuffmanCodes(node->left, str + "0");
    generateHuffmanCodes(node->right, str + "1");
}

std::vector<uint8_t> HuffmanCoding::compress(const std::vector<uint8_t> &data)
{
    std::unordered_map<char, int> freqMap;

    // Calculate frequency of each character
    for (uint8_t byte : data)
    {
        freqMap[static_cast<char>(byte)]++;
    }

    buildHuffmanTree(freqMap);

    // Encode data using Huffman codes
    std::string encodedString;
    for (uint8_t byte : data)
    {
        encodedString += huffmanCode[static_cast<char>(byte)];
    }

    // Convert the encoded string to a vector of bytes
    std::vector<uint8_t> compressedData;
    for (size_t i = 0; i < encodedString.size(); i += 8)
    {
        std::bitset<8> byte(encodedString.substr(i, 8));
        compressedData.push_back(static_cast<uint8_t>(byte.to_ulong()));
    }

    return compressedData;
}

std::vector<uint8_t> HuffmanCoding::decompress(const std::vector<uint8_t> &compressedData)
{
    std::string encodedString;
    for (uint8_t byte : compressedData)
    {
        encodedString += std::bitset<8>(byte).to_string();
    }

    std::string currentCode;
    std::vector<uint8_t> decompressedData;

    for (char bit : encodedString)
    {
        currentCode += bit;

        if (reverseHuffmanCode.find(currentCode) != reverseHuffmanCode.end())
        {
            decompressedData.push_back(static_cast<uint8_t>(reverseHuffmanCode[currentCode]));
            currentCode.clear();
        }
    }

    return decompressedData;
}