#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include "stdafx.h"

class Point2d
{
private:
	int m_x;
	int m_y;

public:
	Point2d() : m_x(0), m_y(0)
	{}

	Point2d(int x, int y) : m_x(x), m_y(y)
	{}

	friend std::ostream& operator<<(std::ostream &out, const Point2d &p)
	{
		out << "(" << p.m_x << "," << p.m_y << ")";

		return out;
	}

	void setPoint(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
};


#endif
