#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char arr1[] = "this is amazing!";
//	char arr2[] = "****************";//创建两个数组，使其具有同样长度。
//	int left=0;
//	int right = strlen(arr1) - 1; //同二分查找相同，使用数组下标来控制字符串的改动。
//	printf("%s", arr2);
//	while (left<=right) //循环条件也同二分查找，当两下标移动到相同位置则停止打印。
//	{
//		
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s", arr2);
//		Sleep(1000); //使用sleep函数使打印更具层次感
//		system("cls");  //执行清理屏幕的指令
//	}
//}
//#include<stdio.h>
//int main()
//{
//	char password[20] = { 0 };
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("input the password\n");
//		scanf("%s", password);//数组名已经是地址，无需取址符&
//		if ((strcmp(password, "123456")) == 0)
//		{
//			printf("right!\n");
//				break;
//		}
//		else
//		{
//			printf("try it again\n");
//		}
//	}
//	if (i == 3)
//		printf("exit\n");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("*****1 play game*****\n");
//	printf("*****0 game  over*****\n");
//}
//void game()
//{
//	int num = rand() % 100 + 1;//任何数除以100余的数都在1-99之间，再加1，即得1-100
//	int b;
//	
//	while (1)
//	{
//		printf("input your number\n");
//		scanf("%d", &b);
//		if (b > num)
//		{
//			printf("your num is bigger\n");
//		}
//		else if (b < num)
//		{
//			printf("your num is smaller\n");
//		}
//		else
//		{
//			printf("right!\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int a = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		menu();
//		printf("choose\n");
//		scanf("%d", &a);
//		switch (a)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("error,try it again");
//		}
//	} while (a);
//	return 0;
//}
//#include<stdio.h>
//
//int main()
//{
//
//	char a[20] = "";
//	system("shutdown -s -t 60"); //关机指令为shutdown -s，-t则是设置在多少秒后
//again:
//	printf("即将关机，请输入123456停止关机程序\n");
//	scanf("%s", a);
//	if ((strcmp(a, "123456")) == 0)
//	{
//		system("shutdown -a"); //取消关机指令
//	}
//	else
//	{
//		goto again;
//	}
//
//	return 0;
//}