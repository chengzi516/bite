#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
using namespace std;

void test1() {
	vector<int>array;

	array.push_back(100);

	array.push_back(300);

	array.push_back(300);

	array.push_back(300);

	array.push_back(300);

	array.push_back(500);

	vector<int>::iterator itor;

	for (itor = array.begin(); itor != array.end(); itor++)

	{

		if (*itor == 300)

		{

			itor = array.erase(itor);

		}

	}

	for (itor = array.begin(); itor != array.end(); itor++)

	{

		cout << *itor << " ";

	}
}

void test2() {
	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sizeof(ar) / sizeof(int);

	vector<int> v(ar, ar + n);

	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(100);

	v.resize(20);

	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(50);

	v.resize(5);

	cout << v.size() << ":" << v.capacity() << endl;
}
void test3() {
	
	vector<int> nums={ 0,0,1,1,1,2,2,3,3,4 };
	int fast = 1;
	int slow = 0;
	while (fast <= nums.size()) {
		if (nums[fast] != nums[slow]) {
			fast++;
			slow++;
		}
		else {
			nums.erase(nums.begin() + slow);
			
		}

	}
}
void test4() {
	
	

		int ar[] = { 0,1, 2, 3, 4,  5, 6, 7, 8, 9 };

		int n = sizeof(ar) / sizeof(int);

		list<int> mylist(ar, ar + n);

		list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

		reverse(mylist.begin(), pos);

		reverse(pos, mylist.end());

		list<int>::const_reverse_iterator crit = mylist.crbegin();

		while (crit != mylist.crend())

		{

			cout << *crit << " ";

			++crit;

		}

		cout << endl;

	


}
int main() {
	test4();
}