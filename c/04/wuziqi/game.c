#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void boardinit(char board[row][col], int Row,int Col)
{
	int i = 0;
	for (i = 0; i < Row; i++)
	{
		int j = 0;
		for (j = 0; j < Col; j++)
		{
			board[i][j] = ' '; //��������λ��
		}
	}
}
void boardprint(char board[row][col], int Row, int Col)
{
	printf("|y   x|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |  11 |  12 |  13 |");
	printf("\n");
	for (int i = 0; i < Row; i++)  //��һ��forѭ����Ƕ������ѭ����֤���̵ı仯���Ը���row��col�ĸı���ı���ʡ�
	{
		if (i + 1 > 9)
		{
			printf("|%d   |", i + 1);
		}
		else
		{
			printf("|%d    |", i + 1);
		}
		for (int j = 0; j < Col; j++)
		{
			
			printf("  %c  ", board[i][j]);
			printf("|");
		}
		printf("\n");
		printf("|-----");
		printf("|");
		for (int j = 0; j < Col; j++)
			{
				printf("-----");
				printf("|");
			}
		printf("\n");
		
	}
}
//�������ĺ���
void playerturn(char board[row][col], int Row, int Col)
{
	while (1)
	{
		printf("��ʼ������������\n");
		int x, y;
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y <= col && y >= 1)//ע�����������±���0��ʼ���������÷Ƿ����ݵ���������
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("error\n");
				printf("try again\n");
			}
		}
		else
		{
			printf("error\n");
			printf("try again\n");
		}
	}
}
void player2turn(char board[row][col], int Row, int Col)
{
	while (1)
	{
		printf("��ʼ������������\n");
		int x, y;
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y <= col && y >= 1)//ע�����������±���0��ʼ���������÷Ƿ����ݵ���������
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("error\n");
				printf("try again\n");
			}
		}
		else
		{
			printf("error\n");
			printf("try again\n");
		}
	}
}

//�÷ֺ���
int getscore(char board[row][col],char a,char b)
{
	
	int asum = 0;
	int bsum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i - 1 > -1 && j - 1 > -1 && i + 2 < row && j + 2 < col && i + 1 < row && col < col && i + 3 < row && j + 3 < col)
			{
				if (board[i][j] == '*'&& board[i][j-1]==' ' && board[i][j+3]==' ' && board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2])
				{
					asum += 100;
				}
				if (board[i][j] == '#' && board[i][j - 1] == ' ' && board[i][j + 3] == ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
				{
					bsum += 100;
				}
			}
		}
	}
	int sum=0;
	sum = bsum - asum;
	return sum;
}
//����С�����㷨���������֦���
typedef struct
{
	int data;
	int alpha;
	int beta;
	int x;
	int y;
}Tree;
int MinMax(char board[row][col],int deep,int Alpha,int Beta,char a)
{
	int minmax;
	char board2[row][col];
	char b;
	int n = 1;
	Tree tree;
	tree.data = 0;
	tree.alpha = Alpha;
	tree.beta = Beta;
	tree.x = 0;
	tree.y = 0;
	if (a == '#')
	{
		b = '*';
	}
	else
	{
		b = '#';
	}
	if (deep > 0)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (board[i][j] == ' ' && tree.alpha < tree.beta)
				{
					memcpy(board2, board, sizeof(char) * 169);
					board2[i][j] = a;
					minmax = MinMax(board2, deep - 1, tree.alpha, tree.alpha, b);
					if (deep % 2 == 0)
					{
						if (tree.alpha < minmax)
						{
							tree.alpha = minmax;
							tree.data = minmax;
							tree.x = i;
							tree.y = j;
						}
						
					}
					else
					{
						
						if (tree.beta > minmax)
						{
							tree.beta = minmax;
							tree.data = minmax;
							tree.x = i;
							tree.y = j;
						}
					}
				}
			}
		}
		X = tree.x;
		Y = tree.y;
		return tree.data;
	}
	else
	{
		return getscore(board,'*','#');
	}
}
void computerturn(char board[row][col], int x, int y)
{
	
		board[x][y] = '#';
	
}
/*
//�������壬����������·�
void computerturn(char board[row][col], int Row, int Col) //����������ֻ꣬Ҫ����δ��ռ�����������
{
	printf("computer turn\n");
	//��һ���ṩ����·���
	while (1)
	{
		int x = rand() % Row;  //  %����������ֻ���ڸ����������
		int y = rand() % Col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}


}
*/
int full(char board[row][col], int Row, int Col) //�ж������Ƿ�����
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char win(char board[row][col], int Row, int Col)
{
	//�ж���
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3]&& board[i][j+3] == board[i][j + 4] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//�ж���
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[j][i] == board[j+1][i] && board[j+1][i] == board[j+2][i] && board[j+2][i] == board[j+3][i]&& board[j+3][i]==board[j+4][i] && board[j][i] != ' ')
			{
				return board[j][i];
			}
		}
	}
	//�ж϶Խ���
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (i - 1 > -1 && j - 1 > -1 && i - 2 >-1 && j - 2 >-1 && i - 3 >-1  && j - 3 >-1&& i-4>-1 && j-4>-1)
			{
				if (board[i][j] == board[i - 1][j - 1] && board[i - 1][j - 1] == board[i - 2][j - 2] && board[i - 2][j - 2] == board[i - 3][j - 3]  && board[i-3][j-3]==board[i-4][j-4] && board[i][j] != ' ')
				{
					return board[i][j];
				}
 				if (i - 1 > -1 && j + 1 <Col && i - 2 > -1 && j + 2 < Col && i + 1 <Row && j - 1 > -1)
				{
					if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 2][j + 2] && board[i - 2][j + 2] == board[i + 1][j - 1] && board[i+2][j-2]==board[i+1][j-1] && board[i][j] != ' ')
					{
						return board[i][j];
					}
				}
				
			}
		}
	}
	if (full(board, Row, Col) == 1)
	{
		return 'q';
	}

	return 'c';
}