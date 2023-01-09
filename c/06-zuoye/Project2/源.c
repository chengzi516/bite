#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void pailie(int arr[],int sz)
{
	int* n1 = arr;
	int* n2=arr + sz - 1;
	int tmp = 0;
	for (int i = 0; i < sz / 2; i++)
	{
		if (( * n1) % 2 == 0)
		{
			if ((*n2) % 2 == 0)
			{
				n2--;
			}
			
			
				tmp = *n1;
				*n1 = *n2;
				*n2 = tmp;
				
				n2--;
			
		}
		n1++;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(arr) / sizeof(arr[1]);
	pailie(arr,sz);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++)
	{
		printf("%d ", arr[i]);
	}
}