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
#define PTIF 100000//������,Beta
#define NGIF -100000//������,Alpha
//������ͷ�ļ�������
//��ʼ������
void boardinit(char board[row][col], int Row, int Col);//��������row��colҪ����
//��ӡ����
void boardprint(char board[row][col], int Row, int Col);
//���
void playerturn(char board[row][col], int Row, int Col);
void player2turn(char board[row][col], int Row, int Col);

//����
void computerturn(char board[row][col], int Row, int Col);
//�ж���Ӯ
char win(char board[row][col], int Row, int Col);
//�ж������Ƿ���
int full(char board[row][col], int Row, int Col);
int MinMax(char board[row][col], int deep, int Alpha, int Beta, char a);
int getscore(char board[row][col], char a, char b);