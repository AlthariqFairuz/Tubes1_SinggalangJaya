# Define compiler and flags (adjust as needed)
CXX = g++
CXXFLAGS = -Wall -std=c++17
# CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -O2 -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector

# Define object file directory (optional, avoids conflicts)
OBJDIR = obj

# Pattern for finding all source files
CPP_SOURCES = $(shell find src -name "*.cpp")

# Define object files based on source files
OBJECTS = $(CPP_SOURCES:src/%.cpp=$(OBJDIR)/%.o)

# Executable name (change as needed)
EXECUTABLE = main

# Main target (executable)
all: $(EXECUTABLE)

# Link object files into executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Compile individual source files to object files
$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(@D)  # Create object directory if it doesn't exist
	$(CXX) -c $(CXXFLAGS) -o $@ $<

# Clean target to remove all object files
clean:
	rm -rf $(OBJECTS) $(OBJDIR)
