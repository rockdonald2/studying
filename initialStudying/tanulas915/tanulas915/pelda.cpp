#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <cstring>


/*class Fraction
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
	// önhozzárendelés megelőzése
	if (this == &f)
		return *this;

	m_numerator = f.m_numerator;
	m_denominator = f.m_denominator;

	return *this; // hogy össze lehessen láncolni őket.
}

int main()
{
	

	return 0;
}*/


class MyString
{
private:
	char *m_data;
	int m_length;

public:
	// konstruktőr
	MyString(const char *source = "")
	{
		assert(source && "A forras egy null string");

		// megkeressük a string hosszát
		// +1 karakter a terminátorhoz
		m_length = strlen(source) + 1;

		// lefoglaljuk a buffert ami a hosszával egyenlő
		m_data = new char[m_length];

		// bemásoljuk a paraméter stringet a belső bufferba.
		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];


		// bebiztosítjuk, hogy a string véget ért.
		m_data[m_length - 1] = '\0';
	}

	// copy konstruktőr, deep copyval.
	MyString(const MyString& source)
	{
		// mivel nem mutató a length, ezért shallow másolhatjuk.
		m_length = source.m_length;

		// m_data egy mutató, ezért deep copyzzuk, csak akkor ha nem null mutató
		if (source.m_data)
		{
			// lefoglaljuk a memóriát a másolatnak
			m_data = new char[m_length];

			// másoljuk
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = 0;
	}

	// destruktőr
	~MyString()
	{
		delete[] m_data;
	}

	MyString& operator=(const MyString& source);

	char* getString() { return m_data; }
	int getLength() { return m_length; }
};

MyString& MyString::operator=(const MyString& source)
{
	// önhozzárendelés megelőzés
	if (this == &source)
		return *this;

	// először letöröljük bármely értéket amelyet a string tartalmaz
	delete[] m_data;

	// shallow copyzzuk a lengthet, mert nem mutató
	m_length = source.m_length;

	if (source.m_data)
	{
		// lefoglaljuk a memóriát a másolathoz
		m_data = new char[m_length];

		// másoljuk
		for (int i = 0; i < m_length; ++i)
			m_data[i] = source.m_data[i];
	}

	else
		m_data = 0;

	return *this;
}
