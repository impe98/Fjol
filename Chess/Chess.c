#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <curses.h>
#include <ncurses.h>
#include "ChessPieces.h"
#include "Board.h"
#include "Move.h"
//TODO: How to handle empty squares? Currently: Empty squares are 0 
//TODO: getMove only accepts two inputs (newline is perhaps seen as input?)
//TODO: Ensure only legal moves be accepted 
//TODO: Clean up all dependencies
//TODO: Find way to represent color of 

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

int getMove() { //Get the coordinates for piece to move and to where
    int i0 = getchar();
    int j0 = getchar();
    int i1 = getchar();
    int j1 = getchar();
    return i0, j0, i1, j1;
}

//Main game-loop
int main(int argc, char** argv) {
    int i0, j0, i1, j1;
    bool play = true; //Bool which determines when the game is done
    chessPiecesInit();//Create collection of pieces
    chessPiecesArray(); //Create Collection of Pieces
    for (int i = 0; i < 32; i++) {//Create Board filled with pieces.
        createBoard(board);       // This board will be modified throughout the game
    }
    while (play) {
        printBoard(); //Print the board after each move
        printf("\n"); //Newline to distinguish each board from the last
        getMove(); //Get the coordinates for each move 
    }
    return 0;
}