#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int Fun(int n)
//{
//    if (n == 5)
//        return 2;
//    else
//        return 2 * Fun(n + 1);
//}
//int main()
//{
//    printf("%d", Fun(2));
//    return 0;
//}
//#include<stdio.h>
//int cifang(int n, int k)
//{
//	if (k == 1)
//	{
//		return n;
//	}
//	else
//	{
//		return n * cifang(n, k - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	printf("%d", cifang(n, k));
//}
//#include<stdio.h>
//int x = 0;
//int sum(int a)
//{
//	if (a > 9)
//	{
//		sum(a / 10);
//	}
//	x += a % 10;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	sum(a);
//	printf("%d", x);
//}
//#include<stdio.h>
////int strlen(char *arr)
////{
////	if (*arr == '\0')
////	{
////		return 0;
////	}
////	else
////	{
////		return 1 + strlen(arr + 1);
////	}
////}
//int strlen(char *arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = {"abcdef"};
//	printf("%d", strlen(arr));
//}
#include<stdio.h>
int print(int a)
{
	if (a > 9)
	{
		print(a/ 10);
	}
	printf("%d ", a % 10);
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	print(a);
	return 0;
}