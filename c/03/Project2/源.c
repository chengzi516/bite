#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int add(int *x)
//{
//	(*x)++;
//}
//int main()
//{
//	int num = 0;
//	num = add(&num);
//	printf("%d", num);
//	return 0;
//}
//#include<stdio.h>
//void one_hello()
//{
//	printf("hello\n");
//}
//void three_hello()
//{
//	for (int i = 0; i < 3; i++)
//	{
//		one_hello();
//	}
//}
//int main()
//{
//	three_hello();
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	printf("%d", printf("%d", printf("%d", 43)));
//}
//#include<stdio.h>
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d", n%10);
//}
//int main()
//{
//	int num = 1234;
//	print(num);
//	return 0;
//}
int strlen(char *arr)
{
	if (*arr == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + strlen(arr + 1);
	}
}
#include<stdio.h>
int main()
{
	char arr[] = { "abcdef" };
	strlen(arr);
	printf("%d", strlen(arr));
}