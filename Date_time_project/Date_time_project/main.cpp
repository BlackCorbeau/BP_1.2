#include <iostream>
#include "class.h"
#include "CDate.h"
#include "functions.h"

int main()
{
	CTime t1(12, 43, 24);
	CTime t2(12, 38, 25);
	assign(t1, t2);
	t1.print_parametrs();
	t2.print_parametrs();
	return 0;
}