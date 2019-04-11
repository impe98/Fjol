#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ChessPieces.h>

void chessPiecesWhitePawn() {
    for (int i = 0; i < 8; i++) {
        chessPieces[i]->pieceName = "Pawn";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = false;
        chessPieces[i]->block = 'p';
    }
}
void chessPiecesBlackPawn() {
    for (int i = 8; i < 16; i++) {
        chessPieces[i]->pieceName = "Pawn";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = true;
        chessPieces[i]->block = 'P';
    }
}
void chessPiecesWhiteRook() {
    for (int i = 16; i < 18; i++) {
        chessPieces[i]->pieceName = "Rook";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = false;
        chessPieces[i]->block = 'r';
    }
}
void chessPiecesBlackRook() {
    for (int i = 18; i < 20; i++) {
        chessPieces[i]->pieceName = "Rook";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = true;
        chessPieces[i]->block = 'R';
    }
}

void chessPiecesWhiteKnight() {
    for (int i = 20; i < 22; i++) {
        chessPieces[i]->pieceName = "Knight";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = false;
        chessPieces[i]->block = 'k';
    }
}

void chessPiecesBlackKnight() {
    for (int i = 22; i < 24; i++) {
        chessPieces[i]->pieceName = "Knight";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = true;
        chessPieces[i]->block = 'K';
    }
}

void chessPiecesWhiteBishop() {
    for (int i = 24; i < 26; i++) {
        chessPieces[i]->pieceName = "Bishop";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = false;
        chessPieces[i]->block = 'b';
    }
}

void chessPiecesBlackBishop() {
    for (int i = 26; i < 28; i++) {
        chessPieces[i]->pieceName = "Bishop";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = true;
        chessPieces[i]->block = 'B';
    }
}

void chessPiecesWhiteKing() {
    for (int i = 28; i < 29; i++) {
        chessPieces[i]->pieceName = "King";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = false;
        chessPieces[i]->block = 't';
    }
}

void chessPiecesBlackKing() {
    for (int i = 29; i < 30; i++) {
        chessPieces[i]->pieceName = "King";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = true;
        chessPieces[i]->block = 'T';
    }
}

void chessPiecesWhiteQueen() {
    for (int i = 30; i < 31; i++) {
        chessPieces[i]->pieceName = "Queen";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = false;
        chessPieces[i]->block = 'q';
    }
}

void chessPiecesBlackQueen() {
    for (int i = 31; i < 32; i++) {
        chessPieces[i]->pieceName = "Queen";
        chessPieces[i]->alive = true;
        chessPieces[i]->black = true;
        chessPieces[i]->block = 'Q';
    }
}

void chessPiecesArray() {
    chessPiecesWhitePawn;
    chessPiecesBlackPawn;
    chessPiecesWhiteRook;
    chessPiecesBlackRook;
    chessPiecesWhiteBishop;
    chessPiecesBlackBishop;
    chessPiecesWhiteKnight;
    chessPiecesBlackKnight;
    chessPiecesWhiteQueen;
    chessPiecesBlackQueen;
    chessPiecesWhiteKing;
    chessPiecesBlackKing;
}
