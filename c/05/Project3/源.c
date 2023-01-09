#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define n 10
float fun(float* arr, float* pmax, float* pmin)
{
	float sum = 0;
	float* p;
	for (p = arr; p < arr + n; p++)
	{
		sum += *p;
		if (*p > *pmax)
		{
			*pmax = *p;
		}
		if (*p < *pmin)
		{
			*pmin = *p;
		}
	}
}
int main()
{
	
	float num[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%f", &num[i]);
	}
	float a = num[0];
	float b = num[0];
	float* pmax = &a;
	float* pmin = &b;
	fun(num, pmax, pmin);
	printf("%f %f", *pmax, *pmin);
	return 0;
}