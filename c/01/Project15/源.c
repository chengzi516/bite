#define _CRT_SECURE_NO_WARNINGS 1
//关键字typedef
//#include<stdio.h>
//typedef unsigned int uint;
//int main() {
//	uint a = 10;
//	return 0;
//}
//关键字static
//#include<stdio.h>
//void test() {
//	static int q=0;
//	q++;
//	printf("%d\n", q);
//}
//int main() {
//	int i = 0;
//	for (i = 0; i < 10; i++) {
//		test();
//
//	}
//	return 0;
//
//}
//define定义常量与宏
//#include<stdio.h>
//#define A 10   //定义标识符常量
//#define sum(x,y)  ((x)+(y)) //定义宏
//int main() {
//	int a = sum(1, 2);
//	printf("%d", a);
//	return 0;
//}
//#include<stdio.h>
//int main() {
//	int a = 10;
//	&a;//用取址符取出a的地址
//	printf("%p", &a);  //%p是以地址形式打印
//	return 0;
//
//}
//
#include<stdio.h>
int main() {
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(double*));
	return 0;
}