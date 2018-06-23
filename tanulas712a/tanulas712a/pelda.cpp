#include "stdafx.h"
#include <iostream>

#include <cassert>
#include <array>

int lekerArrayErtek(std::array<int, 10> &array, int index)
{
	// kijelentjük, hogy az index 0 és 9 között van
	assert(index >= 0 && index <= 9 && "Az index tul kicsi/tul nagy a hasznalathoz");

	return array[index];
}

int main()
{
	std::array<int, 10> array = { 2, 3, 5, 7, 1, 11, 43, 22, 16, 27 };

	std::cout << lekerArrayErtek(array, 1);

	return 0;
}

