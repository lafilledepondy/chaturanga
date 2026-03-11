CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
CPPFLAGS = -MMD -MP
TARGET = main
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
SOURCES = $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
INCLUDE_FLAGS = -I$(SRC_DIR)

ifeq ($(wildcard $(INCLUDE_DIR)), $(INCLUDE_DIR))
INCLUDE_FLAGS += -I$(INCLUDE_DIR)
endif

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Rebuild everything
rebuild: clean all

# Google Test configuration
TEST_SOURCES = $(shell find tests -name '*.cpp')
TEST_MAIN_OBJ = $(BUILD_DIR)/main_test.o
OTHER_TEST_SOURCES = $(filter-out tests/main_test.cpp,$(TEST_SOURCES))
OTHER_TEST_OBJECTS = $(patsubst tests/%.cpp,$(BUILD_DIR)/%_test.o,$(OTHER_TEST_SOURCES))
TEST_OBJECTS = $(TEST_MAIN_OBJ) $(OTHER_TEST_OBJECTS)
TEST_TARGET = run_tests
GTEST_FLAGS = -lgtest -pthread
# Exclude main.o from test build to avoid multiple definition of main
TEST_LINK_OBJECTS = $(filter-out $(BUILD_DIR)/main.o,$(OBJECTS))

# Build and run tests
test: $(TARGET) $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_LINK_OBJECTS) $(TEST_OBJECTS) $(GTEST_FLAGS)
	./$(TEST_TARGET)

# Compile main_test.cpp
$(BUILD_DIR)/main_test.o: tests/main_test.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

# Compile other test files
$(BUILD_DIR)/%_test.o: tests/%.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

DEPS = $(OBJECTS:.o=.d)

-include $(DEPS)

.PHONY: all run clean rebuild test
