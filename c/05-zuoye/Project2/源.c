#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int numberof1(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//		{
//			count++;
//			n = n / 2;
//		}
//
//	}
//	return count;
//}
//int number0f1(int n)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((n >> i) & 1 == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int number0f1(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//}
//void Print(int n)
//{
//	printf("奇数位：");
//	for (int i = 0; i <= 30; i += 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	printf("偶数位：");
//	for (int i = 1; i <= 30; i += 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	Print(n);
//	return 0;
//}
//int main()
//{
//	int a, b;
//	scanf("%d", &a);
//	scanf("%d", &b);
//	int ret = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (((a >> i) & 1) != ((b >> i) & 1))
//		{
//			ret++;
//		}
//	}
//	printf("%d", ret);
//}
//int main()
//{
//	int a, b;
//		scanf("%d", &a);
//		scanf("%d", &b);
//		int m = a ^ b;
//		int count = 0;
//		while (m)
//		{
//			m = m & (m - 1);
//			count++;
//		}
//		printf("%d", count);
//
//}
int getdays(int y, int m)
{
    int day = 0;
    switch (m)
    {
    case 1:
    case 5:
    case 3:
    case 7:
    case 8:
    case 10:
        day = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        day = 30;
        break;
    case 2:
    {
        day = 28;
        if (((y%4==0)&&(y%100!=0)) || (y%400==0))
            {
            day++;
            }
        break;
    }
    }
    return day;
}
int main() {
    int y = 0;
    int m = 0;
    scanf("%d %d", &y, &m);
    int ret = getdays(y, m);
    printf("%d", ret);
    return 0;
}
