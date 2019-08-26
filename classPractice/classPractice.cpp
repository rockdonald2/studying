#include <iostream>

//class Point2d {
//private:
//	double m_x;
//	double m_y;
//
//public:
//	Point2d(double x = 0.0, double y = 0.0) : m_x(x), m_y(y) {
//		std::cout << "Initialization completed\n";
//	}
//
//	double getX() const {
//		return this->m_x;
//	}
//
//	double getY() const {
//		return this->m_y;
//	}
//
//	void print() {
//		std::cout << "Point2d(" << this->m_x << ", " << this->m_y << ")\n";
//	}
//
//	double distanceTo(const Point2d& point) const {
//		return sqrt((this->m_x - point.m_x) * (this->m_x - point.m_x) + (this->m_y - point.m_y) * (this->m_y - point.m_y));
//	}
//
//	friend double distanceFrom(const Point2d& point1, const Point2d& point2);
//};
//
//double distanceFrom(const Point2d& point1, const Point2d& point2) {
//	return sqrt((point1.getX() - point2.getX()) * (point1.getX() - point2.getX()) + (point1.getY() - point2.getY()) * (point1.getY() - point2.getY()));
//}
//
//int main()
//{
//	Point2d first;
//	Point2d second(3.0, 4.0);
//	first.print();
//	second.print();
//	std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
//	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
//
//	return 0;
//}

//class HelloWorld
//{
//private:
//	char* m_data;
//
//public:
//	HelloWorld()
//	{
//		m_data = new char[14];
//		const char* init = "Hello, World!";
//		for (int i = 0; i < 14; ++i)
//			m_data[i] = init[i];
//	}
//
//	~HelloWorld()
//	{
//		std::cout << "\nDestructor called\n";
//		delete[] m_data;
//	}
//
//	void print() const
//	{
//		std::cout << m_data;
//	}
//
//};
//
//int main()
//{
//	HelloWorld hello;
//	hello.print();
//
//	return 0;
//}