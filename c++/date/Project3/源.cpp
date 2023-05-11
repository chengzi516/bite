#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
using namespace std;
int dayofmonth[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

bool isleapyear(int year) {            //�Ƿ�Ϊ����
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year, month, day;
    int number = 0;
    while (cin >> year >> number) {
        month = 0;
        int row = isleapyear(year);
        while (number > dayofmonth[row][month]) {          //��number���ݼ�ȷ��ȷ���·�
            number -= dayofmonth[row][month];
            month++;
        }
        day = number;                //������ʣ�µ�numberȷ����
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}

