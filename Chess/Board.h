#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createBoard();
void insertPiece(int i);
void printBoard();
void printSquare();

struct chessPiece *board[8][8];

#endif 