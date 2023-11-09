#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"map.h"
#include"set.h"

int main() {
	chengzi::map<int,int> m;
	chengzi::set<int> n;
	n.Insert(1);
	n.Insert(2);
	n.Insert(3);
	n.Insert(4);
  auto it = n.begin();
	while (it != n.end())
	{
		
		cout << *it << " ";
		++it;
	}
	cout << endl;
	
}