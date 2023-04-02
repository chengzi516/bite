#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void insertsort(int* a, int asize) {
	for (int i = 1; i < asize; i++) {
		int end=i-1;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (a[end] > tmp) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void shellsort(int* a, int asize) {
	int gap = asize;
	while (gap > 1) {
		gap /= 2;
		for (int i = 0; i < asize - gap; i++) {
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
int main() {
	int a[] = { 13,56,32,45,36,127,11,23 };
	shellsort(a, 8);
	for (int i = 0; i < 8; i++)
		printf("%d\n", a[i]);
}