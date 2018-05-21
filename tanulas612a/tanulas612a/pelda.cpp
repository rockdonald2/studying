#include "stdafx.h"
#include <iostream>

/*int main()
{
	int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	for (auto szam : fibonacci)
		std::cout << szam << ' ';

			// ! ebben az esetben a szam nem array index, hanem egy adathordozó ami tárolja a jelenlegi array elem értékét

	for (const auto &elem : fibonacci)
		std::cout << elem << ' ';

	return 0;
}*/


/*
Quiz,
Határozz meg egy fix arrayt a következő nevekkel: Alex, Betty, Caroline, Dave, Emily, Fred, Greg, és Holly.
	Kérd a felhasználót, hogy írjon be egy nevet. Használj egy for-each loopot, hogy leellenőrízd, hogy a név amit beírtak
		megtalálható-e az arrayben.

*/

#include <string>

int main()
{
	std::string nevSor[] = { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

	std::cout << "Irj be egy nevet: ";
	std::string lekertNev;
	std::getline(std::cin, lekertNev);

	bool megtalalhato{ false };

	for (std::string nev : nevSor)
	{
		if (lekertNev == nev)
		{
			megtalalhato = true;
			break;
		}
	}

	if (megtalalhato)
		std::cout << lekertNev << " megtalalhato a nevsorban.\n";
	else
		std::cout << lekertNev << " nem talalhato meg a nevsorban.\n";

	return 0;
}