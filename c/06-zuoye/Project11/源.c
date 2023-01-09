#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a = 10;
	int b = 1;
	char* p = (char*)&b;
	if (*p == 1)
	{
		printf("Ð¡¶Ë");
	}
	else
	{
		printf("´ó¶Ë");

	}
}