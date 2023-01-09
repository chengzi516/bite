#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int add(int x, int y)
//{
//	return x + y;
//}
//void test(int arr[])
//{
//	printf("1");
//}
//int main()
//{
//	int x = 1;
//	int y = 2;
//	int ret=add(x, y);
//	printf("%d", ret);
//	int arr[] = { 1,2,3,4,5 };
//	test(arr);
//}
//void test3()
//{
//	int a = 10;
//}
//void test2()
//{
//	test3();
//}
//void test1()
//{
//	test2();
//}
//int main()
//{
//	test1();
//}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = 1;
	int sum=0;
	for (int j = 1; j <= 3; j++)
	{

		for (int i = 1; i <= n; i++)
		{
			ret *= i;
		}
		sum += ret;
	}
	printf("%d", ret);
}