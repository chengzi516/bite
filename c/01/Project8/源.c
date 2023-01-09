#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int choice=0;
	printf("勤奋码代码还是躺平？（1或者0）");
	scanf("%d", &choice);
	if (choice == 1) {
		printf("offer get");
	}
	else
	{
		printf("卖红薯");
	}
	return 0;
}