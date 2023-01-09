#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//01
//int main()
//{
	/*int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (i = 5)
			printf("%d ", i);
	}*/


	/*int a = 1;
	int b;
	switch (a)
	{
	case 1: b = 30;
	case 2: b = 20;
	case 3: b = 16;
	default: b = 0;
	}
	printf("%d", b);*/


	
		//int x = 3;
		//int y = 3;
		//switch (x % 2) {
		//case 1:
		//	switch (y)
		//	{
		//	case 0:
		//		printf("first");
		//	case 1:
		//		printf("second");
		//		break;
		//	default: printf("hello");
		//	}
		//case 2:
		//	printf("third");
		//}

//
//	return 0;
//}
//int main() {
//	for (int i = 1; i < 101; i++) {
//		if (i%3 == 0) {
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//int main() {
//	int a = 0, b = 0, c = 0;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a > b) {
//		if (b > c) {
//			printf("%d %d %d", a, b, c);
//		}
//		else {
//			if (a > c) {
//				printf("%d %d %d", a, c, b);
//			}
//			else {
//				printf(" % d % d % d", c, a, b);
//			}
//		}
//	}
//	else {
//		if (a > c) {
//			printf("%d %d %d", b, a, c);
//		}
//		else {
//			if (b > c) {
//				printf("%d %d %d", b, c, a);
//
//			}
//			else {
//				printf("%d %d %d", c, b, a);
//			}
//		}
//	}
//
//
//
//	return 0;
//}
//int main() {
//	int a = 0;
//	for (int i = 100; i < 201; i++)   
//	{
//		for ( a = 2; a < i; a++)   
//		{
//			
//			if (i % a == 0)  
//			{
//				break;
//			}
//		}
//		if (a == i)   
//		{
//			printf("%d ", i);
//		}
//	}
//	
//	return 0;
//}
 

//int main() {
//	for (int i = 1000; i < 2001; i++) {
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
//			printf("%d\n", i);
//		}
//	}
//}

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int gys = 0;
	int gbs = 0;
	scanf("%d%d", &a, &b);
	if (a < b)
	{
		c = a;
	}
	else
	{
		c = b;
	}
	for (int i = 1; i < c+1; i++) {
		if ((a % i == 0) &&( b % i == 0)) 
		{
			gys = i;
		}
	}
	gbs = a * b / gys;
	printf("gbs=%d gys=%d", gbs, gys);

	return 0;
}