#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//��дջ��������õ��Ƕ�̬ջ����̬������ջ��С�ڴ���ܵ���С�����ơ�
// ջ���ص�����Ƚ������������һ��һ�����ŷ���û�г��ڵ������Ҫ��ȥʱ�ôӶ�β��ȥ��
typedef int datatype;
typedef struct stack {
	datatype* arr;
	int maxsize;
	int currentsize;  //����˳���һ�����Զ�̬�ڴ��������������ڴ档
}st;

//��ʼ��
void stackinit(st* ps) {
	ps->arr = (datatype*)malloc(sizeof(datatype) * 4);
	ps->maxsize = 4;
	ps->currentsize = 0; // �ȷ���4���ռ��ջ��maxsize��currentsize��Ҫ����á�
}
//��ʵ��˳���һ�����������ж�ջ�Ƿ������������һ��������
void stackisfull(st* ps) {
	if (ps->currentsize == ps->maxsize) {
		datatype* tmp = realloc(ps->arr, ps->maxsize * 2 * sizeof(datatype));  //���˾�����������
		if (tmp == NULL)
			printf("realloc fail\n");
		ps->arr = tmp;
		ps->maxsize *= 2;
	}
}
//��ջ����
void stackpull(st* ps, datatype x) {
	stackisfull(ps);
	ps->arr[ps->currentsize] = x;
	ps->currentsize++;
}
//��ջ����
void stackpop(st* ps) {
	assert(ps);
	ps->currentsize -= 1;
}
//����ջ��Ԫ��
datatype stackgetpop(st* ps) {
	assert(ps);
	return ps->arr[ps->currentsize-1];
}
//��ջ��Ϊ��
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