#include <iostream>
#include "CFraction.h"

int main()
{
	Fraction fr(1, 4);
	Fraction fr2(4, 20);
	Fraction Fr3;
	fr2.Do_easier();
	fr.print();
	fr2.print();
	Fr3 = fr - fr2;
	fr -= fr2;
	Fr3.print();
	fr.print();
	return 0;
}