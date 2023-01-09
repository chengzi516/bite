#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main() {
//	int i = 1;
//	while (i <= 10) {
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

//int main() {
//
//	int i = 1;
//	while (i <= 10) {
//		if (i == 5) {
//			break;
//		}
//		printf("%d ", i);
//		i++;
//	}
//}
//int main() {
//
//	int i = 0;
//	while (i < 10)
//	{
//		i++;
//		if (i == 5)
//		{
//			continue;
//		}
//		printf("%d ", i);
//		
//
//	}
//	return 0;
//}
//int main() {
//	int ch=0;
//	while ((ch = getchar()) != EOF) {
//		putchar(ch);
//	}
//	return 0;
//}
//int main() {
//	char charr[20] = { 0 };
//	char ch;
//	scanf("%s", charr);//向字符数组中输入一串字符
//	while (getchar() != '\n') {
//		;
//	}
//	printf("%s", charr);
//	printf("确认字符串输入是否正确（y）？");
//	ch = getchar();
//	if (ch == 'y') {
//		printf("正确");
//	}
//	else
//	{
//		printf("错误");
//	}
//
//
//}
//int main() {
//	int i = 0;
//	for (i = 1; i <= 10; i++) {
//		printf("%d ", i);
//	}
//	return 0;
//
//}
//int main() {
//	int i = 0;
//	for (i = 1; i <= 10; i++) {
//		if (i == 5) {
//			continue;
//		}
//		printf("%d ", i);
//	}
//	return 0;
//
//}
//int main() {
	//for (;;) {
	//	printf("1");
	//}
	/*int i = 0;
	int j = 0;
	for(;i<3;i++)
	{
		for (; j < 3; j++)
		{
			printf("1 ");
		}
	}*/
	/*int i = 1;
	do
	{
		i++;
		if(i==5)
		{
			continue;
		}
		printf("%d ", i);
		
	} while (i <= 10);*/
	/*int i = 1;
	int ret = 1;
	int n = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		ret = ret * i;
	}
	printf("%d", ret);
	return 0;*/
int main() {
	/*int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		int ret = 1;
		for (int j = 1; j <= i; j++)
		{
			ret = ret * j;
		}
		sum += ret;
	}

	printf("%d", sum);*/
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int right = 9;
	int left = 0;
	int key = 7;
	int mid = 0;
	int flag=0;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if(arr[mid]<key)
		{
			left = mid + 1;
		}
		else
		{
			printf("找到了");
			flag += 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("找不到");
	}
	return 0;
}