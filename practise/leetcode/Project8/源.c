#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int check1(int* arr, int num, int q) {
    if (arr[num] >= q)
        return 1;
    else
        return 0;
}
int check2(int* arr, int num, int q) {
    if (arr[num] <= q)
        return 1;
    else
        return 0;
}
int binerysearch1(int q, int* arr, int l, int r) {

    while (l < r) {
        int mid = (l + r >> 1);
        if (check1(arr, mid, q)) r = mid;
        else l = mid + 1;
    }
    if (arr[l] == q)
        return l;
    else
        return -1;
}
int binerysearch2(int q, int* arr, int l, int r) {


    while (l < r) {
        int mid = (l + r + 1 >> 1);
        if (check2(arr, mid, q)) l = mid;
        else r = mid - 1;
    }
    if (arr[l] == q)
        return l;
    else
        return -1;
}

int main() {
    int n = 0, m = 0;
    int arr[100000];
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; i++) {
        int q = 0;
        scanf("%d", &q);
        int begin = binerysearch1(q, arr, 0, n - 1);
        int end = binerysearch2(q, arr, 0, n - 1);
        printf("%d %d\n", begin, end);
    }

}