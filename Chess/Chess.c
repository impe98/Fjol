#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ChessPieces.h"

#define HEIGHT 26
#define WIDTH 26

void freeStuff() {
    for (int i = 0; i < 32; i++) {
        free(chessPieces[i]);
    }
}

int main(int argc, char** argv) {   
    chessPiecesInit();
    chessPiecesArray();
    for (int i = 0; i < 32; i++) {
        printf("Name is: %s\n", chessPieces[i]->pieceName);
    }
    freeStuff();
    return 0;
}