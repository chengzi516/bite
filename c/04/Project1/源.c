#define _CRT_SECURE_NO_WARNINGS 1
//type  arrname[const n];
////type是数组的元素类型
////arrname是数组名
////const n是常量表达式，用以指定数组大小
//int arr1[10] = { 1,2,3 };
//int arr3[3] = { 1,2,3 };
//#include<stdio.h>
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c' };
//	printf("%s\n", arr1);
//	printf("%s", arr2);
//}
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	//输入
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++)
//	{
//		arr[i] = i;
//	}
//	//输出
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//}
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[1]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("&arr[%d]=%p\n", i, &arr[i]);
//
//	}
//	return 0;
//}
//int arr[3][3] = { 1,2,3 };
#include<stdio.h>
int main()
{
	int arr[3][3] = { 0 };
	//输入
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = i + j;
		}
	}//输出
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("arr[%d][%d]=%d\n", i, j, arr[i][j]);
		}
	}
		return 0;
}