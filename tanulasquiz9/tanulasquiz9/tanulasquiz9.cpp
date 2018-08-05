#include "stdafx.h"
#include <iostream>
#include <cassert>

/*

1a) friennd function overload
1b) member function overload
1c) friend function overload
1d) member function overload

*/


/*class Average
{
private:
	int32_t m_avg;
	int8_t m_num;

public:
	Average(int avg = 0, int num = 0) : m_avg(avg), m_num(num)
	{}

	Average(const Average &a)
	{
		m_avg = a.m_avg;
		m_num = a.m_num;
	}

	Average& operator+=(int value);
	Average& operator=(Average &a);
	friend std::ostream& operator<<(std::ostream &out, Average &a);
};

Average& Average::operator+=(int value)
{
	Average::m_avg += value;
	++Average::m_num;

	return *this;
}

Average& Average::operator=(Average &a)
{
	if (this == &a)
		return *this;

	Average::m_avg = a.m_avg;
	Average::m_num = a.m_num;

	return *this;
}

std::ostream& operator<<(std::ostream &out, Average &a)
{
	out << static_cast<double>(a.m_avg) / a.m_num;

	return out;
}

int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	return 0;
}*/


/*class IntArray
{
private:
	int *m_array = nullptr;
	int m_length = 0;

public:
	IntArray(int length = 0) : m_length(length)
	{
		assert(length > 0 && "Az array hossza egy pozitiv egesz szam kell legyen!\n");

		m_array = new int[m_length] { 0 };
	}

	IntArray(const IntArray &a)
	{
		m_length = a.m_length;

		m_array = new int[m_length];

		for (int index = 0; index < m_length; ++index)
		{
				m_array[index] = a.m_array[index];
		}

	}

	~IntArray()
	{
		delete[] m_array;
		m_length = 0;
	}

	int& operator[](const int index);
	friend std::ostream& operator<<(std::ostream &out, const IntArray &a);
	IntArray& operator=(const IntArray &a);
};

int& IntArray::operator[](const int index)
{
	assert(index >= 0);
	assert(index < m_length);

	return m_array[index];
}

std::ostream& operator<<(std::ostream &out, const IntArray &a)
{
	for (int index = 0; index < a.m_length; ++index)
	{
		out << a.m_array[index] << ' ';
	}

	return out;
}

IntArray& IntArray::operator=(const IntArray &a)
{
	if (this == &a)
		return *this;

	m_length = a.m_length;

	delete[] m_array;
		
	m_array = new int[m_length];

		
	for (int index = 0; index < m_length; ++index)
	{
		m_array[index] = a.m_array[index];
	}

	return *this;
}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}*/


