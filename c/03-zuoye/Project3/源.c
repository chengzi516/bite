#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
////int fac(int n)
////{
////	int a = 1;
////	int b = 1;
////	int c = 1;
////	while (n > 2)
////	{
////		c = a + b;
////		a = b;
////		b = c;
////		n--;
////	}
////	return c;
////}
//int fac(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	return fac(n - 1) + fac(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fac(n));
//}
//#include<stdio.h>
////int jiecheng(int n)
////{
////	int a = 1;
////	for (int i = 1; i <= n; i++)
////	{
////		a *= i;
////	}
////	return a;
////}
//int jiecheng(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	return n * jiecheng(n - 1);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", jiecheng(n));
//}
#include<stdio.h>
reverse_string(char* arr)
{
	if (arr == '\0') 
	{
		return 0;
	}

	
}
int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
}