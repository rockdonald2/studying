#include "stdafx.h"
#include <iostream>

#define __STDC_WANT_LIB_EXT1__ 1
#include <cstring> // for strcpy_s

int main()
{
	char peldaString[] = "pelda";
	int hossz = sizeof(peldaString) / sizeof(peldaString[0]);
	std::cout << peldaString << " egy C-style string, aminek van " << hossz << " karaktere.\n";
	for (int index = 0; index < hossz; ++index)
		std::cout << static_cast<int>(peldaString[index]) << '\t';

	peldaString[0] = 'z';
	std::cout << "A valtoztatas utan a string: " << peldaString << "\n";

	std::cout << "\n";
	char nev[255];
	std::cout << "Ird be a neved: ";
	std::cin.getline(nev, 255);
	std::cout << "A neved: " << nev << "\n";
	std::cout << "A neved tartalmaz " << strlen(nev) << " karaktert.\n";
	std::cout << "Az array tartalmazhat maximum " << sizeof(nev) / sizeof(nev[0]) << " karaktert.\n";

	char forras[] = "Masold ezt!";
	char celAllomas[50];
	strcpy_s(celAllomas, 50, forras);
	std::cout << celAllomas << '\n';

	

	return 0;
}