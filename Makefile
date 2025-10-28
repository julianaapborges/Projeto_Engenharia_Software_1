CXX = g++
CXXFLAGS = -Iinclude -Isrc -Wall -std=c++11

BIN_DIR = bin
SRC_DIR = src
TEST_DIR = test

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
APP_TARGET = $(BIN_DIR)/app.exe
TEST_TARGET = $(BIN_DIR)/testeRegressivo.exe

.PHONY: all test clean

all: $(APP_TARGET)

test: $(TEST_TARGET)

$(APP_TARGET): $(SRC_FILES)
	@mkdir -p $(BIN_DIR) 
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_FILES) $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES))
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(BIN_DIR)/*.exe
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/*.so
	rm -f $(BIN_DIR)/*.dll
	rm -f $(BIN_DIR)/*.a