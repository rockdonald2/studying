#include "stdafx.h"
#include <iostream>
#include <cassert>

/*class Matrix
{
private:
	double m_data[4][4];

public:
	Matrix()
	{
		for (int row = 0; row < 4; ++row)
			for (int col = 0; col < 4; ++col)
				m_data[row][col] = 0.0;
	}

	double& operator()(int row, int col);
	const double& operator()(int row, int col) const;
	void operator()();
};

double& Matrix::operator()(int row, int col)
{
	assert(col >= 0 && col < 4);
	assert(row >= 0 && row < 4);

	return m_data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
	assert(col >= 0 && col < 4);
	assert(row >= 0 && row < 4);

	return m_data[row][col];
}

void Matrix::operator()()
{
	for (int row = 0; row < 4; ++row)
		for (int col = 0; col < 4; ++col)
			m_data[row][col] = 0.0;
}

int main()
{
	Matrix matrix;
	matrix(1, 2) = 4.5;
	std::cout << matrix(1, 2) << '\n';
	matrix();
	std::cout << matrix(1, 2) << '\n';

	return 0;
}*/

/*class Value
{
private:
	int m_counter = 0;

public:
	Value() {}

	int operator() (int i) { return m_counter += i; }
};

int main()
{
	//functor
	Value vlm;
	std::cout << vlm(10) << '\n';
	std::cout << vlm(20) << '\n';

	return 0;
}*/

#include <string>

class Mystring
{
private:
	std::string m_string;

public:
	Mystring(std::string string) : m_string(string)
	{}

	std::string operator()(int index, int length);
};

std::string Mystring::operator()(int index, int length)
{
	std::string temp;

	for (int count = 0; count < length; ++count)
	{
		temp += m_string[count + index];
	}

	return temp;
}

int main()
{
	Mystring string("Hello, world!");
	std::cout << string(7, 5) << '\n';

	return 0;
}