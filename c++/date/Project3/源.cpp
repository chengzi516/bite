#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
using namespace std;
int dayofmonth[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

bool isleapyear(int year) {            //是否为闰年
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year, month, day;
    int number = 0;
    while (cin >> year >> number) {
        month = 0;
        int row = isleapyear(year);
        while (number > dayofmonth[row][month]) {          //用number来递减确定确定月份
            number -= dayofmonth[row][month];
            month++;
        }
        day = number;                //不足月剩下的number确定日
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}

