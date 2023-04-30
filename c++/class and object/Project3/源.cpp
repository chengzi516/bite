#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;
class student {
public:
	student() {
		age = 10;
		name = "chengzi";
	}
private:
	string name;
	int age;
};
class date {
public:
	void init(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}

	date() {

	}
	date(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}
	date(const date& d) {
		_day = d._day;
		_month = d._month;
		_year = d._year;
		stu = d.stu;
	}
	/*bool operator==(const date& d1) {
		return d1._year == _year && d1._month == _month && d1._day == _day;
	}
	date& operator=(const date& d1) {
		_year = d1._year;
		_day = d1._day;
		_month = d1._month;
		return *this;
	}*/
	void assignment(date& d1) {
		(*this) = d1;
	}
private:
	int _day=1;
	int _month=1;
	int _year=1;
	student stu;
	
};
class stack {
public:
	stack(int capacity) {
		arr = (int*)malloc(sizeof(int) * capacity);
		currentsize = 0;
	}
	~stack() {
		if (arr) {
			free(arr);
			arr = NULL;
		}
	}
	stack(const stack& stack1) {
		arr = (int*)malloc(sizeof(int) * stack1.capacity);
		memcpy(arr, stack1.arr, sizeof(int) * stack1.currentsize);
		capacity = stack1.capacity;
		currentsize = stack1.currentsize;
	}
private:
	int* arr;
	int capacity;
	int currentsize;
};
int main() {
	date d1(22,22,22);
	date d2;
	d2.assignment(d1);
	return 0;
}