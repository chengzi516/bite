#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int age = 100;  //全局变量
int main() {
	int num = 9; //局部变量
	int age = 95;
	printf("%d", age);


	return 0;
}