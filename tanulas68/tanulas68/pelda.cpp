#include "stdafx.h"
#include <iostream>

int main()
{
	int sor[5] = { 9, 7, 5, 3, 1 };

	std::cout << &sor << '\n';

	int *mutato = sor;
	std::cout << &mutato << '\n';

	return 0;
}