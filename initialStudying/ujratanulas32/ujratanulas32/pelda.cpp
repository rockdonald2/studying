#include "stdafx.h"
#include <iostream>

/*int main()
{
	int x{ 5 };
	int y{ 2 };

	std::cout << "int / int = " << x / y << "\n";
	std::cout << "double / int = " << static_cast<double>(x) / y << "\n";
	std::cout << "int / double = " << x / static_cast<double>(y) << "\n";
	std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << "\n";

	return 0;
}*/

// QUIZ

/*

írj egy programot, amiben lekérsz egy egész számot, és kiírod a felhasználónak, hogy az a szám páros vagy páratlan.

*/

int lekerSzam()
{
	std::cout << "Irj be egy egesz szamot: ";
	int x;
	std::cin >> x;

	return x;
}

bool szamParos(int x)
{
	if (x % 2 == 0)
		return true;
	else
		return false;
}

int main()
{
	int x = lekerSzam();

	if (szamParos(x) == true)
		std::cout << "A beirt szam " << x << " paros.\n";
	else if (szamParos(x) == false)
		std::cout << "A beirt szam " << x << " paratlan.\n";

	return 0;
}