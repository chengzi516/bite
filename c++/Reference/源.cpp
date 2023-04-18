#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
namespace chengzi {
	int a = 10;
	int& add(int& nums1, int& nums2) {
		int sum = nums1 + nums2;
		return sum;
	}
}
using namespace chengzi;
using namespace std;
void print(const int& a) {

	cout << a << endl;
}

int main() {
	/*int& b = a;
	int& c = a;
	cout << b << endl;
	cout << c << endl;
	c = 20;
	cout << b << endl;
	int d = 30;
	int& c = d;
	cout << c << endl;*/
	 int a = 10;
	 int b = 20;
	 int& c=add(a, b);
	 cout << c << endl;
	 printf("aaa\n");
	 cout << c << endl;
	
}