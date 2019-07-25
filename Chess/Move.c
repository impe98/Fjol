#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curses.h>
#include <ncurses.h>
#include "ChessPieces.h"
#include "Board.h"
#include "Move.h"
#include "Chess.h"

//Make the move on the board
void makeMove(int i, int j, int i2, int j2) {
    board[i2][j2] = board[i][j];
    board[i][j] = 0;
}

//Get the coordinates for piece to move and to where
int getMove() { 
    int r0,c0,r1,c1;
    do {
        scanf(" %d", &r0);
        scanf(" %d", &c0);
        scanf(" %d", &r1);
        scanf(" %d", &c1);
    } 
    while (legalPieceMove(r0, c0, r1, c1) == false); //Redo move when illegal 
    makeMove(r0,c0,r1,c1); //Perform legal move
    return 0;
}
//Function to determine if a move is legal or not for the piece in question 
bool legalPieceMove(int r0, int c0, int r1, int c1) {
    bool isLegal = false;
    if (board[r0][c0] == 0) {
        return false; 
    }
    char* name = board[r0][c0]->pieceName;
    if (name == "Pawn") {
        isLegal = legalMovePawn(r0, c0, r1, c1);
    }
    return isLegal;
}
//Determines legality of move made by pawn
bool legalMovePawn(int r0, int c0, int r1, int c1) {
    //Pawn moves one step forward
    if ((r1 == (r0+1) || r1 == (r0-1)) && c0 == c1) {
        printf("First");
        return true;
    }
    //Pawn moves two steps forward, only legal in first turn
    else if ((r1 == (r0+2) || r1 == (r0-2)) && c0 == c1 && (r0 == 1 && r1 == 6)) {
        printf("Second");
        return true;
    }    
    //Pawn moves diagonal if opponent is present 
    else if (r1 == (r0+1) && c1 == (c0+1) && board[r1][c1] != 0 && board[r0][c0]->colour != board[r1][c1]->colour) {
        printf("Third");
        return true;
    }
    else {
        printf("Fourth");
        return false;
    }
}