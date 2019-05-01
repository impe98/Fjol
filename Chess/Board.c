#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curses.h>
#include <ncurses.h>
#include "ChessPieces.h"
#include "Board.h"
#include "Move.h"

void createBoard() { //Create the board to later fill with chessPieces
    for (int i = 0; i < 32; i++) {
        insertPiece(i);
    }
    for (int i = 0; i < 8; i++) { //Make empty squares none-null
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == NULL) {
                board[i][j] = 0;
            }
        }
    }
}

void insertPiece(int i) { //Inserts pieces onto the board at the start of the game
    if (i < 0) { //Illegal piece
        printf("None-legal piece inserted");
    }
    else if (i < 8) { //White Pawn
        board[6][i] = chessPieces[i];
    }
    else if (i >= 8 && i < 16) { //Black Pawn
        board[1][i-8] = chessPieces[i];
    }
    else if (i >= 16 && i < 18) { //White Rook
        board[7][0] = chessPieces[i];
        board[7][7] = chessPieces[i]; 
    }
    else if (i >= 18 && i < 20) { //Black Rook 
        board[0][0] = chessPieces[i];
        board[0][7] = chessPieces[i];
    }
    else if (i >= 20 && i < 22) { //White Bishop
        board[7][2] = chessPieces[i];
        board[7][5] = chessPieces[i];
    }
    else if (i >= 22 && i < 24) { //Black Bishop
        board[0][2] = chessPieces[i];
        board[0][5] = chessPieces[i];
    }
    else if (i >= 24 && i < 26) {//White Knight
        board[7][1] = chessPieces[i];
        board[7][6] = chessPieces[i];
    }
    else if (i >= 26 && i < 28) {//Black Knight
        board[0][1] = chessPieces[i];
        board[0][6] = chessPieces[i];
    }
    else if (i >= 28 && i < 29) {//White King
        board[7][4] = chessPieces[i];
    }
    else if (i >= 29 && i < 30) {//Black King
        board[0][4] = chessPieces[i];
    }
    else if (i >= 30 && i < 31) {//White Queen
        board[7][3] = chessPieces[i];
    }
    else if (i >= 31 && i < 32) {//Black Queen
        board[0][3] = chessPieces[i];
    }
    else {
        printf("None-legal piece inserted");
    }
}

void printRow(int i) { //Print each row of the board
    for (int k = 0; k < 11; k++) {
        printf("___");
    }
    printf("\n");
    for (int j = 0; j < 8; j++) {
        if (board[i][j] != 0) { //Print the character representing each piece on each inhabited square  
            printf("| %c ", board[i][j]->block); 
        }
        else {
            printf("|   ");
        }
    }
    printf("|");
    printf("\n");
    for (int l = 0; l < 8; l++) {
        printf("|___");
    }
    printf("|");
}

void printBoard() { //print entire board by calling the printRow function eight times
   for (int i = 0; i < 8; i++) {
       printRow(i);
       printf("\n");
   }
}