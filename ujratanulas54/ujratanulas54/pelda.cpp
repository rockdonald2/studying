#include "stdafx.h"
#include <iostream>

#include <cmath> // a sqrt(), azaz a gyökvonás függvényhez


int main()
{
	int x;
probaldUjra: // statement label
	std::cout << "Irj be egy pozitiv szamot: ";
	std::cin >> x;

	if (x < 0.0)
		goto probaldUjra; // goto statement

	std::cout << "A beirt szamod gyoke: " << sqrt(x) << "\n";

	return 0;
}