#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef struct heap {
	int* arr;
	int capacity;
	int size;
}heap;
void heapinit(heap* hp) {
	assert(hp); //����ʵ��Ķ��Է�����ԡ�
	hp->arr = (int*)malloc(sizeof(int) * 4);
	if (hp->arr == NULL)
		printf("malloc fail\n");
	hp->capacity = 4;
	hp->size = 0;
}
void swap(int* p1, int* p2)
{
	int x = *p1;
	*p1 = *p2;
	*p2 = x;
}
void adjustup(int* arr, int child){
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (arr[child] > arr[parent]) {
			swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
void adjustdown(int* arr, int parent,int n) {
	int child = parent * 2 + 1;
	while (child < n)
	{
		// ѡ�����Һ����д����һ��
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			++child;
		}

		if (arr[child] > arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void heappush(heap* hp, int x) {
	assert(hp);
	//����������Ҫ����
	if(hp->size==hp->capacity){
		int* new = (int*)realloc(hp->arr,sizeof(int) * hp->capacity * 2);
		if (new == NULL)
			printf("realloc fail\n");
		hp->arr = new;
		hp->capacity *= 2;
	}
	//��������
	hp->arr[hp->size++] = x;
	//�ѵĵ���
	adjustup(hp->arr, hp->size - 1); //��������������һ��������±꣬Ҫע��
}

bool heapempty(heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
void heappop(heap* hp) {
	assert(hp);
	assert(!heapempty(hp));
	swap(&hp->arr[0], &hp->arr[hp->size - 1]);
	hp->size--;
	adjustdown(hp->arr, hp->size, 0);
}
void heapinitarray(heap* hp, int* a, int k)
{
	assert(hp);
	hp->arr = (int*)malloc(sizeof(int) * k);
	if (hp->arr == NULL)
	{
		perror("malloc fail");
		return;
	}
	hp->size = k;
	hp->capacity = k;

	// ����
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(hp->arr, hp->size, i);
	}
}
int main() {
	heap hp;
	heapinit(&hp);
	heappush(&hp, 1);
	heappush(&hp, 3);
	heappush(&hp, 4);
	heappush(&hp, 2);
	heappush(&hp, 5);
}