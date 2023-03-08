#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void quick_sort(int* arr, int l, int r) {
    if (l >= r)
        return;
    int i = l - 1, j = r + 1;
    int x = arr[(l + r >> 1)];
    while (i < j) {
        do {
            i++;
        } while (arr[i] < x);
        do {
            j--;
        } while (arr[j] > x);
        if (i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    quick_sort(arr, l, j);
    quick_sort(arr, j + 1, r);
}
int main() {
    int n = 0;
    scanf("%d", &n);
    int arr[10000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
