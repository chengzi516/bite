#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int isleapyear(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (isleapyear(y))
//		{
//			printf("%d ", y);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[20] = "hello,world";
//	char arr2[20] = { 0 };
//	//°Ñarr1¿½±´µ½arr2ÖÐ
//	char *p = strcpy(arr2,arr1);
//	printf("%s", arr2);
//	return 0;
//}
//int getmax(int x, int y)
//{
//	return (x > y) ? x : y;
//}
//int main()
//{
//	int num1 = 12;
//	int num2 = 7;
//	int max = getmax(num1, num2);
//	printf("%d\n", max);
//}
//void exchange1(int *p, int *q)
//{
//	int temp = 0;
//	temp = *p;
//	*p = *q;
//	*q = temp;
//}
//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	exchange1(&num1, &num2);
//	printf("num1=%d,num2=%d", num1, num2);
//	return 0;
//}