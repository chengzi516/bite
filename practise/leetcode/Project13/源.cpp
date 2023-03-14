#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//排序算法


//1.插入排序
// 时间复杂度O(N^2)
// 最坏情况逆序：1+2+3+  +n-1，为n方
//例如2 5 4 3 6 1，先将2当作是一个有序数列，合理，往下走，插入5使2，5成为有序数列。接着插入3，此时3就要移动到2的后面，5的前面，循环往复。
void insertsort(int* a, int n) {
	//[0,end]有序，将end+1位置的值插入进去，让[0,end+1]有序
	for (int i = 0; i < n - 1; i++) {  //循环的趟数。
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {  //这里是第一层限制，例如24561这种情况，1会不断往前走
			if (a[end] > tmp) {  //第二层限制，如2563，3会放到2的前面去。
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp; //不管是上面哪种情况，都会放到end+1的位置去。
	}
}
//2.希尔排序
//在插入排序基础上优化得来的排序。
//先进行预排序，让数组接近有序，再来进行插入排序。
//预排序是一种分组的排序。gap==1,就是一种直接插入排序。再次之前会有多次预排序。
void  shellsort(int* a, int n) {

	int gap = n;
	while (gap > 1) {
		gap = gap / 2;//保证最后为1即可。进行一次插入排序，前面的预排不过是在让其接近有序，降低复杂度。
		//将间隔为gap的多组数据排序.
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (a[end] > tmp) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}

}
//3.堆排序
//堆的物理结构是一个数组。
//而逻辑结构是一颗树。堆在结构上是完全二叉树，并且任意节点的关键字是字数所有节点的最大值。
void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
//要将每一棵树都变成小堆。从最后一个非叶子的子树开始调。这里建的是大堆，要建小堆将比较符号一环即可。
void downadjust(int* a, int n, int root) { //向下调整算法的前提是左右子树必须为小堆。
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n) {
		//选出左右孩子里小的那一个。
		if (child + 1 < n && a[child + 1] > a[child]) { //防止只有左孩子溢出了。 
			++child;
		}
		if (a[child] > a[parent]) {
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
	}
}
void heapsort(int* a, int n) {
	//建堆复杂度O（N）
	for (int i = (n - 2) / 2; i >= 0; i--) {//倒着来，从最后一个非叶子节点开始调整。
		downadjust(a, n, i);
	}
	//排降序就要建小堆。升序就要建大堆。
	int end = n - 1;
	while (end > 0) {
		swap(&a[0], &a[end]);
		downadjust(a, end, 0);
		end--;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}
//4.直接选择排序
void selectsort(int* a, int n) {
	int begin = 0; int end = n - 1;
	while (begin < end) {
		int max = begin;; int min = begin;
		for (int i = begin; i <= end; i++) {
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		swap(&a[begin], &a[min]);
		swap(&a[max], &a[end]);
		begin++;
	}

}
//5.快速排序,会采用分治算法的思想。
int getmid(int* a, int left, int right) {
	int mid = (left + right) >> 1;

}
void quciksort(int* a, int left, int right) {
	if (left >= right) {
		return;
	}
	int index = getmid(a, left, right);
	swap(&a[left], &a[index]);
	int begin = left; int end = right;
	int pivot = begin;
	int key = a[begin];
	while (begin < end) {
		//右边找小的放左边。
		while (a[end] >= key && begin < end) {
			--end;
		}
		a[pivot] = a[end];
		pivot = end; //新坑形成。
		//左边找大的
		while (a[begin] <= key && begin < end) {
			++begin;
		}
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;
	quciksort(a, left, pivot - 1);
	quciksort(a, pivot + 1, right);
}
void  heapsofttest() {
	int a[] = { 3,5,2,7,6,1,9,4,0 };
	heapsort(a, sizeof(a) / sizeof(int));
}
void  shellsofttest() {
	int a[] = { 2,4,5,6,1 };
	shellsort(a, 5);
	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);
}
void  insertsofttest() {
	int a[] = { 2,4,5,6,1 };
	insertsort(a, 5);
	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);
}
int main() {
	//insertsofttest();
	//shellsofttest();
	heapsofttest();
}