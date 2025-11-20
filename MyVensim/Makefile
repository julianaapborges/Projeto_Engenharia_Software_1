CXX = g++
CXXFLAGS = -Iinclude -Isrc -Wall -std=c++11

BIN_DIR = bin
SRC_DIR = src
TEST_DIR = test
FUNC_DIR = $(TEST_DIR)/funcional
UNIT_DIR = $(TEST_DIR)/unit

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRCS_NO_MAIN = $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES))
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
FUNC_FILES = $(wildcard $(FUNC_DIR)/*.cpp)
UNIT_FILES = $(wildcard $(UNIT_DIR)/*.cpp)

APP_TARGET = $(BIN_DIR)/app.exe
TEST_TARGET = $(BIN_DIR)/testeRegressivo.exe
FUNC_TARGET = $(BIN_DIR)/testeFuncional.exe
UNIT_TARGET = $(BIN_DIR)/testeUnitario.exe

.PHONY: all test func unit test-all clean

all: $(APP_TARGET)

test: $(TEST_TARGET)

func: $(FUNC_TARGET)
	@echo "Executando testes funcionais..."
	@./$(FUNC_TARGET)

unit: $(UNIT_TARGET)

test-all: test func unit

$(APP_TARGET): $(SRC_FILES)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_FILES) $(SRCS_NO_MAIN)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(FUNC_TARGET): $(FUNC_FILES) $(SRCS_NO_MAIN)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(UNIT_TARGET): $(UNIT_FILES) $(SRCS_NO_MAIN)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(BIN_DIR)/*.exe
	rm -f $(BIN_DIR)/*.o
	rm -f $(BIN_DIR)/*.so
	rm -f $(BIN_DIR)/*.dll
	rm -f $(BIN_DIR)/*.a