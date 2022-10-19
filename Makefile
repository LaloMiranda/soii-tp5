CC=gcc
CFLAGS= -g -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11

all: clean server

server: serverFuncs
	$(CC) $(CFLAGS) ./obj/serverFuncs.o  ./src/server.c  -lulfius -o ./bin/server.out

serverFuncs:
	$(CC) $(CFLAGS) -c ./src/serverFuncs.c -o ./obj/serverFuncs.o

clean:
	rm -f ./bin/*
	rm -f ./obj/*

run: all
	./bin/server.out
