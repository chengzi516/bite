#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"list.h"

void Print(const bit::list<int>& lt)
{
	bit::list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		// (*it) += 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main() {
	bit::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	Print(l1);

}