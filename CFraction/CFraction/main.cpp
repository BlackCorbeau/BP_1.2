#include <iostream>
#include "CFraction.h"

int main()
{
	Fraction fr(3, 4);
	Fraction fr2(2, 4);
	Fraction fr3;
	bool i = fr >= fr2;
	std::cout << i << '\n';
	fr2.simplify();
	fr2.print();
	std::cout << fr << '\n';
	std::cout << fr2 << '\n';
	fr3 = fr / fr2;
	fr /= fr2;
	fr3.print();
	fr.print();
	return 0;
}