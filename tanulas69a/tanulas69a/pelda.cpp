#include "stdafx.h"
#include <iostream>

/*
QUIZ

�rj egy programot amelyben:
	a felhaszn�l�t�l lek�red h�ny nevet akar be�rni, lek�red mindegyik nevet, leh�v egy funkci�t amely selection sorttal rendezi,
	majd ki�rja a rendezett n�vsort.

		- haszn�lj egy std::string dinamikus arrayt a n�v t�rol�sra
		- az std::string t�mogassa, hogy stringeket hasonl�ts �ssze az �sszehasonl�t� oper�torral(< >)
*/

#include <string> // std::stringhez
#include <algorithm> // std::swaphoz

int main()
{
	std::cout << "Ird be a nevsor hosszat: ";
	int hossz;
	std::cin >> hossz;

	std::string *nevsor = new std::string[hossz]; // dinamikusan l�trehozok egy std::string arrayt

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


	delete[] nevsor; // t�rl�m a dinamikusan l�trehozott arrayemet
	nevsor = nullptr; // a mutat� �rt�k�t null�zom
	return 0;
}