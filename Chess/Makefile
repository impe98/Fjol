CC = gcc
CFLAGS =-Wall -Wextra -pedantic -g -O0 -std=gnu11 -ggdb
DEPS = ChessPieces.h Board.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Chess: Chess.c ChessPieces.c
	$(CC) -o Chess Chess.c ChessPieces.c Board.c
