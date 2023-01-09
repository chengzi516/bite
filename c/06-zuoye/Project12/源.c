#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a = 8;
	float* p = (float*)&a;
	printf("n=%d\n", a);
	printf("p=%f\n", *p);
	*p = 8.0;
	printf("n=%d\n", a);
	printf("p=%f\n", *p);
	return 0;
}