#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	total += money;
//	empty += money;
//
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2+empty%2;
//	}
//	printf("%d", total);
//}

//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hello bit\n");
//	}
//	return 0;
//}
void my_strcpy(char* a,char* b)
{
	int i = 0;
	while (a[i] != '\0')
	{
		b[i] = a[i];
		i++;
	}
	b[i] = '\0';

}
int main()
{
	char a[] = "abcdef";
	char b[] = "";
	my_strcpy(a,b);
	printf("%s", b);
	return 0;
}
//int my_strlen(char* a)
//{
//	int count = 0;
//	int i = 0;
//	while (a[i] != '\0')
//	{
//		count++;
//		i++;
//	}
//	return count;
//}
//int main()
//{
//	char a[] = "abcdef";
//	printf("%d", my_strlen(a));
//}