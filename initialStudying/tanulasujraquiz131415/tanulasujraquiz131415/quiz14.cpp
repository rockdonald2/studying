#include "pch.h"
#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator, int denominator) try : m_numerator(numerator), m_denominator(denominator) 
	{
		if (m_denominator == 0)
			throw std::runtime_error("Denominator cannot be 0");
	}

	catch (...)
	{
		throw;
	}

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f)
	{
		out << f.m_numerator << '/' << f.m_denominator;
		return out;
	}
};

int main()
{
	std::cout << "Enter the numerator: ";
	int n{ 0 };
	std::cin >> n;
	
	std::cout << "Enter the denominator: ";
	int d{ 1 };
	std::cin >> d;

	try
	{
		Fraction f(n, d);

		std::cout << f;
	}

	catch (std::exception)
	{
		std::cerr << "Your fraction has an invalid denominator";
		return -1;
	}

	return 0;
}