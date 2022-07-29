#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// will display a 9 row and 9 col of mine board
#define ROW 9
#define COL 9

// Define real mine board row and col in here
#define ROWS ROW+2
#define COLS COL+2

#define MINE_COUNT 10

//inital a board with a special char within speci arrange
void InitalBoard(char board[ROWS][COLS],int row,int col,char set);

//Display board
void DisplayBoard(char board[ROWS][COLS], int row, int col);

void FillMine(char board[ROWS][COLS],int row,int col);

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);