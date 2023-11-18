DIR = ./
OBJS = main.cpp 
CC = g++
CFLAGS = -w -std=c++14
INCPATH = -I /usr/local/Cellar/sdl2/2.26.4/include
LIBS = -L /usr/local/Cellar/sdl2/2.26.4/lib
LINKER_FLAGS = -lSDL2main -lSDL2
OBJ_NAME = -o maze

all:
	$(CC) $(CFLAGS) $(INCPATH) $(LINKER_FLAGS) $(LIBS) $(OBJ_NAME) $(OBJS)