#include "stdafx.h"
#include <iostream>
#include <string>

/*class Fraction
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
	std::cout << makeNegative(7) << '\n'; // vedd észre az integer paramétert.

	return 0;
}*/


class MyString
{
private:
	std::string m_string;

public:

		MyString(char) = delete;
		// ez a konstruktőr nem teszi lehetőve, hogy magától értetődö átalakítást végezzen.
	explicit MyString(int x) // lefoglal egy string x méretben
	{
		m_string.resize(x);
	}

	MyString(const char *string)
	{
		m_string = string;
	}

	friend std::ostream& operator<<(std::ostream &out, MyString &string);
};

std::ostream& operator<<(std::ostream &out, MyString &string)
{
	out << string.m_string;

	return out;
}

int main()
{
	MyString string = 'x'; // compiler error.
	std::cout << string << '\n';

	return 0;
}