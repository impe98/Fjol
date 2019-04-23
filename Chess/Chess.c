#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ChessPieces.h"
#include "Board.h"

//TODO: How to handle empty squares? Currently: Empty squares are 0 
//TODO: Newline for each square - potential solution to make each row instead?

// Free everything once done (split into several functions as to free along the way?)
void freeStuff() {
    for (int i = 0; i < 32; i++) {
        free(chessPieces[i]);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            free(board[i][j]);
        }
    }
}

//Main game-loop
int main(int argc, char** argv) {
    chessPiecesInit();//Create collection of pieces
    chessPiecesArray(); //Create Collection of Pieces
    for (int i = 0; i < 32; i++) {//Create Board filled with pieces.
        createBoard(board);       // This board will be modified throughout the game
    }
    printBoard();
    freeStuff();
    printf("\n");
    return 0;
}