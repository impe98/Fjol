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

//TODO: Function to determine name of chosen piece. Name to be used in "legalPieceMove"
//TODO: Define macros as to make function calls more manageable
//TODO: Maybe have function "blocked" which calls specific blocked-functions?
//TODO: Find better way to check for blocking opponents. Seriously; it's embarrasing. 
//TODO: Pawns can't move backwards - ensure this. 

//Macro to make standard message for opponent being blocked
#define BLOCKEDMESSAGE "Illegal move - you're being blocked!"
#define FRIENDOCC "Friendly piece occupies space you're attempting to move to!"
//Make the move on the board
void makeMove(int r0, int c0, int r1, int c1) {
    board[r1][c1] = board[r0][c0];
    board[r0][c0] = 0; //Make tile being moved from empty
}
//Function to determine if the tile being moved to is empty
//returns true if empty; false if not
bool empty(int r1, int c1) {
    if (board[r1][c1] == 0) {
        return true;
    }
    return false;
}

//Function to determine if tile being moved to is an opponent
//Short-circuting (evaluating empty() first) ensures no segmentation fault
//Returns true if an opponent is on the tile being moved to
bool opponent(int r0, int c0, int r1, int c1) {
    if ((!empty(r1, c1)) && strcmp(board[r0][c0]->colour, board[r1][c1]->colour) != 0) { //Different colour between tile being moved from and to or tile is empty
        return true;
    }
    return false;
}

//Function to determine if the tile being moved to is occupied by ones own piece
bool friend(int r0, int c0, int r1, int c1) {
    if (board[r0][c0]->colour == board[r1][c1]->colour) {
        return true;
    }
    return false; 
}
//Check if move made with pawn is blocked
bool blockedPawn(int r0, int c0, int r1, int c1) {
    if (r0 < r1) { //Pawn moves down. Check for blocking opponent
        if (!empty((r0+1), c1)) {
            printf("%s\n", BLOCKEDMESSAGE);
            return true; 
        }
    }
    else if (!empty((r0-1), c1)) { //Pawn moves up. Check for blocking opponent 
        printf("%s\n", BLOCKEDMESSAGE);
        return true; 
    }
    return false; //No blocking opponent
}

//Check if move made by rook is blocked
bool blockedRook(int r0, int c0, int r1, int c1) {
    if (r0 == r1) { //Rook moves on same row
        if (c0 < c1)  { //Rook moves right; check tiles on the right
            for (int i = c0+1; i < c1; i++) {
                if (!empty(r1, i)) { //Opponent on distance travelled found
                    printf("%s\n", BLOCKEDMESSAGE);
                    return true; 
                }
            }
        }
        else { //Rook moves left
            for (int i = c0-1; i > c1; i--) {
                if (!empty(r1, i)) {
                    printf("%s\n", BLOCKEDMESSAGE);
                    return true;
                }
            }
        }
    }
    else {
        printf("rows: %d, %d", r0, r1);
        if (r0 < r1)  { //Rook moves down; check tiles downwards
            for (int i = r0+1; i < r1; i++) {
                if (!empty(i, c1)) { //Opponent on distance travelled found
                    printf("Here %s\n", BLOCKEDMESSAGE);
                    printf("i is: %d", i);
                    return true; 
                }
            }
        }
        else { //Rook moves up; check tiles upwards
            for (int i = r0-1; i > r1; i--) {
                if (!empty(i, c1)) {
                    printf("%s\n", BLOCKEDMESSAGE);
                    return true;
                }
            }
        }
    }
    return false; //not blocked
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
    while (!legalPieceMove(r0, c0, r1, c1)); //Redo move when illegal 
    makeMove(r0,c0,r1,c1); //Perform legal move
    return 0;
}
//Function to determine if a move is legal or not for the piece in question 
//Returns true if legal, false if not
bool legalPieceMove(int r0, int c0, int r1, int c1) {
    if (board[r0][c0] == 0) { //Determines if piece exist on selected tile
        printf("No piece on that tile!\n");
        return false; 
    }
    else if ((r1 < 0 || r1 > 7) || (c1 < 0 || c1 > 7)) { //Ensure piece doesn't move off board
        printf("Can't move piece off board!\n");
        return false; 
    }
    return callLegalFunction(r0, c0, r1, c1);
}

// Call the correct legality-function
bool callLegalFunction(int r0, int c0, int r1, int c1) {
    char* name = board[r0][c0]->pieceName; //Get name of piece
    if (strcmp(name, "Pawn") == 0) {
        printf("Recognizes name\n");
        return legalMovePawn(r0, c0, r1, c1);
    }
    else if (strcmp(name, "Rook") == 0) {
        return legalMoveRook(r0, c0, r1, c1);
    }
    return false; //Should not happen. Name of piece would not be recognized
}
//Determines legality of move made by pawn
//Returns true if legal; false if not. 
bool legalMovePawn(int r0, int c0, int r1, int c1) {
    //Pawn moves one step forward
    if ((r1 == (r0+1) || r1 == (r0-1)) && c0 == c1 && empty(r1, c1)) {
        return true;
    }
    //Pawn moves two steps forward, only legal as first movement
    else if ((r1 == (r0+2) || r1 == (r0-2)) && c0 == c1 && (r0 == 1 || r0 == 6) && empty(r1, c1) && !blockedPawn(r0, c0, r1, c1)) {
        return true;
    }    
    //Pawn moves diagonal if opponent is present 
    else if ((r1 == (r0+1) && (c1 == (c0+1) || c1 == (c0-1)) || (r1 == (r0-1) && (c1 == (c0+1) || c1 == (c0-1)))) && !empty(r1, c1) && opponent(r0, c0, r1, c1)) {
        return true;
    }
    else {
        return false;
    }
}

//Determines legality of move made by rook
//Returns true if legal; false if not. 
bool legalMoveRook(int r0, int c0, int r1, int c1) {
    printf("legalMoveRook called\n");
    //Short-circuiting ensures that opponent() is only called if the tile moved to isn't friendly
    //Important since the function opponent() only works if tile is occupied
    if (!blockedRook(r0, c0, r1, c1) && (r0 == r1 || c0 == c1)) { //Rook moves on row or column
        if (!empty(r1, c1)) {
            if (opponent(r0, c0, r1, c1)) {
                printf("Opponent recognized");
                return true;
            }
            printf("%s", FRIENDOCC);
            return false;
        }
        return true; //Move is legal 
    }
    printf("Rook move not recognized\n");
    return false; //Is either blocked or rook crosses both row and column (illegal move)
}