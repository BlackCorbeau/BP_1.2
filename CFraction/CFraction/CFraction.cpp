#include "CFraction.h"
#include <string>
#include <iostream>

int gcd(int a, int b) {
	if (a == 0) { return b; }
	else if (b == 0) { return a; }
	else if (a >= b) { return gcd(a % b, b); }
	else if (a <= b) { return gcd(a, b % a); }
}

void Fraction::simplify()
{
	int _gcd = gcd(_numerator, _denominator);
	_denominator /= _gcd;
	_numerator /= _gcd;
}

Fraction::Fraction()
{
	_numerator = 0;
	_denominator = 1;
	this->simplify();
}
Fraction::Fraction(const Fraction& F1)
{
	_numerator = F1._numerator;
	_denominator = F1._denominator;
	this->simplify();
}
Fraction::Fraction(int numerator, int denumirator)
{
	_numerator = numerator;
	_denominator = denumirator;
	this->simplify();
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
	this->simplify();
	std::cout << _numerator << '/' << _denominator << '\n';
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
	Res.simplify();
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
	this->simplify();
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
	Res.simplify();
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
		_denominator *= fr1._denominator;
	}
	this->simplify();
}

Fraction Fraction::operator*(const Fraction& fr)
{
	Fraction Res(*this);
	Res._denominator = Res._denominator * fr._denominator;
	Res._numerator = Res._numerator * fr._numerator;
	Res.simplify();
	return Res;
}

void Fraction::operator*=(const Fraction& fr)
{
	_denominator = _denominator * fr._denominator;
	_numerator = _numerator * fr._numerator;
	this->simplify();
}

Fraction Fraction::operator/(const Fraction& fr)
{
	Fraction res(*this);
	res._numerator = res._numerator * fr._denominator;
	res._denominator = res._denominator * fr._numerator;
	res.simplify();
	return res;
}

void Fraction::operator/=(const Fraction& fr)
{
	_numerator = _numerator * fr._denominator;
	_denominator = _denominator * fr._numerator;
	this->simplify();
}