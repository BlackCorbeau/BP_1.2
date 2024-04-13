#include <iostream>
#include "CDate.h"

CDate::CDate(int _day, int _month, int _year)
{
	day = _day;
	month = _month;
	year = _year;
}
CDate::CDate()
{
	day = 0;
	month = 0;
	year = 0;
}
CDate::~CDate() {}
void CDate::initialize_day(int _day)
{
	day = _day;
}
void CDate::initialize_month(int _month)
{
	month = _month;
}
void CDate::initialize_year(int _year)
{
	year = _year;
}
int CDate::get_day()
{
	return day;
}
int CDate::get_month()
{
	return month;
}
int CDate::get_year()
{
	return year;
}
void CDate::print_parametrs()
{
	std::cout << day << "." << month << "." << year << "\n";
}