# Compiler and flags
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -O2
TARGET = writer
SRC = writer.c
OBJ = $(SRC:.c=.o)
BUILD_DIR = build

# Default target: Build the writer application
all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET)

# Rule to build the writer application
$(BUILD_DIR)/$(TARGET): $(BUILD_DIR)/$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile the source file into an object file
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean target: Removes the build folder and all its contents
clean:
	rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean
