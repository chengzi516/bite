#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
char a = 0;
void menu()
{
	printf("****             欢迎游玩五子棋       *****\n");
	printf("****             请根据指引选择       ******\n");
	printf("****         1.play with computer     ******\n");
	printf("****         2.play with player       ******\n");
	printf("*************      3.exit     **************\n");
	printf("********************************************\n");
 }
void game()
{
	system("cls");
	char board[row][col];//创建棋盘
	//初始化棋盘为全空格
	boardinit(board,row,col);
	//打印键盘
	boardprint(board, row, col);
	while (1)
	{
		playerturn(board, row, col);
		system("cls");
		boardprint(board, row, col);
		printf("\n");
		//判断输赢,只要四个字符可以连在一起即可。并且要清晰的告诉我们是谁赢得了比赛或者有平局的可能。
		 a = win(board, row, col);
		if (a != 'c')
		{
			break;
		}
		MinMax(board, 3, NGIF, PTIF, '#');
		computerturn(board, X, Y);
		system("cls");
		boardprint(board, row, col);
		printf("\n");
		//判断输赢
		a = win(board, row, col);
		if (a != 'c')
		{
			break;
		}
	}

		if (a == '*')
		{
			printf("you win!\n");
		}
		else if (a == '#')
		{
			printf("you lost!\n");
		}
		else if (a == 'q')
		{
			printf("full ,please try again!\n");
		}
  


}
void game2()
{
	system("cls");
	char board[row][col];//创建棋盘
	//初始化棋盘为全空格
	boardinit(board, row, col);
	//打印键盘
	boardprint(board, row, col);
	while (1)
	{
		playerturn(board, row, col);
		system("cls");
		boardprint(board, row, col);
		printf("\n");
		//判断输赢,只要四个字符可以连在一起即可。并且要清晰的告诉我们是谁赢得了比赛或者有平局的可能。
		a = win(board, row, col);
		if (a != 'c')
		{
			break;
		}
		player2turn(board, row, col);
		system("cls");
		boardprint(board, row, col);
		printf("\n");
		//判断输赢
		a = win(board, row, col);
		if (a != 'c')
		{
			break;
		}
	}
	if (a == '*')
	{
		printf("player1 win!\n");
	}
	else if (a == '#')
	{
		printf("player2 win!\n");
	}
	else if (a == 'q')
	{
		printf("full ,please try again!\n");
	}
}
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("选择游戏选项\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			game2();
			break;
		case 3:
			goto end;
		default:
			printf("error\n");
			break;
		}
	} while (input);
end:
	printf("end!\n");
}
int main()
{
	test();
	return 0;
}