#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 26
#define WIDTH 26

typedef struct
{
    char* pieceName;
    bool alive;
    bool black;
}chessPiece;

//TODO: Create function to print board and it's contents 

int main(int argc, char** argv) {
    char boardArr[HEIGHT][WIDTH];
    chessPiece* chessPieces = malloc(sizeof(*chessPieces));
    chessPieces[0].pieceName = "Bonde";
    chessPieces[0].alive = true;
    chessPieces[0].black = true;
    printf("%s", chessPieces[0].pieceName); 
    board(boardArr);

}