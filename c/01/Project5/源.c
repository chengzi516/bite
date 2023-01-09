#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
enum sex {
	male,
	female,
	secret
    
};
int main() {
	//字面常量
	3;
	4433;
	//const修饰的常量
	const float pai = 3.14;
	//注意，这样的pai是无法被修改的。
	//define定义的标识符常量
    #define m 100
	const int n = 10;
	// int arr[n] = { 0 };
	int arr[m] = { 0 };
	printf("%d\n", male);
	printf("%d\n", female);
	printf("%d\n", secret);
	return 0;
}