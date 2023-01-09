#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int line=0;
//	scanf("%d", &line);
//	//line
//	for (int i = 0; i < line; i++)
//	{
//		for (int j = 0; j<line-1-i; j++)
//		{
//			printf(" ");
//		}
//		for (int q = 0; q < i * 2 + 1; q++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	//line-1
//	 line = line - 1;
//	 int a = line;
//	for (int i = 0; i < line ; i++)
//	{
//		for (int j = 0; j <=i; j++)
//		{
//			printf(" ");
//		}
//		for (int q = 0; q <2*a-1; q++)
//		{
//			printf("*");
//		}
//		printf("\n");
//		a--;
//		}
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	for (int i = 0; i < 100000; i++)
//	{
//		//判断是几位数
//		int n = 0;
//		int tmp = i;
//		while (tmp)
//		{
//			tmp /= 10;
//			n++;
//		}
//		tmp = i;
//		int sum = 0;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, n);
//			tmp /= 10;
//		}
//
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
#include<stdio.h>
int main()
{
	int n = 0;
	int a = 0;
	scanf("%d %d", &a, &n);
	int sum = 0;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		k=k * 10 + a;
		sum += k;
	}
	printf("%d", sum);
	return 0;
}