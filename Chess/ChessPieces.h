#ifndef CHESSPIECES_H
#define CHESSPIECES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initialize Chess Pieces
struct chessPiece *chessPiecesCreate(char* name, char block, int i, char* colour);
void chessPiecesArray();
void chessPiecesInit();

struct chessPiece
{
    char* pieceName;
    bool alive;
    char* colour;
    char block;
}chessPiece;

struct chessPiece *chessPieces[32];

#endif
