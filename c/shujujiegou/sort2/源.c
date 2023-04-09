#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//快排
void quicksort(int* a, int left,int right) {
	if (left >= right)
		return;
	int key = a[left + right >> 1];
	int l = left - 1;
	int r = right + 1;
	while (l < r) {
		do { l++; } while (a[l] < key);
		do { r--; } while (a[r] > key);
		if (l < r)
			swap(&a[l], &a[r]);
	}
	quicksort(a, left, r);
	quicksort(a, r+ 1, right);
}
//快排的非递归实现,借助栈来做
typedef struct stack
{
	int* arr;
	int size;
	int capacity;
}st;
void stackinit(st* q) {
	q->arr = (int*)malloc(sizeof(int) * 4);
	q->size = 0;
	q->capacity = 4;
}
void stackpush(st* q, int x) {
	if (q->capacity == q->size) {
		int* new = (int*)realloc(q->arr, q->capacity * 2);
		if (new == NULL)
			perror("realloc fail\n");
		q->arr = new;
		q->capacity *= 2;
	}
	q->arr[q->size++] = x;

}
//弹出时顺便取得这个值
int stackpop(st* q) {
	assert(q);
	assert(q->size != 0);
	return q->arr[--q->size];
}
bool stackisempty(st* p) {
	return p->size == 0;
}
int _quicksort(int* a,int left,int right) {
	if (left >= right)
		return;
	int key = a[left + right >> 1];
	int l = left - 1;
	int r = right + 1;
	while (l < r) {
		do { l++; } while (a[l] < key);
		do { r--; } while (a[r] > key);
		if (l < r)
			swap(&a[l], &a[r]);
	}
	return r;
}


void quicksortnonr(int* a,int left,int right) {
	st s;
	stackinit(&s);
	stackpush(&s, right);
	stackpush(&s, left);
	while (!stackisempty(&s)) {
		int begin = stackpop(&s);
		int end = stackpop(&s);
		int key = _quicksort(a, begin, end);
		if (key + 1 < end) {
			stackpush(&s, end);
			stackpush(&s,key+1 );
		}
		if (begin + 1 < key) {
			stackpush(&s, key-1);
			stackpush(&s, begin);
		}

	}
}
int main() {
	int arr[] = { 12,43,100,45,26,37,47,89,24,28 };
	quicksort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	//quicksortnonr(arr, 0, 9);
	//for (int i = 0; i < 10; i++)
	//	printf("%d ", arr[i]);
	/*st s;
	stackinit(&s);
	stackpush(&s, 2);
	stackpush(&s, 3);
	stackpush(&s, 5 );
	stackpush(&s, 7);
	while (!stackisempty(&s))
		printf("%d ", stackpop(&s));
	*/

}