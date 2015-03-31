CC=g++
DEBUG = -g
CFLAGS= -Wall -c 
LFLAGS = -Wall $(DEBUG)
OBJ= tree.cpp
EXE= tree

all:
	$(CC) -o $(EXE) $(OBJ) 

check:
	valgrind --leak-check=yes ./$(EXE)

run:
	./$(EXE)
