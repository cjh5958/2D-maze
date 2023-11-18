#file path
DIR = ./
SRCP = $(DIR)engine/src

#compiler config
CC = g++ -w -std=c++14
CFLAGS = -I/usr/local/include/SDL2 -D_THREAD_SAFE
LIBS = -L/usr/local/lib -lSDL2

.PHONY: all clean run
all: main clean run

main: main.o cfg.o logger.o Timer.o Vector2.o error_list.o error_macro.o Application.o
	$(CC) $(CFLAGS) $(LIBS) main.o Application.o cfg.o logger.o Timer.o Vector2.o error_list.o error_macro.o -o main

main.o : main.cpp engine/Engine.h
	$(CC) $(CFLAGS) $(LIBS) -c $(DIR)main.cpp
Application.o: $(SRCP)/Application.cpp $(SRCP)/Application.h $(SRCP)/cfg.h $(SRCP)/setup.h $(SRCP)/utility/utility.h $(SRCP)/utility/Timer.h $(SRCP)/utility/logger.h $(SRCP)/core/error/error_list.h
	$(CC) $(CFLAGS) $(LIBS) -c $(SRCP)/Application.cpp
cfg.o: $(SRCP)/cfg.cpp $(SRCP)/cfg.h $(SRCP)/core/error/error_list.h
	$(CC) $(CFLAGS) $(LIBS) -c $(SRCP)/cfg.cpp
logger.o: $(SRCP)/utility/logger.cpp $(SRCP)/utility/logger.h
	$(CC) $(CFLAGS) $(LIBS) -c $(SRCP)/utility/logger.cpp
Timer.o : $(SRCP)/utility/Timer.cpp $(SRCP)/utility/Timer.h
	$(CC) $(CFLAGS) $(LIBS) -c $(SRCP)/utility/Timer.cpp
Vector2.o: $(SRCP)/core/math/Vector2.cpp $(SRCP)/core/math/Vector2.h $(SRCP)/core/math/func.h $(SRCP)/core/error/error.h
	$(CC) $(CFLAGS) $(LIBS) -c $(SRCP)/core/math/Vector2.cpp
error_list.o: $(SRCP)/core/error/error_list.cpp $(SRCP)/core/error/error_list.h
	$(CC) $(CFLAGS) $(LIBS) -c $(SRCP)/core/error/error_list.cpp
error_macro.o: $(SRCP)/core/error/error_macro.cpp $(SRCP)/core/error/error_macro.h
	$(CC) $(CFLAGS) $(LIBS) -c $(SRCP)/core/error/error_macro.cpp

clean:
	rm -rf *.o
run:
	./main