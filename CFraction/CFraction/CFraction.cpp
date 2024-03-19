#include "CFraction.h"
#include <string>
#include <iostream>


Fraction::Fraction()
{
	_numerator = 0;
	_denominator = 0;
}
Fraction::Fraction(const Fraction& F1)
{
	_numerator = F1._numerator;
	_denominator = F1._denominator;
}
Fraction::Fraction(int numerator, int denumirator)
{
	_numerator = numerator;
	_denominator = denumirator;
}
//Fraction::Fraction(float num) //Дописать
//{
//	std::string string_num = std::to_string(num);
//	int string_num_size = string_num.size();
//	for (int i = 0; i < string_num_size; i++)
//	{
//		if (string_num[i] == ',')
//		{
//			continue;
//		}
//		else if()
//	}
//}

void Fraction::set_numerator(int numerator)
{
	_numerator = numerator;
}
void Fraction::set_denominator(int denumirator)
{
	_denominator = denumirator;
}
int Fraction::get_numerator()
{
	return _numerator;
}
int Fraction::get_denuminator()
{
	return _denominator;
}

void Fraction::print()
{
	std::cout << _numerator << '/' << _denominator << '\n';
}
void Fraction::Do_easier()
{
	int m = _denominator;
	int n = _numerator;
	int r = m % n;
	while (r != 0)
	{
		m = n;
		n = r;
		r = m % n;
	}
	_denominator /= n;
	_numerator /= n;
}

Fraction Fraction::operator=(const Fraction& fr)
{
	if (this != &fr)
	{
		_denominator = fr._denominator;
		_numerator = fr._numerator;
	}
	else { return *this; }
}

bool Fraction::operator!=(const Fraction& fr)
{
	return (_denominator != fr._denominator && _numerator != fr._numerator);
}

bool Fraction::operator>=(const Fraction& fr)
{
	return ((_denominator == fr._denominator && _numerator >= fr._numerator) || (_denominator <= fr._denominator));
}
bool Fraction::operator<=(const Fraction& fr)
{
	return((_denominator == fr._denominator && _numerator <= fr._numerator) || (_denominator >= fr._denominator));
}
bool Fraction::operator<(const Fraction& fr)
{
	return((_denominator == fr._denominator && _numerator < fr._numerator) || (_denominator > fr._denominator));
}
bool Fraction::operator>(const Fraction& fr)
{
	return((_denominator == fr._denominator && _numerator > fr._numerator) || (_denominator < fr._denominator));
}

Fraction Fraction::operator+(const Fraction& fr1)
{
	Fraction Res(*this);
	if (Res._denominator == fr1._denominator)
	{
		Res._numerator += fr1._numerator;
	}
	else
	{
		Res._numerator = (Res._numerator * fr1._denominator) + (fr1._numerator * Res._denominator);
		Res._denominator = Res._denominator * fr1._denominator;
	}
	Res.Do_easier();
	return Res;
}

void Fraction::operator+=(const Fraction& fr1)
{
	if (_denominator == fr1._denominator)
	{
		_numerator += fr1._numerator;
	}
	else
	{
		_numerator = (_numerator * fr1._denominator) + (fr1._numerator * _denominator);
		_denominator = _denominator * fr1._denominator;
	}
}

Fraction Fraction::operator-(const Fraction& fr)
{
	Fraction Res(*this);
	if (Res._denominator == fr._denominator)
	{
		Res._numerator -= fr._numerator;
	}
	else
	{
		Res._numerator = (Res._numerator * fr._denominator) - (fr._numerator * Res._denominator);
		Res._denominator = Res._denominator * fr._denominator;
	}
	Res.Do_easier();
	return Res;
}

void Fraction::operator-=(const Fraction& fr1)
{
	if (_denominator == fr1._denominator)
	{
		_numerator -= fr1._numerator;
	}
	else
	{
		_numerator = (_numerator * fr1._denominator) - (fr1._numerator * _denominator);
		_denominator = _denominator * fr1._denominator;
	}
}