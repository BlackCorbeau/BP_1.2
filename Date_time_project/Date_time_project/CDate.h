#pragma once

class CDate
{
private:
	int day;
	int month;
	int year;
public:
	CDate();
	CDate(int _day, int _month, int _year);
	~CDate();
	void initialize_day(int _day);
	void initialize_month(int _month);
	void initialize_year(int _year);
	int get_day();
	int get_month();
	int get_year();
	void print_parametrs();
};