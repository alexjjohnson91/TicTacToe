# Compiler and Compiler flags
CC = g++
CCFLAGS = -std=c++11 -g

# Directory Paths
SRC_DIR = ./src/
OBJ_DIR = ./build/
INC_DIR = -I ./inc/project

# files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJS = $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(OBJ_FILES))
INC_FILES = $(INC_DIR)/*.hpp

# target and target path
TARGET = main
TARGET_DIR = bin

all: dir $(TARGET)

dir:
	mkdir -p $(TARGET_DIR) $(OBJ_DIR)

run:
	./$(TARGET_DIR)/$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o $(TARGET_DIR)/$(TARGET) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) $(CCFLAGS) -o $@ -c $< $(INC_DIR)

clean:
	rm -rf $(TARGET_DIR) $(OBJ_DIR)
