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
#include <cstdio>
int main()
{
	__int64 Catalan[40] = { 0 };
	Catalan[0] = 1;
	Catalan[1] = 1;
	for (int i = 2; i <= 35; i++)
		for (int j = 0; j <= i - 1; j++)
			Catalan[i] += Catalan[j] * Catalan[i - 1 - j];
	int num = 1;
	int n;
	while (~scanf("%d", &n) && n != -1)
		printf("%d %d %I64d\n", num++, n, Catalan[n] * 2);
	return 0;
}


#include <cstdio>
int main()
{
	__int64 hanoi[22];        //把n个移到相邻杆子所需次数 
	hanoi[0] = 0;
	hanoi[1] = 1;
	for (int i = 2; i <= 19; i++)
		hanoi[i] = hanoi[i - 1] * 3 + 1;
	int u;
	scanf("%d", &u);
	int n;
	while (u--)
	{
		scanf("%d", &n);
		printf("%d\n", 2 * hanoi[n - 1] + 2);
	}
	return 0;
}


#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int T, i, j, n, m, min, a;
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> n >> m;
		for (j = 1; j <= n; j++) {
			cin >> a;
			if (j == 1) {
				min = a;
			}
			else {
				if (a < min) {
					min = a;
				}
			}
		}
		printf("%d\n", int(pow(100 - min, 2.0)));
	}
	return 0;
}

#include <cstdio>
#include <cstring>
int main()
{
	int u;
	char num[22];
	scanf("%d", &u);
	while (u--)
	{
		scanf("%s", num);
		printf("6%s\n", num + 6);
	}
	return 0;
}



#include <cstdio>
#include <cstring>
int main()
{
	int n, k, u;
	int ant[10];
	int c[44];
	int t[44];
	scanf("%d", &u);
	while (u--)
	{
		memset(ant, 0, sizeof(ant));
		memset(c, 0, sizeof(c));
		memset(t, 0, sizeof(t));
		scanf("%d %d", &n, &k);		//修n个学分，k门课
		for (int i = 1; i <= k; i++)
		{
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			ant[t1] = t2;
		}
		for (int i = 0; (i <= ant[1]) && (i <= 40); i++)
			c[i] = 1;
		for (int i = 2; i <= 8; i++)
		{
			for (int j = 0; j <= 40; j++)
				for (int k = 0; (k <= ant[i] * i) && (k + j <= 40); k += i)
					t[j + k] += c[j];
			for (int j = 0; j <= 40; j++)
			{
				c[j] = t[j];
				t[j] = 0;
			}
		}
		printf("%d\n", c[n]);
	}
	return 0;
}


#include <cstdio>
#include <cstring>
int main()
{
	int u;
	char num[22];
	scanf("%d", &u);
	while (u--)
	{
		scanf("%s", num);
		printf("6%s\n", num + 6);
	}
	return 0;
}




#include <cstdio>
#include <algorithm>
using namespace std;
int abs(int x)
{
	if (x < 0)
		return -x;
	return x;
}
int main()
{
	int u;
	int n;
	int a[555];
	int mid;
	int ans;
	scanf("%d", &u);
	while (u--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		mid = n / 2 + 1;
		ans = 0;
		for (int i = 1; i <= n; i++)
			ans += abs(a[i] - a[mid]);
		printf("%d\n", ans);
	}
	return 0;
}