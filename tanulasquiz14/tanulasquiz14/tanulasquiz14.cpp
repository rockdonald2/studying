#include "pch.h"
#include <iostream>

//

#include <stdexcept>

class Fraction
{
private:
	double m_numerator;
	double m_denominator;

public:
	Fraction(double numerator, double denominator) try : m_numerator(numerator), m_denominator(denominator)
	{
		if (denominator == 0)
			throw std::runtime_error("Denominator cannot be 0");
	}

	catch (std::exception)
	{
		// std::cerr << "An error occurred: " << exception.what() << std::endl;

		throw;
	}

	double solveFraction()
	{
		return static_cast<double>(m_numerator / m_denominator);
	}

	void setNumerator(int x)
	{
		m_numerator = x;
	}

	void setDenominator(int x)
	{
		m_denominator = x;
	}

	double returnNumerator()
	{
		return m_numerator;
	}

	double returnDenominator()
	{
		return m_denominator;
	}
};

int main()
{
	double n{ 0 };
	double d{ 0 };

	try
	{
		std::cout << "Enter the numerator: ";
		std::cin >> n;

		std::cout << "Enter the denominator: ";
		std::cin >> d;

		Fraction f(n, d);

		std::cout << "The answer is: " << f.solveFraction() << '\n';
	}

	catch (std::exception &exception)
	{
		std::cerr << "Your fraction has an invalid denominator. " << "Error: " << exception.what() << std::endl;
	}

	return 0;
}