CC=g++
DEBUG = -g
CFLAGS= -Wall -c 
LFLAGS = -Wall $(DEBUG)
OBJ= ll.cpp
EXE= ll

all:
	$(CC) -o $(EXE) $(OBJ) 

check:
	valgrind --leak-check=yes ./ll

run:
	./ll
