#include "CExperience.h"

CExperience::CExperience()
{
	years = 0;
	months = 0;
}

CExperience::CExperience(CExperience& exp)
{
	years = exp.years;
	months = exp.months;
}

CExperience::CExperience(int _years, int _months)
{
	years = _years;
	months = _months;
}

int CExperience::get_years()
{
	return years;
}

int CExperience::get_months()
{
	return months;
}

void CExperience::set_years(int _years)
{
	years = _years;
}

void CExperience::set_months(int _months)
{
	months = _months;
}

CExperience CExperience::make_easier()
{
	if (months > 12)
	{
		this->years++;
		this->months -= 12;
	}
	return *this;
}

CExperience CExperience::add_month()
{
	this->months++;
	return *this;
}