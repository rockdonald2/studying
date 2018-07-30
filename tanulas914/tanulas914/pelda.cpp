#include "stdafx.h"
#include <iostream>
#include <cassert>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
	{
		assert(m_denominator != 0 && "A nevezo nem lehet nulla!\n");
	}

	Fraction(const Fraction &copy) : m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
	{}

	Fraction& operator=(const Fraction &f);

	friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
};

std::ostream& operator<<(std::ostream &out, const Fraction &f)
{
	out << f.m_numerator << "/" << f.m_denominator;

	return out;
}

Fraction& Fraction::operator=(const Fraction &f)
{
	// önhozzárendelés
	if (this == &f)
		return *this;

	m_numerator = f.m_numerator;
	m_denominator = f.m_denominator;

	return *this; // hogy össze lehessen láncolni őket.
}

int main()
{
	Fraction fiveThirds(5, 3);
	Fraction f;
	f = fiveThirds; // hozzárendelési operátor
	std::cout << f;

	return 0;
}