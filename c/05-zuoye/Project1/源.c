#define _CRT_SECURE_NO_WARNINGS 1
//int main()
//{
//	int a, b, c;
//	a = 5;
//	c = ++a; //a=c=6
//	b = ++c, c++, ++a, a++; //b=7,c=7,a=8
//	b += a++ + c; //
//	printf("a = %d b = %d c = %d\n:", a, b, c);
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("a=%d,b=%d", a, b);
//}
//#include <stdio.h>
//	int countone(int num )
//	{
//		
//		int i = 0;
//		int count = 0;//����
//		while (num)
//		{
//			count++;
//			num = num & (num - 1);
//		}
//		
//		return count ;
//	}
//	
#include<stdio.h>
int main() {
	int num = 0;
	printf("������һ����:");
	scanf("%d", &num);
	printf("����λ��");
	for (int i = 31; i >= 1; i -= 2) {
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
	printf("ż��λ��");
	for (int i = 30; i >= 0; i -= 2) {
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
	system("pause");
	return 0;
}
