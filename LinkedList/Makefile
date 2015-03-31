CC=g++
DEBUG = -g
CFLAGS= -Wall -c 
LFLAGS = -Wall $(DEBUG)
OBJ= classll.cpp
EXE= classll

all:
	$(CC) -o $(EXE) $(OBJ) 

check:
	valgrind --leak-check=yes ./$(EXE)

run:
	./$(EXE)
