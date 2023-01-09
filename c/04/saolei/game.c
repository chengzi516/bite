#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//�����̵ĳ�ʼ����15*15��ע�����������̣�һ�����ף�һ��չʾ�������
void initboard(char  board[Rows][Cols], int rows, int	cols, char a)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = a;
		}
	}
}
//��ӡҲ��ͬ��
void printboard(char board[Rows][Cols], int rows, int cols)
{
	for (int q = 0; q < cols-1; q++)
	{
		if (q > 9)
		{
			printf("%d ", q);
		}
		else
			printf("%d  ", q);
	}
	printf("\n");
	for (int i = 1; i < rows - 1; i++)
	{
		if (i < 10)
		{
			printf("%d  ", i);
		}
		else
		{
			printf("%d ", i);
		}
		for (int j = 1; j < cols - 1; j++)
		{
			printf("%c  ", board[i][j]);
		}
		printf("\n");
	}
}
//�����ס���Ҫע�����ֻ��Ҫ��������13*13���м������С�����1���������ף���0����������
void setmine(char board[Rows][Cols], int row, int col)
{
	int count = lei;
	while (count != 0)
	{
		//��������±�
		int x = rand()%row +1;
		int y = rand() %col +1;//����Ҫע����ޣ���ҪԽ��.
		//������
		if (board[x][y] == '0') //�Ų��Ѿ����ù�����
		{
			board[x][y] = '1';
			count--;
		}

	}
}
int getminecount(char mine[Rows][Cols], int x, int y)
{
	//�ַ����ּ�ȥ�ַ�0���Եõ��������ֵ�asc��
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}
//�˺�����Ϊ���ڵ㿪һ�������׵�����ʱ��������ܰ˸���û���ף�������Χ�˸�չ����ͬ���жϣ����õݹ����ʽ�����С�
void kuozhanlei(char mine[Rows][Cols], char show[Rows][Cols], int x, int y,int *p)
{
	if (show[x][y] == '*' && mine[x][y] == '0'&&x>=1 &&x<=Row && y>=1 &&y<=Col)//����������δ���Ų�
	{
		if (getminecount(mine, x, y)) //�Ų���Χ����
		{
			show[x][y] = getminecount(mine,x,y) + '0';  //����Χ���׽��м�����
		}
		else
		{
			show[x][y] = '0';
		}
		*p += 1; //�Ų�˵�����û�׾ͽ�count+1��������count����������δ���׵�����ʱ�����������������ѭ����
		
		 if (show[x][y] == '0') //����Χ�˸�����еݹ飬չ��δ���׵�����
		 {
			 kuozhanlei(mine, show, x - 1, y - 1, p);
			 kuozhanlei(mine, show, x - 1, y, p);
			 kuozhanlei(mine, show, x - 1, y + 1, p);
			 kuozhanlei(mine, show, x, y - 1, p);
			 kuozhanlei(mine, show, x, y + 1, p);
			 kuozhanlei(mine, show, x + 1, y + 1, p);
			 kuozhanlei(mine, show, x + 1, y - 1, p);
			 kuozhanlei(mine, show, x + 1, y, p);
		 }

		 
	}
}
//�Ų��׵ĺ�����
void findmine(char mine[Rows][Cols], char show[Rows][Cols],int row, int col)
{
	printf("�����Ų�����\n");
	int x = 0;
	int y = 0;
	int count=0;
	while (count<(row*col-lei)) //��ѭ���Խ��У�˵��������Ȼ��δ�������δ��������
	{
		try:
		scanf("%d %d", &x, &y);
			if (x >= 1 && y >= 1 && x <= row && y <= col)
			{
				if (mine[x][y] == '1') //�ŵ��׼���Ϸ����
				{
					system("cls");
					printf("You were blown up\n�׵ķֲ�����ͼ\n");
					printboard(mine, Row, Col);
					break;
				}
				else //����������������׵�չ������
				{
					system("cls");
					int* p = &count;
					kuozhanlei(mine,show, x,y,p);
					printboard(show, Rows, Cols);
				}
		     }
			else
			{
				printf("����ʧ�ܣ�������\n");
				goto try;
			}
	}
	if (count == row * col - lei) //�ж�ΪӮ������ӡʤ����䣬��Ϸ������
	{
		printf("you're the winner!\n");
	}
}
