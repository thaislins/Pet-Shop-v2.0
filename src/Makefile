#Makefile for "	Cadastro de Animais em um Petshop" C++ application
#Created by Thais Lins 28/10/2016

PROG = petfera
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11
OBJS = main.o funcionario.o animal.o op.o

all: petfera exportar

exportar: exportar.o funcionario.o animal.o op.o
	$(CC) exportar.o funcionario.o animal.o op.o -o ../bin/ex

petfera: main.o funcionario.o animal.o op.o
	$(CC) main.o funcionario.o animal.o op.o -o ../bin/pf

exportar.o: exportar.cpp
	$(CC) $(CPPFLAGS) -c exportar.cpp

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

op.o:   op.cpp
	$(CC) $(CPPFLAGS) -c op.cpp

funcionario.o: funcionario.cpp
	       $(CC) $(CPPFLAGS) -c funcionario.cpp

animal.o: animal.cpp
	  $(CC) $(CPPFLAGS) -c animal.cpp

clean:
	rm -rf *o $(OBJS) 	



