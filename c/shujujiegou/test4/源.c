#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//书写栈，这里采用的是动态栈，静态的数组栈大小内存会受到不小的限制。
// 栈的特点就是先进后出，将数据一个一个挨着放入没有出口的隧道，要出去时得从队尾出去。
typedef int datatype;
typedef struct stack {
	datatype* arr;
	int maxsize;
	int currentsize;  //就像顺序表一样，以动态内存分配的行书来给内存。
}st;

//初始化
void stackinit(st* ps) {
	ps->arr = (datatype*)malloc(sizeof(datatype) * 4);
	ps->maxsize = 4;
	ps->currentsize = 0; // 先分配4个空间给栈，maxsize和currentsize都要定义好。
}
//和实现顺序表一样，单独将判断栈是否满了提出来做一个函数。
void stackisfull(st* ps) {
	if (ps->currentsize == ps->maxsize) {
		datatype* tmp = realloc(ps->arr, ps->maxsize * 2 * sizeof(datatype));  //满了就扩大两倍。
		if (tmp == NULL)
			printf("realloc fail\n");
		ps->arr = tmp;
		ps->maxsize *= 2;
	}
}
//入栈操作
void stackpull(st* ps, datatype x) {
	stackisfull(ps);
	ps->arr[ps->currentsize] = x;
	ps->currentsize++;
}
//出栈操作
void stackpop(st* ps) {
	assert(ps);
	ps->currentsize -= 1;
}
//返回栈顶元素
datatype stackgetpop(st* ps) {
	assert(ps);
	return ps->arr[ps->currentsize-1];
}
//将栈置为空
void stacknull(st* ps) {
	ps->currentsize = 0;
}
int main() {
	st st;
	stackinit(&st);
	stackpull(&st, 1);
	stackpull(&st, 2);
	stackpull(&st, 3);
	stackpull(&st, 4);
	stackpull(&st, 5);
	stackpop(&st);
	datatype a = stackgetpop(&st);
	printf("%d", a);
}