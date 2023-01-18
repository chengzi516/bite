#define _CRT_SECURE_NO_WARNINGS 1
#define max 10
#include<stdio.h>
void check(int* arr, int num)
{
	//œ»≈≈–Ú
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	//À´÷∏’Î
	int* first = arr;
	int* second = arr + 1;
	int flag = 2;
	while(flag)
	if ((*first) == (*second))
	{
		first++;
		second++;
	}
	else if ((*first) != (*second))
	{
		if (*second == (*(second + 1)))
		{
			first++;
			second++;
		}
		else
		{
			printf("%d ", *second);
			first = second ;
			second = first + 1;
			flag--;
		}
		
         }
}
int main()
{
	int arr[max] = { 1,1,2,2,3,4,5,5,6,6 };
	check(arr,10);
}