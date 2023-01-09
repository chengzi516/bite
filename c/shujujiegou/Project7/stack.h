#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
typedef int datatype;
typedef struct stack
{
	datatype* a;
	int top;
	int capacity;
}st;

void stackinit(st* ps) ;
void stackdestory(st* ps);
void stackpush(st* ps, datatype x);
void stackpop(st* ps);
datatype stacktop(st* ps);
int stacksize(st* ps);
bool stackempty(st* ps);
