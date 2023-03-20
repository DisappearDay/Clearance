#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu() {
	printf("***********************************\n");
	printf("****** 1. PLAY    0. EXIT *********\n");
	printf("***********************************\n");
}

void game() {
	//布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//排查出来的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	Initboard(mine,ROWS,COLS,'0');
	Initboard(show,ROWS,COLS,'*');
	//打印
	Printboard(show, ROW, COL);
	//Printboard(mine, ROW, COL);
	//布置雷
	Setmine(mine,ROW,COL);
	//Printboard(mine, ROW, COL);
	//扫雷
	FindMine(mine,show,ROW,COL);
}

void test() {
	int input = 0;

	srand((unsigned int)time(NULL));
	menu();
	do {
		printf("请输入>:");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game(); break;
		case 0:	
			printf("退出游戏\n"); break;
		default:
			printf("选择无效，请重新输入\n");	 break;
		}
	} while (input);
	
}



int main() {
	test();


	return 0;
}
