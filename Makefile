# Makefile

# Set a default value for OBJ_DIR if it is not provided as a command-line argument
obj ?= practice.cpp

all:
	g++ -std=c++20 $(obj) -o practice
	./practice

clean:
	rm practice
