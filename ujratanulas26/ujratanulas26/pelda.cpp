#include "stdafx.h"
#include <iostream>

/*

int main()
{
	std::cout << "Irj be egy szamot:";
	int x;
	std::cin >> x;

	if (x == 0)   // == operatort arra használjuk, hogy összehasonlítsuk a két szám egyenlő-e vagy sem
		std::cout << "Az ertek nulla." << "\n";
	else
		std::cout << "Az ertek nem nulla." << "\n";

	return 0;
}

*/

/*
// return-ol true-t ha egyenlőek, false-t ha nem.
bool egyenloek(int x, int y)
{
	return (x == y);
}

int main()
{
	std::cout << "Irj be egy egesz szamot:";
	int x;
	std::cin >> x;

	std::cout << "Irj be egy masik egesz szamot:";
	int y;
	std::cin >> y;

	if (egyenloek(x, y))
		std::cout << x << " es " << y << " egyenloek." << "\n";
	else
		std::cout << x << " es " << y << " nem egyenloek." << "\n";

	return 0;
}
*/

// QUIZ

bool primSzam(int x)
{
	return (x == 2 || x == 3 || x == 5 || x == 7);
}

int main()
{
	std::cout << "Irj be egy szamot 1-tol 9-ig: ";
	int x;
	std::cin >> x;

	if (primSzam(x))
		std::cout << "A beirt szamod primszam." << "\n";
	else
		std::cout << "A beirt szamod nem primszam." << "\n";

	return 0;
}