#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
int main()
{
	st st;
	stackinit(&st);
	stackpush(&st, 1);
	stackpush(&st, 2);
	stackpop(&st);
	stackpush(&st, 3);
	stackpush(&st, 4);
	stackpop(&st);
	stackpush(&st, 5);
	while (!stackempty(&st))
	{
		printf("%d ", stacktop(&st));
		stackpop(&st);
	}
}