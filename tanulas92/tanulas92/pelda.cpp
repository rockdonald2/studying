#include "stdafx.h"
#include <iostream>

/*class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) : m_cents(cents)
	{}

	friend Cents operator+(const Cents &c1, const Cents &c2);
	friend Cents operator-(const Cents &c1, const Cents &c2);
	friend Cents operator+(const Cents &c1, int num);
	friend Cents operator+(int num, const Cents &c2);

	int getCents() const { return m_cents; }
};

Cents operator+(const Cents &c1, const Cents &c2)
{
	// használjuk a Cents konstruktőrt, és az operátor+(int, int)
	// elérhetjük direkt módon a privát tag változót, mert ez egy friend funkció.
	return Cents(c1.m_cents + c2.m_cents);
}

Cents operator-(const Cents &c1, const Cents &c2)
{
	// használjuk a Cents konstruktőrt, és az operátor-(int, int)
	// elérhetjük direkt módon a privát tag változót, mert ez egy friend funkció.
	return Cents(c1.m_cents - c2.m_cents);
}

Cents operator+(const Cents &c1, int num)
{
	// használjuk a Cents konstruktőrt, és az operátor+(Cents, int)
	// elérhetjük direkt módon a privát tag változót, mert ez egy friend funkció.
	return Cents(c1.m_cents + num);
}

Cents operator+(int num, const Cents &c2)
{
	// használjuk a Cents konstruktőrt, és az operátor+(int, Cents)
	// elérhetjük direkt módon a privát tag változót, mert ez egy friend funkció.
	return Cents(num + c2.m_cents);
}

// vagy

Cents operator+(int num, const Cents &c2)
{
	// lehívjuk a már meglevő operátor+(Cents, int)
	return c2.m_cents + num;
}

int main()
{
	Cents cents1(6);
	Cents cents2(8);
	Cents centsSum = cents1 + cents2;
	std::cout << "Nekem van " << centsSum.getCents() << " centem.\n";

	return 0;
}*/

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator)
	{
		reduce();
	}

	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f, int num);
	friend Fraction operator*(int num, const Fraction &f);

	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}

	static int gcd(int a, int b) 
	{
		return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
	}

	void reduce()
	{
		int gcd = Fraction::gcd(m_numerator, m_denominator);
		m_numerator /= gcd;
		m_denominator /= gcd;
	}
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	int fidgN = f1.m_numerator * f2.m_numerator;
	int fidgD = f1.m_denominator * f2.m_denominator;

	return Fraction(fidgN, fidgD);
}

Fraction operator*(const Fraction &f, int num)
{
	int fidgN = f.m_numerator * num;
	int fidgD = f.m_denominator;

	return Fraction(fidgN, fidgD);
}

Fraction operator*(int num, const Fraction &f)
{
	// használom a már meglevő operátor*(Fraction, int)
	return f * num;
}

int main()
{
	Fraction f1(2, 5);
	f1.print();

	Fraction f2(3, 8);
	f2.print();

	Fraction f3 = f1 * f2;
	f3.print();

	Fraction f4 = f1 * 2;
	f4.print();

	Fraction f5 = 2 * f2;
	f5.print();

	Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
	f6.print();

	return 0;
}