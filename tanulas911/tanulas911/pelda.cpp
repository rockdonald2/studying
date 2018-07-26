#include "stdafx.h"
#include <iostream>
#include <cassert>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	// alapértelmezett konstruktőr
	Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
	{
		assert(m_denominator != 0 && "The denominator cannot be zero.\n");
	}

	// copy konstruktőr
	Fraction(const Fraction &copyFraction) : m_numerator(copyFraction.m_numerator), m_denominator(copyFraction.m_denominator)
	{
		
	}

	friend std::ostream& operator<< (std::ostream &out, Fraction &f);
};

std::ostream& operator<< (std::ostream &out, Fraction &f)
{
	out << f.m_numerator << '/' << f.m_denominator;

	return out;
}


int main(void)
{
	Fraction(5, 2); // direct inicializálás
	Fraction{ 1, 2 }; // uniform inicializálás
	Fraction seven = 7; // ami a (7, 1) konstruktőrt hívja le, copy inicializálás.

	Fraction fiveThirds(5, 3);
	Fraction copy(fiveThirds); // copy konstruktőrt hívja le.
	std::cout << copy << '\n';

	return 0;
}