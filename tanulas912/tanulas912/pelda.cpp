#include "stdafx.h"
#include <iostream>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	// alapértelmezett konstruktőr
	Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
	{}

	// copy konstruktőr
	Fraction(const Fraction &copy) : m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
	{
		std::cout << "A copy konstruktor lehivva.\n";
	}

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
	int getNumerator()
	{
		return m_numerator;
	}
	void setNumerator(int numerator)
	{
		m_numerator = numerator;
	}
};

std::ostream& operator<<(std::ostream &out, const Fraction &f)
{
	out << f.m_numerator << '/' << f.m_denominator;

	return out;
}

Fraction makeNegative(Fraction f) // ez ideálisan const hivatkozás által kéne átadva legyen.
{
	f.setNumerator(-f.getNumerator());
	return f; // érték szerinti visszaadás ami copy inicializálással történik
}

int main()
{
	Fraction six = Fraction(6); // copy inicializálás
	Fraction seven(Fraction(7)); // copy inicializálás

	std::cout << six << '\t' << seven << '\n';

	Fraction fiveThirds(5, 3);
	std::cout << makeNegative(fiveThirds) << '\n';

	return 0;
}

