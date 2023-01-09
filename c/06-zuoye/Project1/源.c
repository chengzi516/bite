#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        *(p + i) = 0;
//    }
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//#include<stdio.h>
//void print(int* arr)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *arr);
//		arr += 1;
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	print(arr);
//}
//#include<stdio.h>
//void verse(char* s)
//{
//	char* left=s;
//	char* right = s+strlen(s)-1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		right--;
//		left++;
//	}
//}
//int main()
//{
//	char arr[10000] = {0};
//	gets(arr);//用scanf会到空格就停止
//	verse(arr);
//	printf("%s", arr);
//}
//#include<stdio.h>
//int main()
//{
//	for (int i = 0; i < 7; i++)
//	{
//		for (int j = 1; j < i+2; j+=2)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	/*for (int i = 0; i < 6; i++)
//	{
//		for (int j = 11; j >= 1; j - 2)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}*/
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 99999; i++)
//	{
//		int tmp = i;
//		int count = 0;
//		int sum = 0;
//
//		while (tmp)
//		{
//			tmp /= 10;//各位数
//			count++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow((tmp % 10), count);
//			tmp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d是水仙花数\n", i);
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int s;
//	scanf("%d", &s);
//	int sum=0;
//	for (int i = 0; i < 5; i++)
//	{
//		if (s != 2)
//		{
//			for (int j = 0; j < 4; j++)
//			{
//				s = s * 10;
//			}
//		}
//		s += s;
//		sum += s;
//		
//	}
//	printf("%d", sum);
//}