#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {
	//int x = 0, y = 0;
	//// 以下几个都是对右值的右值引用
	//int&& rr1 = 10;
	//double&& rr2 = x + y;
	//double&& rr3 = fmin(x, y);
	int x = 1, y = 2;
	int&& r1 = 10;
	int&& rr2 = x + y;
	r1 = 20;
	r1 = 2.2;
	cout << r1;
	string str1("asaaa");
	cout << str1;
}