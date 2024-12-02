# Compiler and flags
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -O2
TARGET = writer
SRC = writer.c
OBJ = $(SRC:.c=.o)

# Default target: Build the writer application
all: $(TARGET)

# Rule to build the writer application
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile the source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target: Removes the writer application and object files
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets
.PHONY: all clean
