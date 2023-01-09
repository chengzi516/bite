#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	for (int i = 1; i < 10; i++)
//	{
//
//		for (int j = 1; j < 10; j++)
//		{
//			printf("%d*%d=%d ", i, j, i * j);
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 34,56,23,54,67,25,26,98,12,30 };
//	int i;
//	for ( i = 0; i < 10; i++)
//	{
//		if (arr[i] > arr[i + 1])
//		{
//			
//			arr[i+1] = arr[i];
//			
//		}
//	}
//	printf("%d", arr[9]);
//
//	return 0;
//}
//int main()
//{
//	double sum = 0.0;
//	for (int i = 1; i < 101; i++)
//	{
//		if (i % 2 == 0)
//		{
//			sum += (-(1.0 / i));
//		}
//		else
//		{
//			sum += (1.0 / i);
//		}
//	 
//
//	}
//	printf("%lf", sum);
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 12,34,54,57,87,98,102,140,154,167 };
//	int left = 0;
//	int right = 9;
//	int mid = 0;
//	int key = 102; //需要查找的值
//	int flag = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if(arr[mid]<key)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了");
//			flag++;
//			//break;
//		}
//	}
//	if (flag == 0)
//	{
//		printf(" 找不到");
//	}
//}
int main()
{
	for (int i = 0; i <= 100; i++)
	{
		if (i / 10 == 9 || i % 10 == 9)
		{
			printf("%d ", i);
		}
	}
	return 0;
}