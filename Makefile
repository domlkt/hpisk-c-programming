CC = gcc           # The C compiler you want to use (GCC in this case)
CFLAGS = -Wall     # Compiler flags (optional, but -Wall shows all warnings)

# The output binary names for each program
TARGETS = helloworld variables

# Default target to build both programs
all: $(TARGETS)

# Rule to compile helloworld.c
helloworld: helloworld.c
	$(CC) $(CFLAGS) -o helloworld helloworld.c

# Rule to compile goodbye.c
goodbye: variables.c
	$(CC) $(CFLAGS) -o variables variables.c

# Run both programs
run: $(TARGETS)
	./helloworld
	./variables

# Clean up generated files
clean:
	rm -f $(TARGETS)   # Remove both helloworld and goodbye binaries

.PHONY: all run clean  # Declare that these aren't actual files
