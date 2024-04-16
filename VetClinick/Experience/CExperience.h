#pragma once

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
};