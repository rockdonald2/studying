#include "pch.h"
#include <iostream>

// 1
/*template <class T>
class Pair1
{
private:
	T m_x;
	T m_y;

public:
	Pair1(const T x, const T y) : m_x(x), m_y(y) {}

	T& first()
	{
		return m_x;
	}

	T& second()
	{
		return m_y;
	}

	const T& first() const
	{
		return m_x;
	}

	const T& second() const
	{
		return m_y;
	}

};

int main()
{
	Pair1<int> p1(5, 8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(2.3, 4.5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}*/

// 2
template <class T1, class T2>
class Pair
{
protected:
	T1 m_x;
	T2 m_y;

public:
	Pair(const T1 x, const T2 y) : m_x(x), m_y(y)
	{}

	const T1& first() { return m_x; }
	const T1& first() const { return m_x; }

	const T2& second() { return m_y; }
	const T2& second() const { return m_y; }
};

#include <string>

// 3
template <class T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(std::string value, T x):
		Pair<std::string, T>(value, x) {}
};

int main()
{
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}