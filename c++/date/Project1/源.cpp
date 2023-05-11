#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//判断是否为闰年
bool isleapyear(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
//取当前月的天数
int monthDays(int year, int month) { // 每个月的天数
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isleapyear(year)) { // 闰年的二月有29天
        return 29;
    }
    return days[month];
}
int getdays(int date1, int date2) {
    //使得date1最小
    if (date1 > date2)
        swap(date1, date2);
    //将输入的数据转化为三个部分，年，月，日
    int year1 = date1 / 10000, month1 = date1 % 10000 / 100, day1 = date1 % 100;
    int year2 = date2 / 10000, month2 = date2 % 10000 / 100, day2 = date2 % 100;
    //days即为要返回的数据
    int days = 0;
    for (int i = year1; i < year2; i++) { // 统计整年的天数
        days += 365 + isleapyear(i); //bool隐式转换为int
    }

    for (int i = 1; i < month1; i++) { // 减去date1所在月之前的天数
        days -= monthDays(year1, i);
    }
    days -= day1 - 1; // 减去date1当月已经过去的天数

    for (int i = 1; i < month2; i++) { // 加上date2所在月之前的天数
        days += monthDays(year2, i);
    }
    days += day2; // 加上date2当月已经过去的天数

    return days;

}
int main() {
    int a, b;
    cin >> a >> b;
    cout << getdays(a, b) << endl;
}