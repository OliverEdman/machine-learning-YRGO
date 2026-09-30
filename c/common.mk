# Shared build settings, included by each application's Makefile.
# Each application must set APP_NAME, and may set APP_SRC for extra sources.

# Build directory
BUILD_DIR := build

# Target application
TARGET := $(BUILD_DIR)/$(APP_NAME)

# C compiler
C_COMPILER := gcc

# C compiler flags
C_FLAGS := -Wall -Wextra -Wpedantic -std=c11

# Linker flags
LD_FLAGS := -lm

# Source files
SRC_FILES := main.c $(APP_SRC)

# Build and run by default
default: build run

# Build the application
build:
	@mkdir -p $(BUILD_DIR)
	@$(C_COMPILER) $(SRC_FILES) -o $(TARGET) $(C_FLAGS) $(LD_FLAGS)

# Run the application
run:
	@./$(TARGET)

# Clean the application
clean:
	@rm -rf $(BUILD_DIR)

.PHONY: default build run clean
