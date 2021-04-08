#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <sstream>
#include <fstream>
#include <bitset>
#include <limits>

#include "PriorityQueue.hpp"
#include "CreatedNodeList.cpp"

using byte = unsigned char;

constexpr std::size_t BITS_PER_BYTE = std::numeric_limits<byte>::digits;

using bits_in_byte = std::bitset<BITS_PER_BYTE>;

class Huffman
{
    std::string path;

    void generateStringCodes(Node *node, std::string *codes, std::stringstream &code);
    std::string preprocess(int *chars);
    std::string encodeString(std::string text, std::string *codes);
    std::string decodeString(std::string text, Node *tree);
    Node *generateTree(PriorityQueue &pq, CreatedNodeList &createdNodeList, int *chars);
    std::string read_bits(int *chars);
    void write_bits(std::string bitstring, int *chars);

public:
    Huffman(std::string path);
    ~Huffman();

    void encode();
    std::string decode();
};
#endif