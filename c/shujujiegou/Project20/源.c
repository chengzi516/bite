#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* a, int n) {
	int left = 0, right = n - 1;
	while (left < right)
	{
		int mini = left, maxi = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}

			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[left], &a[mini]);
		if (left == maxi)
		{
			maxi = mini;
		}

		Swap(&a[right], &a[maxi]);

		++left;
		--right;
	}
}
void AdjustDwon(int* a, int n, int root) {
	int child = 2 * root + 1;
	while (child < n) {
		if (a[child] < a[child + 1]&&child+1<n)
			child++;
		if (a[child] > a[root]) {
			Swap(&a[child], &a[root]);
			root = child;
			child = 2 * root + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n) {
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
		AdjustDwon(a, n, i);
	int end = n - 1;
	while (end > 0) {
		Swap(&a[0], &a[n - 1]);
		AdjustDwon(a, n - 1, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)
{
	for (int j = n-1; j>0;j--) {
		for (int i = 0; i < j-1; i++) {
			if (a[i] > a[i + 1])
				Swap(&a[i], &a[i + 1]);
         
		}
	}
}
void quicksort(int* a,int n) {
	
}
int main() {
	int a[] = { 3,2,1,4,6,8,4,3,7,9 };
	BubbleSort(a, 10);
	return 0;
}