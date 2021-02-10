#include "stdafx.h"
#include <iostream>

/*class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) : m_cents(cents)
	{}

	Cents operator-() const;
	Cents operator!() const;

	int getCents() const { return m_cents; }
};

Cents Cents::operator-() const
{
	return Cents(-m_cents);
}

int main()
{
	return 0;
}*/


class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z)
	{}

	Point operator-() const;
	bool operator!() const;
	Point operator+() const;

	friend std::ostream& operator<<(std::ostream &out, const Point &point);

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }
};


Point Point::operator-() const
{
	return Point(-m_x, -m_y, -m_z);
}

Point Point::operator+() const
{
	return Point(+m_x, +m_y, +m_z);
}

bool Point::operator!() const
{
	return (m_x == 0.0 && m_y == 0.0 && m_z == 0);
}

std::ostream& operator<<(std::ostream &out, const Point &point)
{
	out << "(" << point.m_x << "," << point.m_y << "," << point.m_z << ")";

	return out;
}

int main()
{
	Point point;
	Point point2{ 3.2, 2.5, 1.7 };

	if (!point)
		std::cout << "point is set at the origin.\n";
	else
		std::cout << "point is not set at the origin.\n";

	if (!point2)
		std::cout << "point is set at the origin.\n";
	else
		std::cout << "point is not set at the origin.\n";

	std::cout << -point2 << '\n';
	std::cout << +point2 << '\n';

	return 0;
}