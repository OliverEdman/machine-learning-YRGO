# Target application
TARGET := build/linreg_app

# C++ compiler
CXX_COMPILER := g++

# C++ compiler flags
CXX_FLAGS := -Wall -Wextra -Wpedantic -std=c++17 -Iinclude

# Source files (pekar på rätt ställen i ditt träd)
SRC_FILES := source/ml/main.cpp \
             source/ml/lin_reg/fixed.cpp

# Build and run by default
default: build run

# Build the application
build:
	@mkdir -p build/ml/lin_reg
	@$(CXX_COMPILER) $(SRC_FILES) -o $(TARGET) $(CXX_FLAGS)

# Run the application
run:
	@./$(TARGET)

# Clean the application
clean:
	@rm -rf build

.PHONY: default build run clean
