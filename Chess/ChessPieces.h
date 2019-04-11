#include <stdio.h>
#include <stdlib.h>
//Initialize Chess Pieces

void chessPiecesWhitePawn();
void chessPiecesBlackPawn();
void chessPiecesWhiteRook();
void chessPiecesBlackRook();
void chessPiecesWhiteKnight();
void chessPiecesBlackKnight();
void chessPiecesWhiteBishop();
void chessPiecesBlackBishop();
void chessPiecesWhiteQueen();
void chessPiecesBlackQueen();
void chessPiecesWhiteKing();
void chessPiecesBlackKing();
void chessPiecesArray();
typedef struct
{
    char* pieceName;
    bool alive;
    bool black;
    char block;
}chessPiece;

chessPiece* chessPieces[32];
