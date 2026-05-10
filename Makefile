SRC_DIR = ./src
H_DIR = ./includes
BUILD_DIR = ./build

C_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_FILES))

OPT_LIB = -lSDL2 -lm -Wall

all: $(OBJ_FILES)
	gcc -o $(BUILD_DIR)/main $(OBJ_FILES) $(OPT_LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	gcc -c $< -o $@

clean:
	rm -rf ./build
	mkdir ./build

run: all
	./build/main

.SILENT:
.PHONY: all clean run
