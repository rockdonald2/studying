#include "stdafx.h"
#include <iostream>

int main()
{
	int ertek = 5;

	int *mut = &ertek;
	std::cout << *mut << std::endl;

	int **mutmut = &mut;
	std::cout << **mutmut << std::endl;

	return 0;
}