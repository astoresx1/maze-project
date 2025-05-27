#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#define MAX 100

int col, row;

char maze_a[MAX][MAX];

void input();
void maze();
void print_maze();