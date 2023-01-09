#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int a = 20;
	int b = 15;
	int c = (a > b ? a : b);
	printf("%d", c);
	return 0;
}