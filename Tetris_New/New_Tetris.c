#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <termios.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

#define HEIGHT 26
#define WIDTH 26

struct termios orig_termios;

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

// A function which makes the program "sleep", I.E waits
// for a designated amount of time before continuing excecution
int wait(unsigned int s) {
    usleep(s);
    return 0;
}

typedef struct {
    char* name;
    int **coords;
} Piece;

// Prints everything in the array at the given time (all blocks in play)
int printArr(char arr[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", arr[i][j]);
        }
        puts("");
    }
    return 0;
}
// Print the borders of the map
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

// function to make the current piece in play (the struct) 
Piece *makePiece(char* name, int** coordinates) {
    Piece *p = malloc(sizeof(Piece));
    p->name = malloc(strlen(name)+1);
    strcpy(p->name, name);
    p->coords = coordinates;    
    return p;
}

// Get a random block
char *nameOfBlock() {
    char *name;
    time_t t;
    srand((unsigned) time(&t));
    unsigned int r = rand() % 1;
    switch(r) {
        case 0:
           name = "block";
            break;
        case 1:
            name = "l";
            break;
        case 2:
            name = "invL";
            break;
        case 3:
            name = "s";
            break;
        case 4:
            name = "invS";
            break;
        case 5:
            name = "line";
            break;
        case 6: 
            name = "t";
            break;
        default:
            printf("This should not happen");
            break;
        }
    return name;
}

// Get start coordinates for piece
int **coords(const char *name) {
        int **c;
        if (strcmp(name, "block") == 0) {
        int coords[4][2] = {0, WIDTH/2, 0, (WIDTH/2)+1, 1, WIDTH/2, 1, (WIDTH)+1};
        c = coords;
        }
    // Add more here 
    return c;
}

// insert piece into array to be printed
int insertPiece(char map[HEIGHT][WIDTH], Piece *piece) {
    for (int i = 0; i < 4; i++) {
        printf("coords: %i", piece->coords[i][0]);
        map[piece->coords[i][0]][piece->coords[i][1]] = '#';
    }
    return 0;
}

// The main game loop
int main() {
    enableRawMode(); // Disables to need for a new-line before input being registered in the terminal
    bool shallPlay = true; // Determines when game shall play
    char command[] = "clear"; // Used for a system command to clear the terminal and redraw it
    bool getNewPiece = false; // Controls when a new piece shall come in to play
    char map[HEIGHT][WIDTH]; // The map which shall be drawn
    int s = 100000; // // The amount of time to "sleep" 
    int c = 0; // The int which corresponds to the character input
    // While this loop runs, the game shall continue
    while (shallPlay) {
        Piece *piece;
        char* name = nameOfBlock();
        piece = makePiece(name, coords(name));
        insertPiece(map, piece);
        while(!getNewPiece) {
            system(command);
            initMap(map);
            printArr(map);
            initscr();
            timeout(0);
            c = getch();
            endwin();
            wait(s);
        }
    }
}

