#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char board[ROWS][COLS], int row, int col, char convey) 
{
	int i = 0;
	int j = 0;
	for (i=0;i<ROWS;i++)
	{
		for (j=0;j<COLS;j++) 
		{
			board[i][j] = convey;
		}
	}
}

void Printboard(char board[ROWS][COLS], int row, int col) 
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++) {
		printf("%d ",i);
	}
	    printf("\n"); 
	for (i=1;i<=row;i++) 
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++) 
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}


void Setmine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int sum = count;
	while (sum) {
       x = rand() % row + 1;
	   y = rand() % col + 1;
       if (board[x][y] == '0')
	   {
	       board[x][y] = '1';
		   sum--;
	   }
	}


	/*for (i=1;i<row;i++)
	{
		for (j = 1; j < col; j++)
		{
			
		}
	}*/
}

int Is_Mine_Count(char mine[ROWS][COLS], int x,int y) {
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] +
		mine[x][y - 1] - 8 * '0';
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) 
{
	int x = 0; int y = 0; int IsWin = 0;

	while (IsWin< row * col - count)
	{
		
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) 
		{
			if (mine[x][y]=='1')
			{
				printf("该位置是炸弹，您被炸死！\n");
				Printboard(mine,row,col);
				break;
			}
			else
			{
				int amount=Is_Mine_Count(mine,x,y);
				show[x][y] = amount + '0';
				Printboard(show, row, col);
				IsWin++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入！\n");
		}
	}
	if (IsWin == row * col - count) {
		printf("恭喜你，扫雷成功！");
	}
}
