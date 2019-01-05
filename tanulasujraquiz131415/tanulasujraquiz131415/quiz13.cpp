#include "pch.h"
#include <iostream>

/*template <class T>
class Pair1
{
private:
	T m_x;
	T m_y;

public:
	Pair1(T x, T y) : m_x(x), m_y(y) {}

	const T& first() const { return m_x; }
	T& first() { return m_x; }

	const T& second() const { return m_y; }
	T& second() { return m_y; }
};

template <class T1, class T2>
class Pair
{
private:
	T1 m_x;
	T2 m_y;

public:
	Pair(T1 x, T2 y) : m_x(x), m_y(y) {}

	const T1& first() const { return m_x; }
	T1& first() { return m_x; }

	const T2& second() const { return m_y; }
	T2& second() { return m_y; }
};

#include <string>

template <class T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(std::string str, T x) : Pair<std::string, T>(str, x) {}
};

int main()
{
	Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.5, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<int, double> p3(5, 6.7);
	std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

	const Pair<double, int> p4(2.3, 4);
	std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}*/