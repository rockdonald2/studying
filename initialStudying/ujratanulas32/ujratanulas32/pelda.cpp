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

�rj egy programot, amiben lek�rsz egy eg�sz sz�mot, �s ki�rod a felhaszn�l�nak, hogy az a sz�m p�ros vagy p�ratlan.

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