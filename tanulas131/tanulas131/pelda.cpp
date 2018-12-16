#include "pch.h"
#include <iostream>

template <typename T>
const T& max(const T& x,const T& y)
{
	return (x > y ? x : y);
}

int main()
{
	int x{ 1 }, y{ 5 };
	double xD{ 4.5 }, yD{ 1.7 };

	std::cout << max(x, y) << '\n'; 
	std::cout << max(xD, yD) << '\n';

	return 1337;
}