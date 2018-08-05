#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <cmath>

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


class FixedPoint2
{
private:
	int16_t m_num;
	int16_t m_frac;

public:
	FixedPoint2(int num = 0, int frac = 0) : m_num(num), m_frac(frac)
	{
		assert(num > -32768 && num < 32768 && "Out of range\n");
		
		if (num < 0 || frac < 0)
		{
			if (num > 0)
				m_num = -m_num;
			if (frac > 0)
				m_frac = -m_frac;
		}
	}

	FixedPoint2(double num)
	{
		m_num = static_cast<int16_t>(num);

		m_frac = static_cast<int16_t>(round((num - m_num) * 100));
	}

	friend std::ostream& operator<<(std::ostream &out, FixedPoint2 &f);
	friend std::istream& operator>>(std::istream &in, FixedPoint2 &f);

	operator double()
	{
		return m_num + static_cast<double>(m_frac) / 100;
	}

	friend bool operator==(FixedPoint2 &f1, FixedPoint2 &f2);

	FixedPoint2 operator-(FixedPoint2 &f);

	friend FixedPoint2 operator+(FixedPoint2 &f1, FixedPoint2 &f2);

};

std::ostream& operator<<(std::ostream &out, FixedPoint2 &f)
{
	out << static_cast<double>(f);

	return out;
}

std::istream& operator>>(std::istream &in, FixedPoint2 &f)
{
	double x;

	in >> x;

	f = FixedPoint2(x);

	return in;
}

bool operator==(FixedPoint2 &f1, FixedPoint2 &f2)
{
	return (f1.m_num == f2.m_num && f1.m_frac == f2.m_frac);
}

FixedPoint2 FixedPoint2::operator-(FixedPoint2 &f)
{
	return FixedPoint2(f.m_num, -f.m_frac);
}

FixedPoint2 operator+(FixedPoint2 &f1, FixedPoint2 &f2)
{
	if ((f1.m_frac + f2.m_frac) > 1)
	{
		++f1.m_num;

		f1.m_frac = ((f1.m_frac + f2.m_frac) - 1) * 100;
	}

	f1.m_num = f1.m_num + f2.m_num;

	return f1;
}



int main()
{
	FixedPoint2 a(34, 56);
	std::cout << a << '\n';

	FixedPoint2 b(-2, 8);
	std::cout << b << '\n';

	FixedPoint2 c(2, -8);
	std::cout << c << '\n';

	FixedPoint2 d(-2, -8);
	std::cout << d << '\n';

	FixedPoint2 e(0, -5);
	std::cout << e << '\n';

	std::cout << static_cast<double>(e) << '\n';

	FixedPoint2 f(0.01);
	std::cout << f << '\n';
	
	FixedPoint2 g(-0.01);
	std::cout << g << '\n';
	std::cout << -g << '\n';

	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23));
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50));

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow

	return 0;
}