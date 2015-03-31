CC=g++
DEBUG = -g
CFLAGS= -Wall -c 
LFLAGS = -Wall $(DEBUG)
OBJ= stack.cpp
EXE= stack

all:
	$(CC) -o $(EXE) $(OBJ) 

check:
	valgrind --leak-check=yes ./$(EXE)

run:
	./$(EXE)
