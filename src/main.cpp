#include <iostream>

#include "Huffman.hpp"

int main(int argc, char **argv)
{
  
  if (argc < 2)
  {
    std::cout << "No input file." << std::endl;
    return 1;
  }

  std::string path(argv[1]);
  Huffman huffman(path);

  if (path.find(".huff") == std::string::npos)
    huffman.encode();
  else
    std::cout << huffman.decode() << std::endl;
  return 0;
}
