#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//以下排序都是升序为例
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//插入排序
void insertsort(int* nums, int numssize) {
	for (int end = 0; end < numssize-1; end++) {
		int key = nums[end + 1];
		while (end >= 0)  //end>=0之所以有等于，是因为要防止key会排到第一位。
		{
			if (key < nums[end]) {
				nums[end + 1] = nums[end];
				end--;
			}
			else {
				break;  //当不满足条件就会停止，此时end+1就是key插入的位置。
			}
		}
		nums[end + 1] = key;
	}
}
//希尔排序,希尔排序是进行多次预排序，最后执行一次插入排序，但在执行此次插入排序时数组已经接近有序了。
void shellsort(int* nums, int numssize) {
	int gap = numssize;
	while (gap > 1) {
		gap /= 2;
		for (int end = 0; end < numssize - gap; end++) {  //这里的两个地方十分重要，end之所以是++而非+gap是因为这样可以将多组预排序同时进行。numsize也要-end，不然会越界。
			int key = nums[end + gap];
			while (end >= 0)  //end>=0之所以有等于，是因为要防止key会排到第一位。
			{
				if (key < nums[end]) {
					nums[end + gap] = nums[end];
					end -= gap;
				}
				else {
					break;  //当不满足条件就会停止，此时end+1就是key插入的位置。
				}
			}
			nums[end + gap] = key;
		}
	}
}
//堆排序
//第一步是先建堆和书写堆的函数
typedef struct heap {
	int* arr;
	int size;
	int capacity;
}hp;
void heapinit(hp* p) {
	assert(p);
	p->arr = (int*)malloc(sizeof(int) * 4);
	p->capacity = 4;
	p->size = 0;
}
bool heapisempty(hp* p) {
	return p->size==0;
}
//向上调整算法和向下调整算法是建立堆的核心步骤！这里建的都是大堆
void adjustup(int* arr,int root) {
	int parent = (root - 1) / 2;
	while (root > 0) {
		if (arr[root] > arr[parent]) {
			swap(&arr[root], &arr[parent]);
			root = parent;
			parent = (root - 1) / 2;
		}
		else
			break;
	}
}
void adjustdown(int* arr, int root,int n) { //比向上多传入一个n是因为需要用到n来控制root的结束。
	int child = 2 * root + 1;
	while (child < n) {
		if (child+1<n &&arr[child] < arr[child+1])  //限制child+1可能造成越界的问题。
			child++;   //这一步是要选出两个孩子中较大的一个
		if (arr[child] > arr[root]) {
			swap(&arr[child], &arr[root]);
			root = child;
			child = 2 * root + 1;
		}
		else
			break;
	}
}
void heappush(hp* p, int x) {
	assert(p);
	if (p->capacity == p->size) {
		int* tmp = (int*)realloc(p->arr, sizeof(int) * (p->capacity) * 2);
		if (p == NULL)
			printf("realloc fail\n");
		p->arr = tmp;
		p->capacity *= 2;
	}
	p->arr[p->size++] = x;
	adjustup(p->arr, p->size-1); //减1是因为size总是会大于最后一个数1
	
}
//接下来就是书写堆排序了。
//升序就要建大堆，降序就要建小堆。
void  heapsort(int* nums,int numssize) {
	/*for (int n = 0; n < numssize; n++) {
		adjustup(nums, n);
	}*/
	for (int n = (numssize - 1 - 1) / 2; n >= 0; n--) {
		adjustdown(nums, n, numssize);
	}
	int end = numssize - 1;
	while (end>0) {
		swap(&nums[0], &nums[end]);
		adjustdown(nums,0,end);
		end--;
	}
}
//快速排序
void quicksort(int* nums, int left, int right) {
	if (left >= right)
		return;
	int key = nums[left + right >> 1];
	int i = left - 1;
	int j = right + 1;
	while (i < j) {
		do { i++; } while (nums[i] < key);
		do { j--; } while (nums[j] > key);
		if (i < j)
			swap(&nums[i], &nums[j]);
		
	}
	quicksort(nums, left, j);
	quicksort(nums, j+ 1, right);
}
//冒泡排序
void bubblesort(int* nums, int numssize) {
	for (int j = 0; j < numssize-1;j++) {
		for (int i = 0; i < numssize - 1-j; i++) {
			if (nums[i] > nums[i + 1])
				swap(&nums[i], &nums[i + 1]);
		}
	}
}
//快排非递归版本
//归并排序
int main() {
	int arr[] = { 12,34,65,34,26,67,88 };
	//insertsort(arr, 7);
	//shellsort(arr, 7);
	//heapsort(arr, 7);
	//quicksort(arr, 0, 6);
	bubblesort(arr, 7);
	for (int i = 0; i < 7; i++) {
		printf("%d ", arr[i]);
	}
}
