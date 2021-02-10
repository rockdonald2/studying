#include "stdafx.h"
#include <iostream>
#include <vector>
#include <array>


int main()
{
	std::vector<int> dArray = { 2, 6, 8, 1, 3, 9, 7, 5, 4 };

	std::cout << "Az array hossza: " << dArray.size() << std::endl;

	std::cout << "A rendezett array: ";
	std::sort(dArray.rbegin(), dArray.rend());
	for (const int &elem : dArray)
		std::cout << elem << ' ';

	dArray.resize(5);
	std::cout << "A lecsokkentett array merete: " << dArray.size() << std::endl;

	return 0;
}