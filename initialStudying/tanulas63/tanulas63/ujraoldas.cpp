#include "stdafx.h"
#include <iostream>

/*
ujraoldom az egyik feladatot, mert csak.
	használd a megadott arrayt,
		kérj le a felhasználótól egy számot 1 és 9 között, újra és újra kérd ha nem felel meg,
			majd ha beírta a megfelelő számot írd ki a teljes arrayt, majd keresd meg az arrayban annak a számnak az indexét
			amelyet a felhasználó beírt és írd ki
*/

int lekerSzam()
{
	int szam = 0;
	do
	{
		std::cout << "Irj be egy szamot 1 es 9 kozott: ";
		std::cin >> szam;

		if (std::cin.fail()) // ha esetleg rossz inputot írna be
		{
			std::cin.clear();
			std::cin.ignore(32768, '\n');
		}
	} while (szam < 1 || szam > 9);

	std::cin.ignore(32768, '\n');
	return szam;
}

bool szamEllenorzes(int szam)
{
	if (szam < 1 || szam > 9)
		return true;
	else
		return false;
}

void teszt1()
{
	int szam = lekerSzam();
	std::cout << szam;
}

int main()
{
	int sor[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	const int sorHossz = sizeof(sor) / sizeof(sor[0]);

	int szam = lekerSzam();
	bool szamEllenorzes(szam);
	if (szamEllenorzes)
	{
		for (int index = 0; index < sorHossz; ++index)
			std::cout << sor[index] << ' ';
	}

	std::cout << "\n";

	for (int index = 0; index < sorHossz; ++index)
	{
		if (sor[index] == szam)
		{
			std::cout << index << ' ';
			break;
		}

	}

	return 0;
}