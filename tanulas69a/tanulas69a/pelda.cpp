#include "stdafx.h"
#include <iostream>

/*
QUIZ

írj egy programot amelyben:
	a felhasználótól lekéred hány nevet akar beírni, lekéred mindegyik nevet, lehív egy funkciót amely selection sorttal rendezi,
	majd kiírja a rendezett névsort.

		- használj egy std::string dinamikus arrayt a név tárolásra
		- az std::string támogassa, hogy stringeket hasonlíts össze az összehasonlító operátorral(< >)
*/

#include <string> // std::stringhez
#include <algorithm> // std::swaphoz

int main()
{
	std::cout << "Ird be a nevsor hosszat: ";
	int hossz;
	std::cin >> hossz;

	std::string *nevsor = new std::string[hossz]; // dinamikusan létrehozok egy std::string arrayt

	std::cout << "A nevsorod hossza " << hossz << '\n';

	for (int index = 0; index < hossz; ++index)
	{
		std::cout << "Ird be a(z) " << index + 1 << " nevet: ";
		std::cin >> nevsor[index];
	}

	std::cout << "A nevsor rendezes elott: " << '\n';

	for (int index = 0; index < hossz; ++index)
	{
		std::cout << index + 1 << ". nev: "  << nevsor[index] << '\n';
	}

	std::cout << "A nevsor rendezes utan: " << '\n';

	for (int startIndex = 0; startIndex < hossz - 1; ++startIndex)
	{
		int kisebbIndex = startIndex;

		for (int jelenlegiIndex = startIndex + 1; jelenlegiIndex < hossz; ++jelenlegiIndex)
		{
			if (nevsor[jelenlegiIndex] < nevsor[kisebbIndex])
				
				kisebbIndex = jelenlegiIndex;
		}

		std::swap(nevsor[startIndex], nevsor[kisebbIndex]);
	}

	for (int index = 0; index < hossz; ++index)
	{
		std::cout << index + 1 << ". nev: " << nevsor[index] << '\n';
	}

	std::cout << '\n';


	delete[] nevsor; // törlöm a dinamikusan létrehozott arrayemet
	nevsor = nullptr; // a mutató értékét nullázom
	return 0;
}