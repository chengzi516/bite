#define _CRT_SECURE_NO_WARNINGS 1
#include"priorityqueue.h"

int main() {
	bit::priority_queue<int, vector<int>,Less<int>> q1;
	q1.push(3);
	q1.push(2);
	q1.push(1);
	q1.push(4);
	while (!q1.empty())
	{
		int a = q1.top();
		cout << a << " ";
		q1.pop();
	}
	cout << endl;
}