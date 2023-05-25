#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        int ans = 0; int isplus = 1;
        for (char ch : str) {
            if (isalpha(ch)) {
                return 0;
            }if (ch == '+' || ch == '-') {
                isplus = (ch == '+') ? 1 : -1;
            }if (isdigit(ch)) {
                ans = ans * 10 + ch - '0';
            }
        }return isplus * ans;
    }
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string news;
        int value1 = 0, value2 = 0, carry = 0;
        while (end1 >= 0 || end2 >= 0) {
            if (end1 >= 0)
                value1 = num1[end1--] - '0';
            else
                value1 = 0;
            if (end2 >= 0)
                value2 = num2[end2--] - '0';
            else
                value2 = 0;
            int sum = value1 + value2 + carry;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            news += sum + '0';
        }
        if (carry == 1)
            news += '1';
        reverse(news.begin(), news.end());
        return news;
    }
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string news;
        int value1 = 0, value2 = 0, carry = 0;
        while (end1 >= 0 || end2 >= 0) {
            if (end1 >= 0)
                value1 = num1[end1--] - '0';
            else
                value1 = 0;
            if (end2 >= 0)
                value2 = num2[end2--] - '0';
            else
                value2 = 0;
            int sum = value1 + value2 + carry;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }
            news += sum + '0';
        }
        if (carry == 1)
            news += '1';
        reverse(news.begin(), news.end());
        return news;
    }
    int firstUniqChar(string s) {
        //ASCII码表中只有256个字符，所以可以将count数组的大小设置为256。这样就可以将每个字符映射到count数组的一个位置上
        int count[256] = { 0 };
        int size = s.size();
        for (int i = 0; i < size; i++)
            count[s[i]] += 1;
        for (int i = 0; i < size; i++) {
            if (count[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

