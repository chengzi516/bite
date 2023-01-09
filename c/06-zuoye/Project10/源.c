#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int x = 5, y = 7;
void swap()
{
	int z;  
	z = x;
	x = y;
	y = z;
} 
int main()
{
	char c2[] = { '\x10', '\xa', '\8' };
	char c1[] = { '1','2','3','4','5' };
	int c3[5 + 3] = { 0, 1, 3, 5, 7, 9 };
	double c4[5] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
	int x = 3, y = 8;
	swap();
	printf("%d,%d\n",x, y);
	return 0;
}