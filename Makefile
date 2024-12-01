CC = gcc                 # The C compiler you want to use
CFLAGS = -Wall           # Compiler flags (optional, but -Wall shows all warnings)
SRC_DIR = src            # Directory for source files (optional)
OBJ_DIR = obj            # Directory for object files (optional)
BIN_DIR = bin            # Directory for binaries (optional)

# List of source files (this could be expanded as needed)
SOURCES = $(wildcard *.c)  # All .c files in the current directory
OBJECTS = $(SOURCES:.c=.o)  # Corresponding object files

# Output binary names (same as source filenames without .c)
TARGETS = $(SOURCES:.c=)

# Default target to build all programs
all: $(TARGETS)

# Rule to compile any .c file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into an executable (name based on .c file)
%: %.o
	$(CC) $(CFLAGS) -o $@ $^

# Run all the programs (could also use a specific list of targets)
run: $(TARGETS)
	@for prog in $(TARGETS); do \
		./$$prog; \
	done

# Clean up generated files
clean:
	rm -f $(TARGETS) $(OBJECTS)

.PHONY: all run clean
