#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int choice=0;
	printf("�ڷ�����뻹����ƽ����1����0��");
	scanf("%d", &choice);
	if (choice == 1) {
		printf("offer get");
	}
	else
	{
		printf("������");
	}
	return 0;
}