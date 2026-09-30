# Project directory
PROJECT_DIR := ml

# Build directory
BUILD_DIR := $(PROJECT_DIR)/build

# Target application
TARGET := $(BUILD_DIR)/linreg_app

# C++ compiler
CXX_COMPILER := g++

# C++ compiler flags
CXX_FLAGS := -Wall -Wextra -Wpedantic -std=c++17 -I$(PROJECT_DIR)/include

# Source files
SRC_FILES := $(PROJECT_DIR)/source/ml/main.cpp \
             $(PROJECT_DIR)/source/ml/lin_reg/fixed.cpp

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
