#include "stdafx.h"
#include <iostream>

int main()
{
	int ertek = 7;
	int *mutato = &ertek;

	std::cout << mutato << ' '; // az integer adattípus mérete 4 byte
	std::cout << mutato + 1 << ' '; // azt jelenti, hogy 4 byte-al a mutato után
	std::cout << mutato + 2 << ' '; // azt jelenti, hogy 8 byte-al a mutato után
	std::cout << mutato + 3 << ' '; // azt jelenti, hogy 12 byte-al a mutato után

	std::cout << '\n';

	std::cout << *mutato << ' ';
	std::cout << *(mutato + 1) << ' ';
	std::cout << *(mutato + 2) << ' ';
	std::cout << *(mutato + 3) << ' ';

	std::cout << '\n';

	int sor[5] = { 1, 2, 3, 4, 5 };
	std::cout << &sor[0] << ' ';
	std::cout << &sor[1] << ' ';
	std::cout << &sor[2] << ' ';
	std::cout << &sor[3] << ' ';
	std::cout << &sor[4] << ' ';

	std::cout << '\n';

	return 0;
}