#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int c = a < b ? a : b;
//	int i = 0;
//	for ( i = c; i >0; i--)
//	{
//		if (a % i == 0 && b % i == 0)
//			break;
//	}
//	int d = a * b / i;
//	printf("%d\n", d);
//}
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
void reverse_(char* left, char* right)
{
    while (left < right)
    {
        char ret = *left;
        *left = *right;
        *right = ret;

        left++;
        right--;
    }
}

void reverse(char* arr, int len)
{
    reverse_(arr, arr + len - 1);
    while (*arr)
    {
        char* begin = arr;
        while (*arr && (*arr != ' '))
        {
            arr++;
        }
        reverse_(begin, arr - 1);
        if (*begin == ' ')
        {
            arr++;
        }
    }
}
int main()
{
    char arr[100];
    gets(arr);
    int len = strlen(arr);
    reverse(arr, len);
    printf("%s\n", arr);
    system("pause");
    return 0;
}
