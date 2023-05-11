#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
bool isleapyear(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int print(int year, int month, int day, int number) {
    int dayofmonth[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    while (number) {
        if (number > dayofmonth[isleapyear(year)][month] - day + 1) {
            number -= dayofmonth[isleapyear(year)][month] - day + 1;
            month++;
            day = 1;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        else {
            day += number;
            number = 0;
        }
    }

    printf("%04d-%02d-%02d\n", year, month, day); // 按照指定格式输出
    return 0;
}

int main() {
    int m = 0;
    cin >> m;
    while (m) {
        int year, month, day, number;
        cin >> year >> month >> day >> number;
        print(year, month, day, number);
        m--;
    }
}
