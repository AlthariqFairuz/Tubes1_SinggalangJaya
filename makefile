# Makefile for C++ project with source files in src/ directory

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

# Directories
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin

# Get all .cpp files recursively
SRCS := $(shell find $(SRCDIR) -name '*.cpp')

# Generate corresponding object file paths
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

# Main target
all: $(OBJS)
	@mkdir -p $(TARGETDIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGETDIR)/my_program

# Compilation rule for object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(BUILDDIR) $(TARGETDIR)


# Phony targets
.PHONY: all clean
