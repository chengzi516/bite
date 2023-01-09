#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b==2) + (a==3) == 1) &&((b==2) + (e==4) == 1) &&((c==1) + (d==2) == 1) &&((c==5) + (d==3) == 1) &&((e==4) + (a==1) == 1))
//						{
//							if(a*b*c*d*e == 120)
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//} 

//int main()
//{
//	int arr[10][10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			if (i == j)
//				arr[i][j] = 1;
//			if(i>=2&&j>=1)
//				arr[i][j]=
//	}
//	}
//}

//void findk(int arr[3][3], int r, int c,int k)
//{
//	int x = 0;
//	int y = c - 1;
//	while (x<=r-1 && y>=0)
//	{
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			printf("find it");
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 7;
//	findk(arr, 3, 3,k);
//}
void reverse(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char arr[], int k)
{
	int len = strlen(arr);
	k %= len;
	reverse(arr, arr+k-1);
	reverse(arr + k, arr + len - 1);
	reverse(arr, arr + len - 1);

}
//int main()
//{
//	char arr[] = "abcd";
//	int k = 2;
//	left_move(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}
int is_left_move(char arr1[],char arr2[])
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len1 != len2)
		return 0;
	for (int i = 0; i < len1 ; i++)
	{
		left_move(arr1, 1);
		if (strcmp(arr1, arr2) == 0)
			return 1;
	}
	return 0;
}
//int main()
//{
//	char arr1[] = "aabcd";
//	char arr2[] = "bcdaa";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("yes");
//	else
//		printf("no");
//}


//int main()
//{
//	char killer = 0;
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer!='a') + (killer=='c') + (killer=='d') + (killer!='d') == 3)
//		{
//			printf("%c\n", killer);
//		}
//	}
//	return 0;
//}
//



//int main()
//{
//	int arr[10][10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0)
//				arr[i][j] = 1;
//			if (i == j)
//				arr[i][j] = 1;
//			if (i >= 2 && j >= 1)
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		int j = 0;
//		for (j = 0; j <= i; j++)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr);
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr + 1);
//}

void PrintArr(int(*arr)[3],int a,int b) {
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			printf("%d ", arr[i][j]);
		}
	}
}
int int_cmp(void* p1, void* p2)
{
	return (*(int*)p1 - *(int*)p2);
}
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void* base, size_t sz, size_t width, int (*cmp)(const void* e1, const void* e2))
{
	size_t i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		size_t j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
int main()
{
	/*int arr[] = { 1,3,4,6,7,4,2,8,0 };
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]);i++)
	{
		printf("%d ", arr[i]);
	}*/
	int arr[] = { 1,2,3 };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(&arr));

}