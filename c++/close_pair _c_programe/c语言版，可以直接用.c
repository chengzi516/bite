#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// 定义点的结构体
typedef struct {
    double x;
    double y;
} Point;

// 比较函数，用于qsort排序
int compareX(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->y - p2->y);
}

// 计算两点之间的距离
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// 暴力解法，计算最接近点对的距离
double bruteForce(Point P[], int n) {
    double minDist = DBL_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dist = distance(P[i], P[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}

// 分治法，计算最接近点对的距离
double closestUtil(Point P[], int n) {
    if (n <= 3) {
        return bruteForce(P, n);
    }

    int mid = n / 2;
    Point midPoint = P[mid];

    double dl = closestUtil(P, mid);
    double dr = closestUtil(P + mid, n - mid);
    double d = fmin(dl, dr);

    Point strip[100];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(P[i].x - midPoint.x) < d) {
            strip[j] = P[i];
            j++;
        }
    }

    qsort(strip, j, sizeof(Point), compareY);

    for (int i = 0; i < j; i++) {
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < d; k++) {
            double dist = distance(strip[i], strip[k]);
            if (dist < d) {
                d = dist;
            }
        }
    }

    return d;
}

// 最接近点对的入口函数
double closest(Point P[], int n) {
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, n);
}

int main() {
    Point P[] = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
    int n = sizeof(P) / sizeof(P[0]);
    double minDist = closest(P, n);
    printf("最接近点对的距离为: %lf\n", minDist);
    return 0;
}
