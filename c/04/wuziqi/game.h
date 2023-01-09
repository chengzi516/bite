#pragma once
#define row 13
#define col 13
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<windows.h>
int jqn[row][col];
int X, Y;
#define PTIF 100000//正无穷,Beta
#define NGIF -100000//负无穷,Alpha
//函数在头文件中声明
//初始化棋盘
void boardinit(char board[row][col], int Row, int Col);//传进来的row和col要区分
//打印棋盘
void boardprint(char board[row][col], int Row, int Col);
//玩家
void playerturn(char board[row][col], int Row, int Col);
void player2turn(char board[row][col], int Row, int Col);

//电脑
void computerturn(char board[row][col], int Row, int Col);
//判断输赢
char win(char board[row][col], int Row, int Col);
//判断棋盘是否满
int full(char board[row][col], int Row, int Col);
int MinMax(char board[row][col], int deep, int Alpha, int Beta, char a);
int getscore(char board[row][col], char a, char b);