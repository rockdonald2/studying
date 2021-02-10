#include "stdafx.h"
#include <iostream>
#include "Vector3d.h"

Vector3d::Vector3d(double x, double y, double z) : m_x(x), m_y(y), m_z(z)
{}

void Vector3d::print()
{
	std::cout << "Point(" << m_x << "," << m_y << "," << m_z << ")\n";
}

