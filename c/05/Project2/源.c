#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char a = 3;
//	char b = 127;
//	char c = a + b;
//	printf("%d", c);
//}
int main()
{
	char c = 1;
	printf("%d\n", sizeof(c));
	printf("%d\n", sizeof(+c));
	printf("%d\n", sizeof(-c));
}