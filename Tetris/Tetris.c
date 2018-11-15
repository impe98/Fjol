#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <termios.h>
#include <errno.h>
#include <ctype.h>

#define HEIGHT 26
#define WIDTH 26

struct termios orig_termios;

// different bools to determine the block in play; used to determine fields to occupy
bool isBlock = false;
bool isL = false;
bool isInvL = false;
bool isT = false;
bool isLine = false;
bool isS = false;
bool isInvS = false;

// The turnCount is a global variable, which determines the way in which the current block is turned
int turnCount = 0;

// The array of occupyed fields - 0 means vacant; a char means occupied
char occFields[HEIGHT][WIDTH] = {0};

// Meant to disable raw-mode as to make usage of terminal bearable after each run
void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
// Enables raw-mode, which disables echo mode and canon-mode,
// making inputs dissapear from the terminal and inputs registered immediatly (respectively)
void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);
  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Declare turn function
void turn();

// Declare turnBlock function
void turnBlock(int y, int x);

// A function which makes the program "sleep", I.E waits
// for a designated amount of time before continuing excecution
int wait(unsigned int s) {
    usleep(s);
    return 0;
}

// Prints everything in the array at the given time (might add unto it to also print the contents of OccField)
int printArr(char arr[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (occFields[i][j] != 0) {
                arr[i][j] = occFields[i][j];
            }
            printf("%c", arr[i][j]);
        }
        puts("");
    }
    return 0;
}

// Inserts a box with the given coordinates x and y
int insertBox(char arr[HEIGHT][WIDTH], int y, int x) {
    arr[y][x] = '#';
    arr[y][x+1] = '#';
    arr[y+1][x] = '#';
    arr[y+1][x+1] = '#';
    return 0;
}

// Inserts an L with the given coordinates x and y
int insertL(char arr[HEIGHT][WIDTH], int y, int x) {
    switch(turnCount) {
        case 0:
            arr[y][x] = '*';
            arr[y+1][x] = '*';
            arr[y+2][x] = '*';
            arr[y+2][x+1]   = '*';
            break;
            return 0;
        case 1:
            arr[y][x+2] = '*';
            arr[y][x+1] = '*';
            arr[y][x] = '*';
            arr[y+1][x]   = '*';
            break;
            return 0;
        case 2:
            arr[y+2][x+1] = '*';
            arr[y+1][x+1] = '*';
            arr[y][x+1] = '*';
            arr[y][x]   = '*';
            break;
            return 0;
        case 3:
            arr[y+2][x] = '*';
            arr[y+2][x+1] = '*';
            arr[y+2][x+2] = '*';
            arr[y+1][x+2]   = '*';
            break;
            return 0;
        default:
            break;
            return 0;
    }
}
// Inserts an inverse L with the given coordinates x and y 
int insertInvL(char arr[HEIGHT][WIDTH], int y, int x) {
     switch(turnCount) {
            case 0:
                arr[y][x] = 'o';
                arr[y+1][x] = 'o';
                arr[y+2][x] = 'o';
                arr[y+2][x-1] = 'o';
                return 0;
                break;
            case 1:
                arr[y+2][x+1] = 'o';
                arr[y+2][x] = 'o';
                arr[y+2][x-1] = 'o';
                arr[y+1][x-1] = 'o';
                return 0;
                break;
            case 2:
                arr[y+2][x-1] = 'o';
                arr[y+1][x-1] = 'o';
                arr[y][x-1] = 'o';
                arr[y][x] = 'o';
                return 0;
                break;
            case 3:
                arr[y+1][x] = 'o';
                arr[y+1][x+1] = 'o';
                arr[y+1][x-1] = 'o';
                arr[y+2][x+1] = 'o';
                return 0;
                break;
            default:
                break;
                return 0;
        }   
}

// Inserts an s with the given coordinates x and y
int insertS(char arr[HEIGHT][WIDTH], int y, int x) {
    switch(turnCount) {
            case 0:
                arr[y][x] = 'Q';
                arr[y][x+1] = 'Q';
                arr[y+1][x] = 'Q';
                arr[y+1][x-1] = 'Q';
                return 0; 
                break;
            case 1:
                arr[y][x] = 'Q';
                arr[y+1][x] = 'Q';
                arr[y][x-1] = 'Q';
                arr[y-1][x-1] = 'Q';
                return 0; 
                break;
            case 2:
                arr[y][x] = 'Q';
                arr[y][x+1] = 'Q';
                arr[y+1][x] = 'Q';
                arr[y+1][x-1] = 'Q';
                return 0; 
                break;
            case 3:
                arr[y][x] = 'Q';
                arr[y+1][x] = 'Q';
                arr[y][x-1] = 'Q';
                arr[y-1][x-1] = 'Q';
                return 0; 
                break;
            default:
                return 1;
                break;
    }
}

int insertInvS(char arr[HEIGHT][WIDTH], int y, int x) {
    arr[y][x] = 'D';
    arr[y][x-1] = 'D';
    arr[y+1][x] = 'D';
    arr[y+1][x+1] = 'D';
    return 0;
}

int insertLine(char arr[HEIGHT][WIDTH], int y, int x) {
    arr[y][x] = '|';
    arr[y+1][x] = '|';
    arr[y+2][x] = '|';
    arr[y+3][x] = '|';
    return 0;
}
int insertT(char arr[HEIGHT][WIDTH], int y, int x) {
    arr[y][x] = '+';
    arr[y+1][x] = '+';
    arr[y+1][x+1] = '+';
    arr[y+1][x-1] = '+';
    return 0;
}

// Initalizes the map (I.E makes the borders of the game-board)
void initMap(char map[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT-1) {
                map[i][j] = '-';
            } else if (j == 0 || j == WIDTH-1) {
                map[i][j] = '|';
            } else {
                    map[i][j] = ' ';
            }
        }
    }
}
// Moves the piece depending on input
int input(int c, int* y, int* x) {
    if (c == 97) {
        (*x)--; 
        return 0;
    } else if (c == 115) {
         (*y)++;
        return 0;
    } else if (c == 100) {
        (*x)++;
        return 0;
    }
    else if (c == 108) {
        turn();
    }
    else {
        return 1;
    }
}


// Sets coordinates in the array OccFields as a char, to set them as occupied
int insertOccField(int y, int x) {
    if (isBlock) {
        occFields[y][x] = '#';
        occFields[y][x+1] = '#';
        occFields[y+1][x] = '#';
        occFields[y+1][x+1] = '#';
        return 0;
    }
    else if (isL) {
        switch(turnCount) {
            case 0:
                occFields[y][x] = '*';
                occFields[y+1][x] = '*';
                occFields[y+2][x] = '*';
                occFields[y+2][x+1] = '*';
                return 0;
                break;
            case 1:
                occFields[y][x+2] = '*';
                  occFields[y][x+1] = '*';
                occFields[y][x] = '*';
                occFields[y+1][x] = '*';
                return 0;
                break;
            case 2:
                occFields[y+2][x+1] = '*';
                occFields[y+1][x+1] = '*';
                occFields[y][x+1] = '*';
                occFields[y][x] = '*';
                return 0;
                break;
            case 3:
                occFields[y+2][x] = '*';
                occFields[y+2][x+1] = '*';
                occFields[y+2][x+2] = '*';
                occFields[y+1][x+2] = '*';
                return 0;
                break;
            default:
                return 1;
                break;
        }
    }
    else if (isInvL) {
        switch(turnCount) {
            case 0:
                occFields[y][x] = 'o';
                occFields[y+1][x] = 'o';
                occFields[y+2][x] = 'o';
                occFields[y+2][x-1] = 'o';
                return 0;
                break;
            case 1:
                occFields[y+2][x+1] = 'o';
                occFields[y+2][x] = 'o';
                occFields[y+2][x-1] = 'o';
                occFields[y+1][x-1] = 'o';
                return 0;
                break;
            case 2:
                occFields[y+2][x-1] = 'o';
                occFields[y+1][x-1] = 'o';
                occFields[y][x-1] = 'o';
                occFields[y][x] = 'o';
                return 0;
                break;
            case 3:
                occFields[y+1][x] = 'o';
                occFields[y+1][x+1] = 'o';
                occFields[y+1][x-1] = 'o';
                occFields[y+2][x+1] = 'o';
                return 0;
                break;
            default:
                return 1;
                break;
        }       
    }
    else if (isS) {
        switch(turnCount) {
            case 0:
                occFields[y][x] = 'Q';
                occFields[y][x+1] = 'Q';
                occFields[y+1][x] = 'Q';
                occFields[y+1][x-1] = 'Q';
                return 0; 
                break;
            case 1:
                occFields[y][x] = 'Q';
                occFields[y+1][x] = 'Q';
                occFields[y][x-1] = 'Q';
                occFields[y-1][x-1] = 'Q';
                return 0; 
                break;
            case 2:
                occFields[y][x] = 'Q';
                occFields[y][x+1] = 'Q';
                occFields[y+1][x] = 'Q';
                occFields[y+1][x-1] = 'Q';
                return 0; 
                break;
            case 3:
                occFields[y][x] = 'Q';
                occFields[y+1][x] = 'Q';
                occFields[y][x-1] = 'Q';
                occFields[y-1][x-1] = 'Q';
                return 0; 
                break;
            default:
                return 1;
                break;
        }
    }
    else if (isInvS) {
        occFields[y][x] = 'D';
        occFields[y][x-1] = 'D';
        occFields[y+1][x] = 'D';
        occFields[y+1][x+1] = 'D';
        return 0;
    }
    else if (isLine) {
        occFields[y][x] = '|';
        occFields[y+1][x] = '|';
        occFields[y+2][x] = '|';
        occFields[y+3][x] = '|';
        return 0;
    }
    else if (isT) {
        occFields[y][x] = '+';
        occFields[y+1][x] = '+';
        occFields[y+1][x+1] = '+';
        occFields[y+1][x-1] = '+';
        return 0;
    }
}

// Checks if given move is legal, depending on the current block in play. 

bool isLegalMove(int c, int y, int x) {
    if (isBlock) {
        if ((c == 97 && x > 1 && occFields[y][x-1] == 0 && occFields[y+1][x-1] == 0) 
             || (c == 115 && y < HEIGHT-3 && occFields[y+2][x] == 0 && occFields[y+2][x+1] == 0)
             || (c == 100 && x < WIDTH-3 && occFields[y][x+2] == 0 && occFields[y+1][x+2] == 0)) {
                 return true;
        }
        else {
            return false;
        }
    }
    else if (isL) {
        if ((c == 97 && x > 1 && occFields[y][x-1] == 0 && occFields[y+1][x-1] == 0 && occFields[y+2][x-1] == 0) 
    || (c == 115 && y < HEIGHT-4 && occFields[y+3][x] == 0 && occFields[y+3][x+1] == 0)
    || (c == 100 && x < WIDTH-3 && occFields[y][x+2] == 0)) {
        return true;
     }
     else if (c == 108) {
         return true;
     }
    else {
        return false;
        }
    }
    else if (isInvL) {
        if ((c == 97 && x > 2 && occFields[y][x-2] == 0 && occFields[y+1][x-2] == 0 && occFields[y+2][x-3] == 0)
    || (c == 115 && y < HEIGHT-4 && occFields[y+3][x] == 0 && occFields[y+3][x-1] == 0)
    || (c == 100 && x < WIDTH-3 && occFields[y][x-2] == 0)) {
        return true;
         }
    else if (c == 108) {
        return true;
    }
    else {
        return false;
        }
    }
    else if (isS) {
        if ((c == 97 && x > 2 && occFields[y][x-2] == 0 && occFields[y+1][x-2] == 0)
        || (c == 115 && y < HEIGHT-3 && occFields[y+1][x] == 0 && occFields[y+1][x+1] == 0 && occFields[y+1][x-1] == 0)
        || (c == 100 && x < WIDTH-3 && occFields[y][x+1] == 0)) {
            return true;
             }
        else if (c == 108) {
            return true;
        }
        else {
            return false;
             }
        }
    else if (isInvS) {
        if ((c == 97 && x > 2 && occFields[y][x-2] == 0 && occFields[y+1][x-2] == 0) 
        || (c == 115 && y < HEIGHT-3 && occFields[y+1][x] == 0 && occFields[y+1][x+1] == 0 && occFields[y+1   ][x-1] == 0)
        || (c == 100 && x < WIDTH-3 && occFields[y][x+1] == 0)) {
            return true;
        }
    }
    else if (isLine) {
        if ((c == 97 && x > 1 && occFields[y+1][x-2] == 0)
        || (c == 115 && y < HEIGHT-3 && occFields[y+5][x] == 0)
        || (c == 100 && x < WIDTH-3 && occFields[y][x+1] == 0 && occFields[y+1][x+1] == 0 && occFields[y+2][x+1] == 0 && occFields[y+3][x] == 0)) {
            return true;
        }
    }
    else if (isT) {
        if ((c == 97 && x > 2 && occFields[y][x-2] == 0)
        || (c == 115 && y < HEIGHT-3 && occFields[y+4][x] == 0)
        || (c == 100 && x < WIDTH-3 && occFields[y][x+2] == 0 && occFields[y+1][x+2] == 0 && occFields[y+2][x+2] == 0 && occFields[y+3][x] == 0)) {
            return true;
        }
    }
    return false;
}
// Checks if a new block should come into play
bool shallGetNewBlock(int y, int x) {
    if (isBlock) {
        if (y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+2][x+1] != 0))) {
            return true;
        }
    }
    else if (isL) {
        switch(turnCount) {
            case 0:
                if ((y+3 >= HEIGHT-1 || ((occFields[y+3][x] != 0 || occFields[y+3][x+1] != 0)))) {
                    return true;
                }
                break;  
                return false;
            case 1:
                if ((y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+1][x+1] != 0 || occFields[y+1][x+2] !=0 )))) {
                    return true;
                }
                break;
                return false;
            case 2:
                if ((y+3 >= HEIGHT-1 || ((occFields[y+1][x] != 0 || occFields[y+3][x+1] != 0)))) {
                    return true;
                }
                break;
                return false;
            case 3:
                if ((y+3 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+2][x+1] != 0 || occFields[y+2][x+2])))) {
                    return true;
                }
                break;
                return false;
            default:
                return false;
        }
    }
    else if (isInvL) {
        switch(turnCount) {
            case 0:
                if ((y+3 >= HEIGHT-1 || ((occFields[y+3][x] != 0 || occFields[y+3][x-1] != 0)))) {
                    return true;
                }
                break;
                return false;
            case 1:
                if ((y+3 >= HEIGHT-1 || ((occFields[y+3][x-1] != 0 || occFields[y+3][x] != 0 || occFields[y+3][x+1] != 0)))) {
                    return true;
                }
                break;
                return false;
            case 2:
                if ((y+3 >= HEIGHT-1 || (occFields[y+1][x] != 0 || occFields[y+3][x-1] != 0))) {
                    return true;
                }
                break;
                return false;
            case 3:
                if ((y+3 >= HEIGHT-1 || (occFields[y+3][x+1] != 0 || occFields[y+2][x] != 0 || occFields[y+2][x-1] != 0))) {
                    return true;
                }
                break;
                return false;
            default:
                break;
                return false;
        }
    }
    else if(isS) {
        switch(turnCount) {
            case 0:
                if (y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+2][x-1] != 0 || occFields[y+1][x+1] != 0))) {
                    return true;
                }
                break;
                return false;
            case 1:
                if (y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+1][x-1] != 0))) {
                    return true;
                }
                break;
                return false;
            case 2:
                if (y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+2][x-1] != 0 || occFields[y+1][x+1] != 0))) {
                    return true;
                }
                break;
                return false;
            case 3:
                if (y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+1][x-1] != 0))) {
                    return true;
                }
                break;
                return false;
            default:
                break;
                return false;
        }
    }
    if (((((y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+2][x+1] != 0))) && isBlock))) || 
            //((((y+3 >= HEIGHT-1 || ((occFields[y+3][x] != 0 || occFields[y+3][x+1] != 0))) && isL))) ||
            //((((y+3 >= HEIGHT-1 || ((occFields[y+3][x] != 0 || occFields[y+3][x-1] != 0))) && isInvL))) ||
            //((((y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+2][x-1] != 0 || occFields[y+1][x+1] != 0))) && isS))) ||
            ((((y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+1][x-1] != 0 || occFields[y+2][x+1] != 0))) && isInvS))) ||
            ((((y+4 >= HEIGHT-1 || ((occFields[y+4][x] != 0))) && isLine)))||
            ((((y+2 >= HEIGHT-1 || ((occFields[y+2][x] != 0 || occFields[y+2][x+1] != 0 || occFields[y+2][x-1] != 0)) && isT))))) {
                return true;
            }
    else {
        return false;
    }
}
// Delete rows if they are fully occupied and returns the amount of deleted lines (why return amount of deleted lines?)
int deleteRows() {
    int linesToDelete = 0;
    for (int i = 0; i < HEIGHT+1; i++) {
        int c = 0;
        for (int j = 0; j < WIDTH+1; j++) {
            if (occFields[i][j] != 0) {
                c++;
            }
        }
        if (c >= WIDTH-2) {
            for (int h = 0; h < WIDTH+1; h++) {
                occFields[i][h] = 0;
            }
            linesToDelete++;
        }
        return linesToDelete;
    }
}

void setAllFalse() {
    isBlock = false;
    isL = false;
    isInvL = false;
    isS = false;
    isInvS = false;
    isLine = false;
    isT = false;
}

void insertBlock(char map[HEIGHT][WIDTH], int y, int x) {
    if (isBlock) {
        insertBox(map, y, x);
    }
    else if (isL) {
        insertL(map, y, x);
        }
    else if (isInvL) {
        insertInvL(map, y, x);
    }
    else if (isS) {
        insertS(map, y, x);
    }
    else if (isInvS) {
        insertInvS(map, y, x);
    }
    else if (isLine) {
        insertLine(map, y, x);
    }
    else if (isT) {
        insertT(map,  y, x);
    }
}

void turn() {
    if (turnCount <= 2) {
        turnCount++;
    }
    else {
        turnCount = 0;
    }
}

// NOTE TO SELF: CHECK COLLISION
// The main game-loop
int main() {
    enableRawMode();
    char map[HEIGHT][WIDTH];
    int c = 0;
    int y = 0;
    int x = 10;
    int s = 100000;
    bool shallPlay = true;
    char command[6] = "clear";
    int w;
    bool getNewBlock = false;
    unsigned int r;
    // When this loop terminates, the game is over
    while (shallPlay == true) {
        // getNewBlock = false;
        setAllFalse();
        time_t t;
        srand((unsigned) time(&t));
        r = rand() % 4;
        switch(r) {
            case 0:
                isBlock = true;
                break;
            case 1:
                 isL = true;
                break;
            case 2:
                isInvL = true;
                break;
            case 3:
                isS = true;
                break;
            /*
            case 4:
                isInvS = true;
                break;
            case 5:
                isLine = true;
                break;
            case 6: 
                isT = true;
                break;
            */
           default:
                printf("This shold not happen");
                break;
            }
        y = 0;
        x = (WIDTH/2);
        // Turn count is the current way in which a block is turned (0-3).
        turnCount = 0;
        getNewBlock = false;
        // When this loop terminates, the given block is done and a new must be initialized
        // Make one function insertPiece to call?
        while (!getNewBlock) {
            system(command);
            initMap(map);
            insertBlock(map, y, x);
            printArr(map);
            if ((y < HEIGHT+1 && isBlock) || (y < HEIGHT && isL) || 
            (y < HEIGHT && isInvL) || (y < HEIGHT+1 && isS) || (y < HEIGHT+1 && isInvS) || (y < HEIGHT-1 && isLine) || (y < HEIGHT-1 && isT)) {
              input(115, &y, &x);
            }   
            initscr();
            timeout(0);
            c = getch();
            endwin();
            if (isLegalMove(c,y,x)) {
                input(c, &y, &x);
            }
            if (shallGetNewBlock(y, x)) {
                getNewBlock = true;
                insertOccField(y, x);
            }
            deleteRows();
            initMap(map);
            insertBlock(map, y, x);
            system(command);
            printArr(map);
            wait(s);
        }
    }
    disableRawMode();  
}