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

//int gcd(int a, int b) {
//	if (a == 0) {
//		return b;
//	}
//
//	else if (b == 0) {
//		return a;
//	}
//
//	else {
//		return gcd(b, a % b);
//	}
//}
//
//int lcm(int a, int b) {
//	return (a * b) / gcd(a, b);
//}
//
//class Fraction {
//private:
//	int m_numerator;
//	int m_denominator;
//
//public:
//	Fraction(int numerator = 0, int denominator = 1) : m_numerator(numerator), m_denominator(denominator) {
//		if (m_denominator == 0) {
//			std::cerr << "Denominator cannot be assigned 0\n";
//			exit(-1);
//		}
//	}
//
//	friend std::ostream& operator<<(std::ostream& out, const Fraction& fr) {
//		out << fr.m_numerator << " / " << fr.m_denominator << "\n";
//
//		return out;
//	}
//
//	friend Fraction operator+(Fraction& fr1, Fraction& fr2) {
//		int l = lcm(fr1.m_denominator, fr2.m_denominator);
//
//		return Fraction((l / fr1.m_denominator) * fr1.m_numerator + ((l / fr2.m_denominator) * fr2.m_numerator), l);
//	}
//
//	friend Fraction operator-(Fraction& fr1, Fraction& fr2) {
//		int l = lcm(fr1.m_denominator, fr2.m_denominator);
//
//		return Fraction((l / fr1.m_denominator) * fr1.m_numerator - ((l / fr2.m_denominator) * fr2.m_numerator), l);
//	}
//
//	friend Fraction operator*(Fraction& fr1, Fraction& fr2) {
//		return Fraction(fr1.m_numerator * fr2.m_numerator, fr1.m_denominator * fr2.m_denominator);
//	}
//
//	friend Fraction operator/(Fraction& fr1, Fraction& fr2) {
//		return Fraction(fr1.m_numerator * fr2.m_denominator, fr1.m_denominator * fr2.m_numerator);
//	}
//};
//
//int main() {
//	Fraction fr1(3, 4);
//	Fraction fr2(1, 2);
//
//	Fraction fr3 = fr1 + fr2;
//	std::cout << fr3;
//
//	return 0;
//}

class Matrix {
private:
	int m_matrix[2][2];

public:
	Matrix() {
		for (unsigned int i = 0; i < (sizeof(m_matrix) / sizeof(m_matrix[0])); ++i) {
			for (unsigned int j = 0; j < (sizeof(m_matrix[0]) / sizeof(m_matrix[0][0])); ++j) {
				m_matrix[i][j] = 0;
			}
		}
	}

	friend std::ostream& operator>>(std::ostream& out, const Matrix& m) {
		for (unsigned int i = 0; i < (sizeof(m_matrix) / sizeof(m_matrix[0])); ++i) {
			for (unsigned int j = 0; j < (sizeof(m_matrix[0]) / sizeof(m_matrix[0][0])); ++j) {
				out << m.m_matrix[i][j] << " ";
			}

			out << "\n";
		}
	}
};

int main() {
	Matrix matrix();

	std::cout << matrix;

	return 0;
}