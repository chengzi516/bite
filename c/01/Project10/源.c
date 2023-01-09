#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*int main() {


	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	scanf("%d %d", &num1, &num2);
	sum =num1 + num2;
	printf("sum=%d\n", sum);

	return 0;
}  */
int add(int x, int y) {  //创建函数名为add，同时有两个输入
	int z = x + y;  //让变量z等于输入两数和
	return z;   //返回z的值
}
int main() {


	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	scanf("%d %d", &num1, &num2);
	sum = add(num1,num2);
	printf("%d", sum);
	return 0;
}