#define _CRT_SECURE_NO_WARNINGS 1

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "stdbool.h"



//����һ��point��ṹ���洢��x��y���ꡣ
struct Point {
    double x, y;
};
//cmp�����ֱ𷵻�x��y����Ĵ�С�ȶ�
bool cmp_x(struct Point a, struct Point b) {
    return a.x < b.x;
}
bool cmp_y(struct Point a, struct Point b) {
    return a.y < b.y;
}

//����ab�������
double dist(struct Point a, struct Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ������
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
    // ��������ֻ�������㣬ֱ�Ӽ�������֮��ľ��뼴��
    if (n == 2) {
        return dist(a[0], a[1]);
    }
    // ���������������㣬�������Ծ����е���Сֵ
    if (n == 3) {
        return min(dist(a[0], a[1]), min(dist(a[1], a[2]), dist(a[2], a[0])));
    }
    // ����������㣬ʹ�÷����㷨�������
    int m = n / 2; // ���㼯��Ϊ���룬mΪ�ֽ��
    double x = a[m].x; // ȡ�ֽ���x����
    //���Ĳ���
    double d = min(closest_pair(a, m), closest_pair(a + m, n - m)); // �ݹ�������������Ӽ��������Ծ��룬d��ΪҪ���ص���С����

    //�ݹ���ɺ�ص�����������ʱ�Ѿ�������������������ڵ���С���룬��ʱӦ�ÿ������Һϲ���������С�����

    // �����������Ӽ�����y����ϲ�
    sort(a, a + n, cmp_y);
    struct Point b[100]={0};
    int k = 0; // b������±�
    for (int i = 0; i < n; i++) {
        if (fabs(a[i].x - x) < d) { // �жϵ���ֽ��ĺ�����֮���Ƿ�С��d
            for (int j = k - 1; j >= 0 && a[i].y - b[j].y < d; j--) {
                // ��b�����ĩβ��ʼ��ǰ�������жϵ���b�������Ѵ�ŵĵ��������֮���Ƿ�С��d
                // ���С��d���������������֮��ľ��룬��������С����d
                d = min(d, dist(a[i], b[j]));
            }
            b[k++] = a[i]; // �����������ĵ���뵽b������
        }
    }
    return d; // ���������Եľ���
}
int main() {
    int n; //nΪ�������
    printf("please put the number of point");
    scanf("%d",&n);
    struct Point a[100]={0};
    printf("put the coordinate in here(x first,y second)");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    //��Ϊ�ǰ�x���ֳ������֣�������Ҫ���������������
    sort(a, a + n, cmp_x);
    //��closepair�㷨�������
    printf("the shortest distance is %f",closest_pair(a, n));
   
    return 0;
}

