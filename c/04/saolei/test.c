#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("**********************************\n");
	printf("*********     1.play      ********\n");
	printf("*********     2.exit      ********\n");
	printf("**********************************\n");
}
void game()
{
	printf("欢迎游玩扫雷\n");
	//使用两个数组来分别实现布置雷和排查查出的雷的信息。
//同时将二维数组扩大一圈，这样就不用去检查数组的合法性了。
	char mine[Rows][Cols]={0};
	char show[Rows][Cols]={0};
	//show数组默认都是*,mine数组默认都是'0'
	//进行初始化
	initboard(mine, Rows, Cols, '0');
	initboard(show, Rows, Cols, '*');
	//打印棋盘,只要中间的9*9，外面的圈只是为了不越界而处理
	printboard(show, Rows, Cols);
	
	//布置雷
	setmine(mine,Row,Col);
	//排查雷
	findmine(mine, show, Row, Col);

}
void test()
{
	int input = 0;

	do
	{
		menu();
		printf("choose\n");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏\n");
			goto end;
			break;
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
	srand((unsigned int)time(NULL)); //rand函数必要的前置设置，使用时间戳来实现每一次运行的随机性。
	test();
	return 0;
}