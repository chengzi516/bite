#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	printf("input the num\n");
//	scanf("%d", &a);
//	for (i = 1; i <= a; i++)
//	{
//
//		for (j = 1; j <= a; j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//int getmax(int x, int y)
//{
//	return(x > y) ? x : y;
//}
//int main()
//{
//	int a, b;
//	printf("input two nums\n");
//	scanf("%d %d", &a, &b);
//	int c = getmax(a, b);
//	printf("%d", c);
//}
#include<stdio.h>
int is_pm(int x)
{
	int flag = 0;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			break;
		}
		else
		{
			flag++;
		}
		
	}
	if (flag ==x-2)
	{
		return 1;
	}
	return 0;
}
int main()
{
	for (int i = 100; i <= 200; i++)
	{
		if (is_pm(i))
		{
			printf("%d ", i);
		}
			
	}

	return 0;
}
