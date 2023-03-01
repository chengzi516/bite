#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main()
{
	int a = 3;
	int b = 5;
	int ret = 0;
	ret = add(a, b);
	printf("%d", ret);
	return 0;
}