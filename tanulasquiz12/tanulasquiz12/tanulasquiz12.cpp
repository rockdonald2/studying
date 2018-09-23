#include "pch.h"
#include <iostream>
#include <vector> // std::vector

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z) : m_x(x), m_y(y), m_z(z) {}

	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";

		return out;
	}
};

class Shape
{
public:
	virtual std::ostream& print(std::ostream &out) const = 0;
	friend std::ostream& operator<<(std::ostream &out, const Shape &s)
	{
		return s.print(out);
	}
	virtual ~Shape() {}
};

class Triangle : public Shape
{
protected:
	Point m_p1;
	Point m_p2;
	Point m_p3;

public:
	Triangle(const Point &p1, const Point &p2, const Point &p3) : m_p1(p1), m_p2(p2), m_p3(p3)
	{
		
	}
	virtual std::ostream& print(std::ostream &out) const
	{
		out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";

		return out;
	}
};

class Circle : public Shape
{
protected:
	Point m_c;
	int m_r;

public:
	Circle(const Point &p, int r) : m_c(p), m_r(r) {}

	virtual std::ostream& print(std::ostream &out) const
	{
		out << "Circle(" << m_c << ", radius " << m_r << ")";

		return out;
	}

	const int getRadius() { return m_r; }
};

int getLargestRadius(std::vector<Shape*> &v)
{
	int largestRadius = 0;
	for (int count = 0; count < v.size(); ++count)
	{
		Shape *s = v[count];
		Circle *c = dynamic_cast<Circle*>(s);
		if (c)
		{
			if (c->getRadius() > largestRadius)
				largestRadius = c->getRadius();
		}
	}

	return largestRadius;
}

int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	for (int count = 0; count < v.size(); ++count)
		std::cout << (*v[count]) << '\n';

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

	for (int count = 0; count < v.size(); ++count)
		delete v[count];

	return 0;
}