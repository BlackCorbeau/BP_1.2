#include <iostream>
#include "class.h"
#include "CDate.h"

int main()
{
	CTime t1(12, 43, 24);
	t1.print_parametrs();
	t1.initialize_seconds(12);
	t1.initialize_minutes(24);
	t1.initialize_hours(18);
	t1.print_parametrs();
	int a = t1.get_hours();
	std::cout << a << "\n";
	a = t1.get_minutes();
	std::cout << a << "\n"; 
	a = t1.get_seconds();
	std::cout << a << "\n";
	t1.print_parametrs();
	CDate d1(5, 3, 2024);
	d1.print_parametrs();
	d1.initialize_day(21);
	d1.initialize_month(1);
	d1.initialize_year(2005);
	d1.print_parametrs();
	a = d1.get_day();
	std::cout << a << "\n";
	a = d1.get_month();
	std::cout << a << "\n";
	a = d1.get_year();
	std::cout << a << "\n";
	return 0;
}