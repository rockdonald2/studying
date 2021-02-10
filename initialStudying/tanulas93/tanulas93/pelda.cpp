#include "stdafx.h"
#include <iostream>

/*class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0, double y = 0, double z = 0):
		m_x(x), m_y(y), m_z(z)
	{}

	friend std::ostream& operator<< (std::ostream &out, const Point &point);
	friend std::istream& operator>> (std::istream &in, Point &point);
};

std::ostream& operator<< (std::ostream &out, const Point &point)
{
	out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

	return out;
}

std::istream& operator>> (std::istream &in, Point &point)
{
	in >> point.m_x;
	in >> point.m_y;
	in >> point.m_z;

	return in;
}

int main()
{
	Point point1(2.0, 3.0, 4.0);
	std::cout << point1 << '\n';

	Point point2;
	std::cin >> point2;
	std::cout << point2 << '\n';

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
	friend std::ostream& operator<<(std::ostream &out, const Fraction &f);
	friend std::istream& operator>>(std::istream &in, Fraction &f);
	

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

std::ostream& operator<<(std::ostream &out, const Fraction &f)
{
	out << f.m_numerator << "/" << f.m_denominator;

	return out;
}

std::istream& operator>>(std::istream &in, Fraction &f)
{
	char c;

	in >> f.m_numerator;
	in >> c; // hogy használhassuk a n/sz formulát.
	in >> f.m_denominator;

	// mivel átírjuk az f object értékeit, ezért itt is csökkenteni kell.
	f.reduce();
	return in;
}

int main(void)
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

	return 0;
}