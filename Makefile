.PHONY: all run

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))

run: all
	./bin/huffman

all: bin/huffman

bin/huffman: $(OBJ)
	g++ -o $@ $^

build/%.o: src/%.cpp
	g++ -c -o $@ $<

clean:
	rm -f build/* bin/*
