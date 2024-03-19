#include <iostream>
#include "CFraction.h"

int main()
{
	Fraction fr(1, 6);
	Fraction fr2(4, 20);
	fr2.Do_easier();
	fr.print();
	fr2.print();
	if (fr >= fr2)
	{
		std::cout << "fr >= fr2";
	}
	else
	{
		std::cout << "fr <= fr2";
	}
	if (fr <= fr2)
	{
		std::cout << "fr <= fr2";
	}
	else
	{
		std::cout << "fr >= fr2";
	}
	return 0;
}