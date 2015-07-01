CC=g++
DEBUG = -g
CFLAGS= -Wall -c 
LFLAGS = -Wall -std=c++11 $(DEBUG)
OBJ= vector.cpp
EXE= vector

all:
	$(CC) $(LFLAGS) -o $(EXE) $(OBJ) 

check:
	valgrind --leak-check=yes ./$(EXE)

run:
	./$(EXE)
