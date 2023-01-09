#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//3.4exam1
int main() {
	int sum = 0;
	for (int i = 1; i <= 3; i++) {
		int ret = 1;
		
		for (int j = 1; j <= i; j++) {

			ret = ret * j;
			
		}
		sum += ret;
	}

	printf("%d", sum);
	return 0;
}