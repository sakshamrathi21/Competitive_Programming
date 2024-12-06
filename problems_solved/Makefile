# Makefile
# Define the source file and the output executable
SRC = $(file_name)
OUT = practice

# Define the compiler and the compiler flags
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra

# The default target to build
all: $(OUT)

# The rule to build the output executable
$(OUT): $(SRC)
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

# A rule to clean up the build files
clean:
	rm -f $(OUT)
