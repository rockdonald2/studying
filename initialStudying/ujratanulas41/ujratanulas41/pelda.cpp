#include "stdafx.h"
#include <iostream>

int lekerKisebbSzam()
{
	std::cout << "Irj be egy szamot: ";
	int kisebbSzam; // kisebbSzam letrejött itt, és csak ebben a blokkban érhető el.
	std::cin >> kisebbSzam;

	return kisebbSzam;
} // kisebbSzam megsemmisült itt

int lekerNagyobbSzam()
{
	std::cout << "Irj be egy nagyobb szamot mint az elozo: ";
	int nagyobbSzam;
	std::cin >> nagyobbSzam;

	return nagyobbSzam;
}

int main()
{
	int x = lekerKisebbSzam();
	int y = lekerNagyobbSzam();

	if (x > y)
	{
		std::cout << "Error! szamok felcserelese\n";
		int z = y;
		y = x;
		x = z;
	}

	else
	{
		std::cout << "A nagyobb szam: " << y << ".\n";
		std::cout << "A kisebb szam: " << x << ".\n";
	}

	return 0;
	
}
