#include "stdafx.h"
#include <iostream>

void foo(int x)
{
	std::cout << "x = " << x << '\n';
}

int main()
{
	foo(5);

	int x = 6;
	foo(x);
	foo(x + 1);

	return 0;
}