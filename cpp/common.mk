# Shared build settings, included by each application's Makefile.
# Each application must set APP_NAME, and may set APP_SRC for extra sources.

# Path to the ml directory (where this file is located)
ML_DIR := $(patsubst %/,%,$(dir $(lastword $(MAKEFILE_LIST))))

# Build directory
BUILD_DIR := build

# Target application
TARGET := $(BUILD_DIR)/$(APP_NAME)

# C++ compiler
CXX_COMPILER := g++

# C++ compiler flags
CXX_FLAGS := -Wall -Wextra -Wpedantic -std=c++17 -I$(ML_DIR)/include

# Source files
SRC_FILES := main.cpp $(APP_SRC)

# Build and run by default
default: build run

# Build the application
build:
	@mkdir -p $(BUILD_DIR)
	@$(CXX_COMPILER) $(SRC_FILES) -o $(TARGET) $(CXX_FLAGS)

# Run the application
run:
	@./$(TARGET)

# Clean the application
clean:
	@rm -rf $(BUILD_DIR)

.PHONY: default build run clean
