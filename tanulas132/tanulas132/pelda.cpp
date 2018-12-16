#include "pch.h"
#include <iostream>

/*class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) : m_cents(cents)
	{}

	friend bool operator>(const Cents &c1, const Cents &c2)
	{
		return (c1.m_cents > c2.m_cents);
	}
};

template <typename T>
const T& max(const T& x, const T& y)
{
	return (x > y) ? x : y;
}

int main()
{
	Cents tucat(12);
	Cents kilo(1000);

	Cents nagyobb = max(tucat, kilo);

	return 1337;
}*/

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) : m_cents(cents)
	{}

	friend bool operator>(const Cents &c1, const Cents &c2)
	{
		return (c1.m_cents > c2.m_cents);
	}

	friend std::ostream& operator<<(std::ostream &out, const Cents &c)
	{
		out << c.m_cents << " cent";
		return out;
	}

	Cents& operator +=(Cents c)
	{
		m_cents += c.m_cents;
		return *this;
	}

	Cents& operator /=(Cents c)
	{
		m_cents /= c.m_cents;
		return *this;
	}
};

template <typename T>
T average(T *array, int length)
{
	T sum = 0;
	for (int count = 0; count < length; ++count)
		sum += array[count];

	sum /= length;
	return sum;
}

int main()
{
	int array1[] = { 9, 8, 7, 6, 5, 4, 3 };
	double array2[] = { 9.2, 7.2, 6.5, 4.6, 3.2, 2.1 };

	std::cout << average(array1, 7) << '\n';
	std::cout << average(array2, 6) << '\n';

	Cents array3[] = { Cents(12), Cents(16), Cents(50), Cents(1000) };

	std::cout << average(array3, 4) << '\n';

	return 1337;
}