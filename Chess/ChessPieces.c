#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ChessPieces.h"
#include "Board.h"
#include "Move.h"
#include <curses.h>
#include <ncurses.h>

// Insert Chesspiece into collection of chesspieces
struct chessPiece *chessPiecesCreate(char *name, char block, int i, char* colour) {
    struct chessPiece *piece = malloc(sizeof(struct chessPiece));
    piece->pieceName = malloc(strlen(name)+1);
    strcpy(piece->pieceName, name);
    piece->alive = true;
    piece->colour = malloc(strlen(colour)+1);
    strcpy(piece->colour, colour);
    piece->block = block;
    return piece;
}

//Initialize collection of chesspieces
void chessPiecesInit() {
    for (int i = 0; i < 32; i++) {
        chessPieces[i] = malloc(sizeof(struct chessPiece));
    }
}

//Fill up collection of chesspieces 
void chessPiecesArray() {
    for (int i = 0; i < 8; i++) {//Insert White Pawns
        chessPieces[i] = chessPiecesCreate("Pawn", 'l', i, "White");
    }
    for (int i = 8; i < 16; i++) {//Insert Black Pawns
        chessPieces[i] = chessPiecesCreate("Pawn", 'L', i, "Black");
    }
    for (int i = 16; i < 18; i++) {//Insert White Rooks
       chessPieces[i] = chessPiecesCreate("Rook", 'r', i, "White");
    }
    for (int i = 18; i < 20; i++) {//Insert Black Rooks
        chessPieces[i] = chessPiecesCreate("Rook", 'R', i, "Black");
    }
    for (int i = 20; i < 22; i++) {//Insert White Bishops
        chessPieces[i] = chessPiecesCreate("Bishop", 'b', i, "White");
    }
    for (int i = 22; i < 24; i++) {//Insert Black BIshops
        chessPieces[i] = chessPiecesCreate("Bishop", 'B', i, "Black");
    }
    for (int i = 24; i < 26; i++) {//Insert White Knight
        chessPieces[i] = chessPiecesCreate("Knight", 'k', i, "White");
    }
    for (int i = 26; i < 28; i++) {//Insert Black Knight
        chessPieces[i] = chessPiecesCreate("Knight", 'K', i, "Black");
    }
    for (int i = 28; i < 29; i++) {//Insert White King
        chessPieces[i] = chessPiecesCreate("King", 't', i, "White");
    }
    for (int i = 29; i < 30; i++) {//Insert Black King
        chessPieces[i] = chessPiecesCreate("King", 'T', i, "Black");
    }
    for (int i = 30; i < 31; i++) {//Insert White Queen
        chessPieces[i] = chessPiecesCreate("Queen", 'q', i, "White");
    }
    for (int i = 31; i < 32; i++) {//Insert Black Queen
        chessPieces[i] = chessPiecesCreate("Queen", 'Q', i, "Queen");
    }
}
