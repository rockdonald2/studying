#include "pch.h"
#include <iostream>

template<class T1>
class Pair1
{
private:
	T1 m_x;
	T1 m_y;

public:
	Pair1(const T1 x, const T1 y) : m_x(x), m_y(y)
	{}

	T1 first() { return m_x; }
	const T1 first() const { return m_x; }

	T1	second() { return m_y; }
	const T1 second() const { return m_y; }
};

template <class T1, class T2>
class Pair
{
private:
	T1 m_x;
	T2 m_y;

public:
	Pair(const T1 x, const T2 y) : m_x(x), m_y(y)
	{

	}

	T1 first() { return m_x; }
	T1 first() const { return m_x; }

	T2 second() { return m_y; }
	T2 second() const { return m_y; }
};

#include <string>

template<class T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(std::string str, T x) : Pair<std::string, T>(str, x) {}
};

int main()
{
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}