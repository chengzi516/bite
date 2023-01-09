#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//设定棋盘的行与列，因为扫雷过程中需要判断棋盘每一个落点四周的情况，
//所以需要检查落点的合法性。即增加棋盘面积在中间13*13中进行扫雷。
#define Row 13
#define Col 13
#define Rows 15
#define Cols 15
#define lei 20
//初始化棋盘
void initboard(char  board[Rows][Cols], int rows, int	cols, char a);
//打印棋盘
void printboard(char board[Rows][Cols], int rows, int cols);
//随机设置雷
void setmine(char board[Rows][Cols], int rows, int cols);
//对周围的雷进行计数
int getminecount(char mine[Rows][Cols], int x, int y);
//使用坐标找雷
void findmine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col);