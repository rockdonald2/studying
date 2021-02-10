#include "stdafx.h"
#include <iostream>

int osszeadas(int x, int y)
{
	return x + y;
}

double osszeadas(double x, double y)
{
	return x + y;
}

/*
Megfigyelhető, hogy két 'osszeadas' funkciónk van, de más paraméterekkel.
	Ez által eltudja dönteni a compiler az azonos funkciónevek ellenére a továbbadott érv alapján, hogy az 'int' vagy a 'double'
	funkciót kivánjuk használni.
*/

int main()
{
	std::cout << osszeadas(2, 5) << '\n';
	std::cout << osszeadas(2.5, 5.3) << '\n';

	return 0;
}