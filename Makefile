CC = gcc                  # The C compiler you want to use
CXX = g++                  # The C++ compiler you want to use
CFLAGS = -Wall             # Compiler flags (optional, but -Wall shows all warnings)
CXXFLAGS = -Wall           # C++ compiler flags (same as CFLAGS for consistency)

SRC_DIR = src              # Directory for source files (optional)
OBJ_DIR = obj              # Directory for object files (optional)
BIN_DIR = bin              # Directory for binaries (optional)

# List of source files
C_SOURCES = $(wildcard *.c)     # All .c files in the current directory
CPP_SOURCES = $(wildcard *.cpp) # All .cpp files in the current directory

# Corresponding object files
C_OBJECTS = $(C_SOURCES:.c=.o)
CPP_OBJECTS = $(CPP_SOURCES:.cpp=.o)

# All object files
OBJECTS = $(C_OBJECTS) $(CPP_OBJECTS)

# Output binary names (same as source filenames without .c or .cpp)
C_TARGETS = $(C_SOURCES:.c=)
CPP_TARGETS = $(CPP_SOURCES:.cpp=)
TARGETS = $(C_TARGETS) $(CPP_TARGETS)

# Default target to build all programs
all: $(TARGETS)

# Rule to compile C files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile C++ files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into an executable (name based on .c or .cpp file)
%: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Run all the programs (could also use a specific list of targets)
run: $(TARGETS)
	@for prog in $(TARGETS); do \
		./$$prog; \
	done

# Clean up generated files
clean:
	rm -f $(TARGETS) $(OBJECTS)

.PHONY: all run clean
