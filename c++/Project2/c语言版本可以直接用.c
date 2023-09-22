#define _CRT_SECURE_NO_WARNINGS 1

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"



//建立一个point点结构，存储其x，y坐标。
struct Point {
    double x, y;
};
//cmp函数分别返回x，y坐标的大小比对
bool cmp_x(struct Point a, struct Point b) {
    return a.x < b.x;
}
bool cmp_y(struct Point a, struct Point b) {
    return a.y < b.y;
}

//计算ab两点距离
double dist(struct Point a, struct Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 排序函数
void sort(int* arr, int n, int (*cmp)(const void*, const void*)) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (cmp(&arr[j], &arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
double closest_pair(struct Point* a, int n) {
    // 如果传入的只有两个点，直接计算它们之间的距离即可
    if (n == 2) {
        return dist(a[0], a[1]);
    }
    // 如果传入的有三个点，计算三对距离中的最小值
    if (n == 3) {
        return min(dist(a[0], a[1]), min(dist(a[1], a[2]), dist(a[2], a[0])));
    }
    // 如果传入多个点，使用分治算法进行求解
    int m = n / 2; // 将点集分为两半，m为分界点
    double x = a[m].x; // 取分界点的x坐标
    //核心步骤
    double d = min(closest_pair(a, m), closest_pair(a + m, n - m)); // 递归求解左右两个子集的最近点对距离，d即为要返回的最小距离

    //递归完成后回到主函数，此时已经求出了左右两个区域内的最小距离，此时应该考虑左右合并起来的最小距离对

    // 将左右两个子集按照y坐标合并
    sort(a, a + n, cmp_y);
    struct Point b[100]={0};
    int k = 0; // b数组的下标
    for (int i = 0; i < n; i++) {
        if (fabs(a[i].x - x) < d) { // 判断点与分界点的横坐标之差是否小于d
            for (int j = k - 1; j >= 0 && a[i].y - b[j].y < d; j--) {
                // 从b数组的末尾开始向前遍历，判断点与b数组中已存放的点的纵坐标之差是否小于d
                // 如果小于d，则计算这两个点之间的距离，并更新最小距离d
                d = min(d, dist(a[i], b[j]));
            }
            b[k++] = a[i]; // 将满足条件的点加入到b数组中
        }
    }
    return d; // 返回最近点对的距离
}
int main() {
    int n; //n为点的数量
    printf("please put the number of point");
    scanf("%d",&n);
    struct Point a[100]={0};
    printf("put the coordinate in here(x first,y second)");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    //因为是按x来分成两部分，所以需要按横坐标进行排序
    sort(a, a + n, cmp_x);
    //按closepair算法输出即可
    printf("the shortest distance is %f",closest_pair(a, n));
   
    return 0;
}

