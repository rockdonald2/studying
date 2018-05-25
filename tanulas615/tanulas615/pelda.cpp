#include "stdafx.h"
#include <iostream>
#include <array>
#include <algorithm>

// ! szabály, mindig add tovább az std::array-t egy hivatkozással, vagy const hivatkozással mint itt.
void funkcio(const std::array<int, 5> &array)
{
	std::cout << "Az array hossza = " << array.size() << std::endl;
}
int main()
{
	std::array<int, 5> array;

	array.at(1) = 6; // beállítja az első elem értékét 6-ra.
	// array.at(9) = 9; // error, 9-es elem nem létezik.

	funkcio(array);

	array = { 5, 4, 7, 9, 1 };

	for (auto &elem : array)
		std::cout << elem << ' ';

	std::sort(array.begin(), array.end()); // rendezze előre.
	// std::sort(array.rbegin(), array.rend()); ahhoz, hogy fordítva

	for (auto &elem : array)
		std::cout << elem << ' ';


	return 0;
}