#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//�趨���̵������У���Ϊɨ�׹�������Ҫ�ж�����ÿһ��������ܵ������
//������Ҫ������ĺϷ��ԡ�����������������м�13*13�н���ɨ�ס�
#define Row 13
#define Col 13
#define Rows 15
#define Cols 15
#define lei 20
//��ʼ������
void initboard(char  board[Rows][Cols], int rows, int	cols, char a);
//��ӡ����
void printboard(char board[Rows][Cols], int rows, int cols);
//���������
void setmine(char board[Rows][Cols], int rows, int cols);
//����Χ���׽��м���
int getminecount(char mine[Rows][Cols], int x, int y);
//ʹ����������
void findmine(char mine[Rows][Cols], char show[Rows][Cols], int row, int col);