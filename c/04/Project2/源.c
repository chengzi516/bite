#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void bubblesort(int arr[],int sz)
{
	for (int i = 0; i < sz-1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 3,6,8,2,1,9,5,4,7,0 };
	int sz = sizeof(arr) / sizeof(arr[1]);
	bubblesort(arr,sz);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
int main()
{
	printf("hello world");
}