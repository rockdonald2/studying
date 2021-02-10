#include "pch.h"
#include <iostream>

#include <cmath>

double mySqrt(double x)
{
	if (x < 0.0)
		throw "Can not take sqrt of negative number";
	return sqrt(x);
}

int main()
{
	std::cout << "Enter a number: ";
	double x{ 0.0 };
	std::cin >> x;

	try
	{
		double d = mySqrt(x);
		std::cout << "The sqrt of " << x << " is " << d << '\n';
	}

	catch(...) // catch-all handler
	{
		std::cout << "We caught an exception of an undetermined type\n";
	}

	return 0;
}