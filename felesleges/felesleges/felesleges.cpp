#include "pch.h"
#include <iostream>

int main()
{
	int f = 1, i = 2;

	while (++i < 5)
		f*=i;

	std::cout << f;

	return 0;
}