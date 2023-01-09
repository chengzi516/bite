#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,(3,4),5 };
//    printf("%d\n", sizeof(arr));
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    char str[] = "hello bit";
//    printf("%d %d\n", sizeof(str), strlen(str));
//    return 0;
//}
//#include<string.h>
//#include<stdio.h>
//int main()
//{
//	char acX[] = "abcdef";
//	char acY[] = { 'a','b','c','d','e','f' };
//	printf("%d %d\n", sizeof(acX), sizeof(acY));
//	printf("%d %d\n", strlen(acX), strlen(acY));
//
//}
//#include<stdio.h>
//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 6,7,8,9,10};
//	for (int i = 0; i < 5; i++)
//	{
//		int temp;
//		temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		printf("arr1[%d]=%d ", i, arr1[i]);
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		printf("arr2[%d]=%d ", i, arr2[i]);
//	}
//}
//#include<stdio.h>
//#include<string.h>
//void init(int* arr)
//{
//	for (int i = 0; i < 5; i++)
//	{
//		arr[i] = 0;
//	}
// }
//void print(int * arr)
//{
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void reverse(int arr[])
//{
//	int l = 0;
//	int r = 4;
//	
//		while (l<r)
//		{
//			int tmp = arr[l];
//			arr[l] = arr[r];
//			arr[r] = tmp;
//			l++;
//			r--;
//		}
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3,4,5 };
//	int arr3[] = { 1,2,3,4,5 };
//	init(arr1);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	print(arr2);
//	printf("\n");
//	reverse(arr3);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr3[i]);
//	}
//}
#include<stdio.h>
