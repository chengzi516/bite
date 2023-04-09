#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//��������������Ϊ��
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//��������
void insertsort(int* nums, int numssize) {
	for (int end = 0; end < numssize-1; end++) {
		int key = nums[end + 1];
		while (end >= 0)  //end>=0֮�����е��ڣ�����ΪҪ��ֹkey���ŵ���һλ��
		{
			if (key < nums[end]) {
				nums[end + 1] = nums[end];
				end--;
			}
			else {
				break;  //�������������ͻ�ֹͣ����ʱend+1����key�����λ�á�
			}
		}
		nums[end + 1] = key;
	}
}
//ϣ������,ϣ�������ǽ��ж��Ԥ�������ִ��һ�β������򣬵���ִ�д˴β�������ʱ�����Ѿ��ӽ������ˡ�
void shellsort(int* nums, int numssize) {
	int gap = numssize;
	while (gap > 1) {
		gap /= 2;
		for (int end = 0; end < numssize - gap; end++) {  //����������ط�ʮ����Ҫ��end֮������++����+gap����Ϊ�������Խ�����Ԥ����ͬʱ���С�numsizeҲҪ-end����Ȼ��Խ�硣
			int key = nums[end + gap];
			while (end >= 0)  //end>=0֮�����е��ڣ�����ΪҪ��ֹkey���ŵ���һλ��
			{
				if (key < nums[end]) {
					nums[end + gap] = nums[end];
					end -= gap;
				}
				else {
					break;  //�������������ͻ�ֹͣ����ʱend+1����key�����λ�á�
				}
			}
			nums[end + gap] = key;
		}
	}
}
//������
//��һ�����Ƚ��Ѻ���д�ѵĺ���
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
//���ϵ����㷨�����µ����㷨�ǽ����ѵĺ��Ĳ��裡���ｨ�Ķ��Ǵ��
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
void adjustdown(int* arr, int root,int n) { //�����϶ഫ��һ��n����Ϊ��Ҫ�õ�n������root�Ľ�����
	int child = 2 * root + 1;
	while (child < n) {
		if (child+1<n &&arr[child] < arr[child+1])  //����child+1�������Խ������⡣
			child++;   //��һ����Ҫѡ�����������нϴ��һ��
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
	adjustup(p->arr, p->size-1); //��1����Ϊsize���ǻ�������һ����1
	
}
//������������д�������ˡ�
//�����Ҫ����ѣ������Ҫ��С�ѡ�
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
//��������
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
//ð������
void bubblesort(int* nums, int numssize) {
	for (int j = 0; j < numssize-1;j++) {
		for (int i = 0; i < numssize - 1-j; i++) {
			if (nums[i] > nums[i + 1])
				swap(&nums[i], &nums[i + 1]);
		}
	}
}
//���ŷǵݹ�汾
//�鲢����
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
