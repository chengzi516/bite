#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

#include "vector.h"

int main() {
	myclass::vector<int> v1(10, 1);
	myclass::vector<int> v2(v1);
	return 0;
}