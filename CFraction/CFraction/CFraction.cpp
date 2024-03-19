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

void Fraction::Fraction_print()
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

Fraction Fraction::operator+(const Fraction& fr1)
{
	Fraction Res(*this);
	if (Res._denominator == fr1._denominator)
	{
		Res._numerator += fr1._numerator;
	}
	else
	{
		Res._denominator = Res._denominator * fr1._denominator;
		Res._numerator = (Res._numerator * fr1._denominator) + (fr1._numerator * Res._denominator);
	}
	return Res;
}