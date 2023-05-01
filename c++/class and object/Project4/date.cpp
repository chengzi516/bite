#define _CRT_SECURE_NO_WARNINGS 1
#include"date.h"
#include<iostream>

Date::Date(int year,int month,int day) {
	_year = year;
	_month = month;
	_day = day;
}

Date::Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

int Date::GetMonthDay(int year, int month) {
	static int daysArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	else
	{
		return daysArr[month];
	}
}

Date& Date::operator=(const Date& d) {
	_year = d._year;
	_day = d._day;
	_month = d._month;
}

Date::~Date() {

}

Date& Date:: operator+=(int day) {
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator+(int day) {

	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}


Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}

bool Date::operator==(const Date& x)
{
	return _year == x._year
		&& _month == x._month
		&& _day == x._day;
}


bool Date::operator<=(const Date& x)
{
	return *this < x || *this == x;
}

bool Date::operator>(const Date& x)
{
	return !(*this <= x);
}

bool Date::operator>=(const Date& x)
{
	return !(*this < x);
}

bool Date::operator!=(const Date& x)
{
	return !(*this == x);
}