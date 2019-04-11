#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ChessPieces.h"


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

void chessPiecesInit() {
    for (int i = 0; i < 32; i++) {
        chessPieces[i] = malloc(sizeof(struct chessPiece));
    }
}

void chessPiecesArray() {
    for (int i = 0; i < 8; i++) {
        chessPieces[i] = chessPiecesCreate("Pawn", 'p', i, "White");
    }
    for (int i = 8; i < 16; i++) {
        chessPieces[i] = chessPiecesCreate("Pawn", 'P', i, "Black");
    }
    for (int i = 16; i < 18; i++) {
       chessPieces[i] = chessPiecesCreate("Rook", 'r', i, "White");
    }
    for (int i = 18; i < 20; i++) {
        chessPieces[i] = chessPiecesCreate("Rook", 'R', i, "Black");
    }
    for (int i = 20; i < 22; i++) {
        chessPieces[i] = chessPiecesCreate("Bishop", 'b', i, "White");
    }
    for (int i = 22; i < 24; i++) {
        chessPieces[i] = chessPiecesCreate("Bishop", 'B', i, "Black");
    }
    for (int i = 24; i < 26; i++) {
        chessPieces[i] = chessPiecesCreate("Knight", 'k', i, "White");
    }
    for (int i = 26; i < 28; i++) {
        chessPieces[i] = chessPiecesCreate("Knight", 'K', i, "Black");
    }
    for (int i = 28; i < 29; i++) {
        chessPieces[i] = chessPiecesCreate("King", 't', i, "White");
    }
    for (int i = 29; i < 30; i++) {
        chessPieces[i] = chessPiecesCreate("King", 'T', i, "Black");
    }
    for (int i = 30; i < 31; i++) {
        chessPieces[i] = chessPiecesCreate("Queen", 'q', i, "White");
    }
    for (int i = 31; i < 32; i++) {
        chessPieces[i] = chessPiecesCreate("Queen", 'Q', i, "Queen");
    }
}
