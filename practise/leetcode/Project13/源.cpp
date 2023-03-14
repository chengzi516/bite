#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//�����㷨


//1.��������
// ʱ�临�Ӷ�O(N^2)
// ��������1+2+3+  +n-1��Ϊn��
//����2 5 4 3 6 1���Ƚ�2������һ���������У����������ߣ�����5ʹ2��5��Ϊ�������С����Ų���3����ʱ3��Ҫ�ƶ���2�ĺ��棬5��ǰ�棬ѭ��������
void insertsort(int* a, int n) {
	//[0,end]���򣬽�end+1λ�õ�ֵ�����ȥ����[0,end+1]����
	for (int i = 0; i < n - 1; i++) {  //ѭ����������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {  //�����ǵ�һ�����ƣ�����24561���������1�᲻����ǰ��
			if (a[end] > tmp) {  //�ڶ������ƣ���2563��3��ŵ�2��ǰ��ȥ��
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp; //�����������������������ŵ�end+1��λ��ȥ��
	}
}
//2.ϣ������
//�ڲ�������������Ż�����������
//�Ƚ���Ԥ����������ӽ������������в�������
//Ԥ������һ�ַ��������gap==1,����һ��ֱ�Ӳ��������ٴ�֮ǰ���ж��Ԥ����
void  shellsort(int* a, int n) {

	int gap = n;
	while (gap > 1) {
		gap = gap / 2;//��֤���Ϊ1���ɡ�����һ�β�������ǰ���Ԥ�Ų�����������ӽ����򣬽��͸��Ӷȡ�
		//�����Ϊgap�Ķ�����������.
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
//3.������
//�ѵ�����ṹ��һ�����顣
//���߼��ṹ��һ���������ڽṹ������ȫ����������������ڵ�Ĺؼ������������нڵ�����ֵ��
void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
//Ҫ��ÿһ���������С�ѡ������һ����Ҷ�ӵ�������ʼ�������ｨ���Ǵ�ѣ�Ҫ��С�ѽ��ȽϷ���һ�����ɡ�
void downadjust(int* a, int n, int root) { //���µ����㷨��ǰ����������������ΪС�ѡ�
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n) {
		//ѡ�����Һ�����С����һ����
		if (child + 1 < n && a[child + 1] > a[child]) { //��ֹֻ����������ˡ� 
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
	//���Ѹ��Ӷ�O��N��
	for (int i = (n - 2) / 2; i >= 0; i--) {//�������������һ����Ҷ�ӽڵ㿪ʼ������
		downadjust(a, n, i);
	}
	//�Ž����Ҫ��С�ѡ������Ҫ����ѡ�
	int end = n - 1;
	while (end > 0) {
		swap(&a[0], &a[end]);
		downadjust(a, end, 0);
		end--;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}
//4.ֱ��ѡ������
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
//5.��������,����÷����㷨��˼�롣
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
		//�ұ���С�ķ���ߡ�
		while (a[end] >= key && begin < end) {
			--end;
		}
		a[pivot] = a[end];
		pivot = end; //�¿��γɡ�
		//����Ҵ��
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