#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	printf("study hard");
	int code = 0;
	while (code < 100) {
		code++;
		printf("work harder\n ");
	}
	if (code >= 100) {
		printf("amazing!");
	}

	{
		printf("%d\n", strlen("c:\test\121"));
		return 0;
	}

	return 0;
}