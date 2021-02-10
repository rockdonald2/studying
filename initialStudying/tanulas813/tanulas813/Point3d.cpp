#include "stdafx.h"
#include <iostream>
#include "Point3d.h"
#include "Vector3d.h"

Point3d::Point3d(double x, double y, double z) : m_x(x), m_y(y), m_z(z)
{}

void Point3d::print()
{
	std::cout << "Point(" << m_x << "," << m_y << "," << m_z << ")\n";
}

void Point3d::moveByVector(Vector3d &vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;
}
