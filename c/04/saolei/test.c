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
	printf("��ӭ����ɨ��\n");
	//ʹ�������������ֱ�ʵ�ֲ����׺��Ų������׵���Ϣ��
//ͬʱ����ά��������һȦ�������Ͳ���ȥ�������ĺϷ����ˡ�
	char mine[Rows][Cols]={0};
	char show[Rows][Cols]={0};
	//show����Ĭ�϶���*,mine����Ĭ�϶���'0'
	//���г�ʼ��
	initboard(mine, Rows, Cols, '0');
	initboard(show, Rows, Cols, '*');
	//��ӡ����,ֻҪ�м��9*9�������Ȧֻ��Ϊ�˲�Խ�������
	printboard(show, Rows, Cols);
	
	//������
	setmine(mine,Row,Col);
	//�Ų���
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
			printf("�˳���Ϸ\n");
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
	srand((unsigned int)time(NULL)); //rand������Ҫ��ǰ�����ã�ʹ��ʱ�����ʵ��ÿһ�����е�����ԡ�
	test();
	return 0;
}