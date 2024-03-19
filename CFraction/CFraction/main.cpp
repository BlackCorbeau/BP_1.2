#include <iostream>
#include "CFraction.h"

int main()
{
	Fraction fr(3, 5);
	Fraction fr2(4, 20);
	fr2.Do_easier();
	fr = fr2;
	fr.print();
	fr2.print();
}