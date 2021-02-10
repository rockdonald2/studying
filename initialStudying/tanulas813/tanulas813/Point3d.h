#ifndef POINT3D_H
#define POINT3D_H

class Vector3d;

class Point3d
{
private:
	double m_x, m_y, m_z;

public:
	Point3d(double x = 0, double y = 0, double z = 0);

	void print();

	void moveByVector(Vector3d &vector);
};

#endif
