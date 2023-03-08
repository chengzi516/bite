#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void mergesort(int* arr, int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r >> 1);
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
    int tmp[100000];
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r) {
        if (arr[i] > arr[j]) {
            tmp[k++] = arr[j++];

        }
        else {
            tmp[k++] = arr[i++];
        }
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    for (int i = l, k = 0; i <= r; i++, k++) {
        arr[i] = tmp[k];
    }
}
int main() {
    int n = 0;
    scanf("%d", &n);
    int arr[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}