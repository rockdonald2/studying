#include "stdafx.h"
#include <iostream>

// overflow példa


/*int main()
{
	unsigned short x = 65535; // a legnagyobb 16-bit unsigned érték
	std::cout << "x volt: "<< x << std::endl;
		x = x + 1;
	std::cout << "x jelenleg: " << x << std::endl;

		return 0;
}*/

// egész szám osztás

int main()
{
	std::cout << "Irj be egy szamot: ";
	short x;
	std::cin >> x;

	std::cout << "Irj be meg egy szamot: ";
	short y;
	std::cin >> y;

	std::cout << "A ket szam aranya: " << x / y << std::endl;
	return 0;
}

						// ha az osztás tört számot eredményez, a tört rész elvesztődik.