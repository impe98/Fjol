#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size;
int height;
int width;
int tal1 = -1;
int tal2 = -1;
int x;
int y;
int range2;
int gameBoard[x][y];
int randomInt(int range, int tempBoard[x][y]);
bool isValueInArray(int val, int tempBoard[x][y]);

int main(int argc, char *argv[]) {
  do {
    printf("Please give size of board (must be multiple of two): ");
    scanf("%d", &size);
  } while (size % 2 != 0);
  height = size / 2;
  width = 2;
  gameBoard[width][height] = randomInt((height+height), int board[width][height]);
  return 0;
}
  
  
int randomInt(int range, int tempBoard[2][range2]) {
  time_t t;
  int tempLoc;
  int tempLoc2;
  srand((unsigned) time(&t));
  for(int i = 0; i < range; i++) {
    do {
      int temp = rand() % range;
      tal1 = temp;
      tal2 = tal1;
    } while (isValueInArray(tal1, tempBoard[2][range2]) == false);
    do {
      tempLoc = rand() % 2;
      tempLoc2 = rand() % range;
      tempBoard[tempLoc][tempLoc2] = tal1;
    } while (tempBoard[tempLoc][tempLoc2] == '0');
    do {
      tempLoc = rand() % 2;
      tempLoc2 = rand() % range;
    } while (tempBoard[tempLoc][tempLoc2] == '0');
  }
  return tempBoard;
}

bool isValueInArray(int val, int arr[x][y]) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++)
    if (arr[i][j] == val) {
      return true;
    }
  }
  return false;
}
	
    
    
