#include "stdafx.h"
#include <iostream>

/*
ujraoldom az egyik feladatot, mert csak.
bubble sort feladat
*/

#include <utility>

int main()
{
	int sor[] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	const int hossz = sizeof(sor) / sizeof(sor[0]);

	for (int szamlalo = 0; szamlalo < hossz - 1; ++szamlalo)
	{
		int bubbleOptimalizalas = hossz - szamlalo;

		bool csere = false;

		for (int jelenlegiIndex = 0; jelenlegiIndex < hossz - 1; ++jelenlegiIndex)
		{
			if (sor[jelenlegiIndex] > sor[jelenlegiIndex + 1])
			{
				std::swap(sor[jelenlegiIndex], sor[jelenlegiIndex + 1]);
				csere = true;
			}

		}

		if (!csere)
		{
			std::cout << "A rendezes a " << szamlalo + 1 << " ismetleskor leallt.\n";
			break;
		}
	}

	for (int index = 0; index < hossz; ++index)
		std::cout << sor[index] << ' ';

	return 0;
}