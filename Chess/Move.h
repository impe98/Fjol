#ifndef MOVE_H
#define MOVE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curses.h>
#include <ncurses.h>

void makeMove(int i, int j, int i2, int j2);
bool legalPieceMove(int i0, int j0, int i1, int j1);
bool legalMovePawn(int i0, int j0, int i1, int j1);
bool callLegalFunction(int r0, int c0, int r1, int c1);
int getMove();

#endif