#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
void stackinit(st* ps)
{
	ps->a = (datatype*)malloc(sizeof(datatype) * 4);
	ps->capacity = 4;
	ps->top = 0;
}
void stackpush(st* ps, datatype x)
{
	assert(ps);
	if (ps->top == ps->capacity) {
		datatype* tmp = realloc(ps->a, ps->capacity * 2 * sizeof(datatype));
		if (tmp == NULL)
			printf("fail!");
		ps->a=tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void stackpop(st* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
datatype stacktop(st* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
int stacksize(st* ps)
{
	assert(ps);
	return ps->top;
}

bool stackempty(st* ps)
{
	assert(ps);
	return ps->top == 0;
}