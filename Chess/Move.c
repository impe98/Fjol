#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curses.h>
#include <ncurses.h>
#include "ChessPieces.h"
#include "Board.h"
#include "Move.h"

void makeMove(int i, int j, int i2, int j2) {
    board[i2][j2] = board[i][j];
    board[i][j] = 0;
}