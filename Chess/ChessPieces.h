#ifndef CHESSPIECES_H
#define CHESSPIECES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initialize Chess Pieces
struct chessPiece *chessPiecesCreate(char* name, char block, int i, char* colour);
void chessPiecesArray();
void chessPiecesInit();

//Create Chess Piece Struct
struct chessPiece
{
    char* pieceName;
    bool alive;
    char* colour;
    char block;
}chessPiece;

//Collection of Chess pieces
struct chessPiece *chessPieces[32];

#endif
