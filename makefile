CC = gcc
CFLAGS = -Wall -Wextra

.PHONY: all clean

.INTERMEDIATE: main.o stack.o

all: main

main: main.o stack.o
	  $(CC) $(CFLAGS) -o main main.o stack.o

main.o: main.c ./stack/stack.h
	  $(CC) $(CFLAGS) -c -o main.o main.c

stack.o: ./stack/stack.c ./stack/stack.h
	  $(CC) $(CFLAGS) -c -o stack.o ./stack/stack.c

clean:
	  rm -f main main.o stack.o