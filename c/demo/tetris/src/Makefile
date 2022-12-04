CC := gcc
INCLUDE_DIR := -I ../include
OBJ_DIR := $(shell pwd)/obj
BIN_DIR := $(shell pwd)/bin

SUB_DIR := main user global obj

TARGET := tetris

export CC INCLUDE_DIR OBJ_DIR BIN_DIR SUB_DIR TARGET

all : $(SUB_DIR)

$(SUB_DIR) : MK_BIN
	make -C $@

MK_BIN : 
	mkdir -p $(BIN_DIR)

clean :
	rm -rf $(BIN_DIR) $(OBJ_DIR)/*.o

