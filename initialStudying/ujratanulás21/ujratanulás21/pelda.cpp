#include "stdafx.h"
#include <iostream>

int main()
{
	std::cout << "Irj be egy szamot: ";
	int x;
	std::cin >> x;

	std::cout << "Irj be egy másik számot: ";
	int y;
	std::cin >> y;

	std::cout << "A ket szam összege: " << x + y << std::endl;

	return 0;

	 // fontos szabály, ha lehet a felhasználáshoz lehető legközelebb definiáld a változókat.
}