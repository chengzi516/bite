#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//对棋盘的初始化是15*15，注意是两个棋盘，一个放雷，一个展示排雷情况
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
//打印也是同理
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
//设置雷。需要注意的是只需要将雷埋在13*13的中间区域中。将‘1’代表有雷，‘0’代表无雷
void setmine(char board[Rows][Cols], int row, int col)
{
	int count = lei;
	while (count != 0)
	{
		//随机生成下标
		int x = rand()%row +1;
		int y = rand() %col +1;//但是要注意界限，不要越界.
		//布置雷
		if (board[x][y] == '0') //排查已经布置过的雷
		{
			board[x][y] = '1';
			count--;
		}

	}
}
int getminecount(char mine[Rows][Cols], int x, int y)
{
	//字符数字减去字符0可以得到整型数字的asc码
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}
//此函数是为了在点开一个不是雷的区域时，如果四周八个格都没有雷，即对周围八格展开相同的判断，采用递归的形式来进行。
void kuozhanlei(char mine[Rows][Cols], char show[Rows][Cols], int x, int y,int *p)
{
	if (show[x][y] == '*' && mine[x][y] == '0'&&x>=1 &&x<=Row && y>=1 &&y<=Col)//本身不是雷且未被排查
	{
		if (getminecount(mine, x, y)) //排查周围的雷
		{
			show[x][y] = getminecount(mine,x,y) + '0';  //将周围的雷进行计数。
		}
		else
		{
			show[x][y] = '0';
		}
		*p += 1; //排查此点后如果没雷就将count+1，当满足count等于棋盘中未埋雷的数量时，即跳出输入坐标的循环。
		
		 if (show[x][y] == '0') //对周围八个点进行递归，展开未埋雷的区域。
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
//排查雷的函数。
void findmine(char mine[Rows][Cols], char show[Rows][Cols],int row, int col)
{
	printf("输入排查坐标\n");
	int x = 0;
	int y = 0;
	int count=0;
	while (count<(row*col-lei)) //若循环仍进行，说明场上任然有未被输入的未埋雷坐标
	{
		try:
		scanf("%d %d", &x, &y);
			if (x >= 1 && y >= 1 && x <= row && y <= col)
			{
				if (mine[x][y] == '1') //排到雷即游戏结束
				{
					system("cls");
					printf("You were blown up\n雷的分布如下图\n");
					printboard(mine, Row, Col);
					break;
				}
				else //不是雷则进入棋盘雷的展开函数
				{
					system("cls");
					int* p = &count;
					kuozhanlei(mine,show, x,y,p);
					printboard(show, Rows, Cols);
				}
		     }
			else
			{
				printf("输入失败，请重试\n");
				goto try;
			}
	}
	if (count == row * col - lei) //判断为赢，即打印胜利语句，游戏结束。
	{
		printf("you're the winner!\n");
	}
}
