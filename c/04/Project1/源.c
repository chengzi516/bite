#define _CRT_SECURE_NO_WARNINGS 1
//type  arrname[const n];
////type�������Ԫ������
////arrname��������
////const n�ǳ������ʽ������ָ�������С
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
//	//����
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++)
//	{
//		arr[i] = i;
//	}
//	//���
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
	//����
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = i + j;
		}
	}//���
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("arr[%d][%d]=%d\n", i, j, arr[i][j]);
		}
	}
		return 0;
}