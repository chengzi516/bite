#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int a = 100;
	int b = a++;  
	printf("a=%d,b=%d\n", a, b);
	 b = ++a;
	printf("a=%d,b=%d", a, b);

	return 0;
}