# Simple Huffman Coding Implementation

This is a simple educational implementation of the Huffman Coding algorithm for compression.

Both encoding and decoding was implemented in this program.

## Huffman Coding basics

Huffman code is an optimal prefix code used for lossless data compression.

The basic ideia is to encode characters in a text file with non constant bit lengths, in such way that the most commom characters have the smallest encoded bit length representation, and the least used characters have the biggest.

This encoding is done trough generating a Huffman Tree, in which the most commom characters stays in nodes closer to the tree root.

Using the tree representation, the bit encodings of characters result from the path to its node from the root, appending a '0' for left branches and '1' for right branches.

More information and details: https://en.wikipedia.org/wiki/Huffman_coding

## Download and build

Clone this repository, and move to its directory.

```
git clone https://github.com/rodipm/huffman_coding.git
cd huffman_coding
```

Run:
```
make
```

The executable file will be in

```
bin/huffman.exe
```

## Run

1. You can compress files by running:

```
huffman.exe file_name
```

This will generate a compressed file with a ".huff" extension

2. You can decompress .huff files by running

```
huffman.exe file_name.huff
```
Compressed files must end with `.huff` extension.

The previous command will output the decompressed file to stdout. If you want to save the decompressed file, just redirect the output to a file:

```
huffman.exe example.huff > example
```
