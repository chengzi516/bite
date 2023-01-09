#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int a = 0;
	int b = 0;
	printf("input two numbers\n");
	scanf("%d %d", &a, &b);
	int M;
	M=max(a, b);
	printf("the bigger number is%d", M);

	return 0;
}
int max(int c, int d) {
	int e;
	if (c > d) {
		e = c;
	}
	else if(c<d) {
		e = d;
	}
	else {
		e = c;
	}
	return e;
}