#define _CRT_SECURE_NO_WARNINGS 1

#define ROWS 11
#define	COLS 11
#define ROW ROWS-2
#define	COL COLS-2
#define count 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initboard(char board[ROWS][COLS], int row ,int col, char convey);



void Printboard(char board[ROWS][COLS], int row, int col);

void Setmine(char board[ROWS][COLS], int row, int col);


void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
