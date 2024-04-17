#pragma once
#include <iostream>

class CExperience
{
	int years;
	int months;

public :
	CExperience();
	CExperience(CExperience& exp);
	CExperience(int _years, int _months);
	
	CExperience make_easier();
	int get_years();
	int get_months();
	void set_years(int _years);
	void set_months(int _months);

	CExperience add_month ();

	friend std::istream& operator>>(std::istream& cin, CExperience& _exp) {
		cin >> _exp.years >> _exp.months;
		return cin;
	}

	friend std::ostream& operator<<(std::ostream& cout, CExperience& _exp) {
		cout << _exp.years << "Лет" << _exp.months << "Месяцев";
		return cout;
	}
};