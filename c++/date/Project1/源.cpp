#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//�ж��Ƿ�Ϊ����
bool isleapyear(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
//ȡ��ǰ�µ�����
int monthDays(int year, int month) { // ÿ���µ�����
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isleapyear(year)) { // ����Ķ�����29��
        return 29;
    }
    return days[month];
}
int getdays(int date1, int date2) {
    //ʹ��date1��С
    if (date1 > date2)
        swap(date1, date2);
    //�����������ת��Ϊ�������֣��꣬�£���
    int year1 = date1 / 10000, month1 = date1 % 10000 / 100, day1 = date1 % 100;
    int year2 = date2 / 10000, month2 = date2 % 10000 / 100, day2 = date2 % 100;
    //days��ΪҪ���ص�����
    int days = 0;
    for (int i = year1; i < year2; i++) { // ͳ�����������
        days += 365 + isleapyear(i); //bool��ʽת��Ϊint
    }

    for (int i = 1; i < month1; i++) { // ��ȥdate1������֮ǰ������
        days -= monthDays(year1, i);
    }
    days -= day1 - 1; // ��ȥdate1�����Ѿ���ȥ������

    for (int i = 1; i < month2; i++) { // ����date2������֮ǰ������
        days += monthDays(year2, i);
    }
    days += day2; // ����date2�����Ѿ���ȥ������

    return days;

}
int main() {
    int a, b;
    cin >> a >> b;
    cout << getdays(a, b) << endl;
}