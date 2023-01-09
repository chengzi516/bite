#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int factorial(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return factorial(n - 1) * n;
//	}
//}
//int count = 0;
//int fib(int n)
//{
//	if (n == 3)
//	{
//		count++;
//	}
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fib(n-2) + fib(n - 1);
//	}
//}
//int factorial(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 10;
//	printf("%d", factorial(n));
//}
//int add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 3;
//	int b = 5;
//	int ret = 0;
//	ret = add(a, b);
//	printf("%d", ret);
//	return 0;
//}
//#include<stdio.h>
//double cifang(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if(k>0)
//	{
//		return n * cifang(n, k - 1);
//	}
//	else
//	{
//		return 1.0 / cifang(n, -k);
//	}
//
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	double ret = 0.0;
//	scanf("%d %d", &n, &k);
//	ret=cifang(n, k);
//	printf("%.2lf", ret);
//}
#include<stdio.h>
#include<string.h>
//void reverse_string(char* arr)
//{
//	int left = 0;
//	int right = strlen(arr)-1;
//	while (right > left)
//	{
//		char temp = *(arr+right);
//		*(arr + right) = *(arr+left);
//		*(arr+left) = temp;
//		right--;
//		left++;
//	}
//}
int Strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

void reverse_string(char* str)
{
	int len = Strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if(Strlen(str+1)>=2)
		reverse_string(str+1);
	
	*(str + len - 1) = tmp;
}

int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	printf("%s", arr);
}
