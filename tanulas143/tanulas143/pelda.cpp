#include "pch.h"
#include <iostream>

/*#include <cmath>

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

	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << std::endl;
	}

	return 0;
}*/

void last()
{
	std::cout << "Start last\n";
	std::cout << "last throwing an exception\n";
	throw - 1;
	std::cout << "End last\n";
}

void third()
{
	std::cout << "Start third\n";
	last();
	std::cout << "End third\n";
}

void second()
{
	std::cout << "Start second\n";
	try
	{
		third();
	}
	catch (double)
	{
		std::cerr << "second caught double exception\n";
	}
	std::cout << "End second\n";
}

void first()
{
	std::cout << "Start first\n";
	try
	{
		second();
	}
	catch (int)
	{
		std::cerr << "first caught int exception\n";
	}
	catch (double)
	{
		std::cerr << "first caught double exception\n";
	}
	std::cout << "End first\n";
}

int main()
{
	std::cout << "Start main\n";
	try
	{
		first();
	}
	catch (int)
	{
		std::cerr << "main caught int exception\n";
	}
	std::cout << "End main\n";

	return 0;
}