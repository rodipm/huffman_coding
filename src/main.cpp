#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <limits>

#include "PriorityQueue.hpp"
#include "CreatedNodeList.cpp"

// http://en.cppreference.com/w/cpp/language/type_alias
using byte = unsigned char ;

// http://en.cppreference.com/w/cpp/types/numeric_limits
constexpr std::size_t BITS_PER_BYTE = std::numeric_limits<byte>::digits ;

// http://en.cppreference.com/w/cpp/utility/bitset
using bits_in_byte = std::bitset<BITS_PER_BYTE> ;

void generateStringCodes(Node *node, std::string *codes, std::stringstream &code)
{
  if (node->l_child == nullptr && node->r_child == nullptr)
  {
    codes[static_cast<int>(node->symbol)] = code.str();
    code.str("");
    return;
  }

  std::string oldCode = code.str();

  code << "1";
  generateStringCodes(node->r_child, codes, code);

  std::stringstream lCode;
  lCode << oldCode << "0";
  if (node->l_child != nullptr)
  {
    generateStringCodes(node->l_child, codes, lCode);
  }
}

std::string preprocess(std::string path, int *chars, PriorityQueue& pq, CreatedNodeList& createdNodeList)
{
  std::ifstream t(path);
  std::stringstream text;
  text << t.rdbuf();

  for (auto ch : text.str())
  {
    chars[ch] += 1;
  }

  for (int i = 0; i < 128; i++)
  {
    if (chars[i] != 0)
    {
      Node *n = new Node();
      n->symbol = static_cast<char>(i);
      n->weight = chars[i];
      n->parent = nullptr;
      n->l_child = nullptr;
      n->r_child = nullptr;

      createdNodeList.push(n);
      pq.push(n);
    }
  }

  return text.str();
}

std::string encodeString(std::string text, std::string codes[128])
{
  std::stringstream encoded;
  for (auto ch : text)
  {
    encoded << codes[ch];
  }
  return encoded.str();
}

std::string decodeString(std::string text, Node *tree)
{
  std::stringstream decoded;

  Node *curNode = tree;
  Node *nextNode = nullptr;

  for (auto ch : text)
  {
    if (curNode->l_child == nullptr && curNode->r_child == nullptr)
    {
      decoded << curNode->symbol;
      curNode = tree;
    }
    if (ch == '0')
      curNode = curNode->l_child;
    else
      curNode = curNode->r_child;
  }

  if (curNode->l_child == nullptr && curNode->r_child == nullptr)
    decoded << curNode->symbol;
  return decoded.str();
}

Node* generateTree(PriorityQueue& pq, CreatedNodeList& createdNodeList)
{
  while (pq.getSize() > 1)
  {
    int newWeight = 0;
    Node *interiorNode = new Node();
    createdNodeList.push(interiorNode);
    interiorNode->r_child = pq.pop();
    newWeight += interiorNode->r_child->weight;

    interiorNode->l_child = pq.pop();
    if (interiorNode->l_child != nullptr)
      newWeight += interiorNode->l_child->weight;

    interiorNode->weight = newWeight;
    pq.push(interiorNode);
  }

  return pq.pop();
}

std::string read_bits( const char* path_to_file )
{
    std::string bitstring ;
    std::ifstream file( path_to_file, std::ios::binary ) ; // open in binary mode

    char c ;
    while( file.get(c) ) // read byte by byte
        bitstring += bits_in_byte( byte(c) ).to_string() ; // append as string of '0' '1'

    return bitstring ;
}

void write_bits( std::string bitstring, const char* path_to_file )
{
    // pad with zeroes to make it represent an integral multiple of bytes
    while( bitstring.size()% BITS_PER_BYTE ) bitstring += '0' ;

    std::ofstream file( path_to_file, std::ios::binary ) ; // open in binary mode

    for( std::size_t i = 0 ; i < bitstring.size() ; i += BITS_PER_BYTE )
    {
        // convert each sequence of '0' or '1' to a byte
        byte b = bits_in_byte( bitstring.substr( i, BITS_PER_BYTE ) ).to_ulong() ;
        file << b ; // and write it
    }
}

int main()
{
  srand(static_cast<unsigned int>(time(NULL)));
  Node *tree = nullptr;
  CreatedNodeList createdNodeList;
  PriorityQueue pq;
  int chars[128] = {};

  std::string path("Makefile");
  std::string text = preprocess(path, chars, pq, createdNodeList);
  tree = generateTree(pq, createdNodeList);

  std::string codes[128];
  std::stringstream code;
  generateStringCodes(tree, codes, code);

  for (int i = 0; i < 128; i++)
  {
    if (codes[i] != "")
      std::cout << static_cast<char>(i) << ": " << codes[i] << std::endl;
  }

  std::string encodedString = encodeString(text, codes);
  std::cout << encodedString << std::endl;

  write_bits(encodedString, "encodedFile");

  std::string readEncodedString = read_bits("encodedFile");

  std::string decodedString = decodeString(readEncodedString, tree);
  std::cout << decodedString << std::endl;

  createdNodeList.clean();
  return 0;
}
