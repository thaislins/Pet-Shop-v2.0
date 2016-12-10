#Makefile for "	Cadastro de Animais em um Petshop" C++ application
#Created by Thais Lins 28/10/2016

INC_DIR = include
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib

CC      = g++
CFLAGS  = -Wall -pedantic -std=c++11 -ansi -I. -I$(INC_DIR)
ARCHIVE	= ar

linux: petfera.so prog_dinamico

windows: minhalib.lib minhalib.dll prog_estatico.exe prog_dinamico.exe

# LINUX

petfera.so: $(SRC_DIR)/main.cpp $(SRC_DIR)/animal.cpp $(SRC_DIR)/funcionario.cpp $(SRC_DIR)/op.cpp $(INC_DIR)/animal.h $(INC_DIR)/funcionario.h $(INC_DIR)/op.h $(INC_DIR)/ex.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/animal.cpp -o $(OBJ_DIR)/animal.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/funcionario.cpp -o $(OBJ_DIR)/funcionario.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/op.cpp -o $(OBJ_DIR)/op.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/main.o $(OBJ_DIR)/animal.o $(OBJ_DIR)/funcionario.o $(OBJ_DIR)/op.o 
	@echo "+++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

prog_dinamico:
	$(CC) $(CFLAGS) $(SRC_DIR)/exportar.cpp -L$(LIB_DIR) $(LIB_DIR)/petfera.so -o $(OBJ_DIR)/$@ 

# WINDOWS

petfera.dll: $(SRC_DIR)/animal.cpp $(SRC_DIR)/funcionario.cpp $(SRC_DIR)/op.cpp $(INC_DIR)/animal.h $(INC_DIR)/ex.h $(INC_DIR)/funcionario.h $(INC_DIR)/op.h  
	$(CC) $(CFLAGS) -c $(SRC_DIR)/animal.cpp -o $(OBJ_DIR)/animal.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/funcionario.cpp -o $(OBJ_DIR)/funcionario.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/op.cpp -o $(OBJ_DIR)/op.o
	$(CC) -shared -o $(LIB_DIR)/$@ $(OBJ_DIR)/animal.o $(OBJ_DIR)/funcionario.o $(OBJ_DIR)/op.o 
	@echo "+++ [Biblioteca dinamica criada em $(LIB_DIR)/$@] +++"

pf.exe:
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(LIB_DIR)/petfera.dll -o $(OBJ_DIR)/$@ 	

clean:
	@rm -rf $(OBJ_DIR)/* 	



