
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//����һ��point��ṹ���洢��x��y���ꡣ
struct Point {  
    double x, y;
};
//cmp�����ֱ𷵻�x��y����Ĵ�С�ȶ�
bool cmp_x(Point a, Point b) {
    return a.x < b.x;
}
bool cmp_y(Point a, Point b) {
    return a.y < b.y;
}
//����ab�������
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double closest_pair(Point* a, int n) {
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
    Point* b = new Point[n]; // ����һ����ʱ����b�����ڴ�����������ĵ�
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
    delete[] b; // �ͷ���ʱ����b���ڴ�
    return d; // ���������Եľ���
}
int main() {
    int n; //nΪ�������
    cout << "please put the number of point";
    cin >> n;
    Point* a = new Point[n];  //aΪָ��㼯ָ��
    cout << "put the coordinate in here(x first,y second)";
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    //��Ϊ�ǰ�x���ֳ������֣�������Ҫ���������������
    sort(a, a + n, cmp_x);  
    //��closepair�㷨�������
    cout<<"the shortest distance is " << closest_pair(a, n);
    delete[] a;
    return 0;
}

