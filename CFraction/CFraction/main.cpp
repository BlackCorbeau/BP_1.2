#include <iostream>
#include "CFraction.h"

int main()
{
	Fraction fr(5, 4);
	Fraction fr2(8, 20);
	Fraction Fr3;
	fr2.Do_easier();
	std::cout << fr << '\n';
	std::cout << fr2 << '\n';
	Fr3 = fr / fr2;
	fr /= fr2;
	Fr3.print();
	fr.print();
	return 0;
}