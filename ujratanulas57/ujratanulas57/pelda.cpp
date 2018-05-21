#include "stdafx.h"
#include <iostream>


/*

írj egy programot for loopal, amey kiírja az összes páros számot 0-tól 20ig.

*/

/*int main()
{
	for (int szamlalo = 0; szamlalo <= 20; ++szamlalo)
	{
		if (szamlalo % 2 == 0)
			std::cout << szamlalo << "\n";
	}

	return 0;
}*/

/*

írj egy funkciót amely felhasznál egy integer paramétert, és kiírja az összeget 1től, addig a számig.

	pl. teljesOsszeg(5) ki kéne írja ,hogy 15, mert 1 + 2 + 3 + 4 + 5 = 15

*/

int teljesOsszeg(int x)
{
	int osszeg = 0;

	for (int szamlalo = 1; szamlalo <= x; ++szamlalo)
		osszeg += szamlalo;

	return osszeg;
}


int main()
{
	int x = 5;

	std::cout << teljesOsszeg(5) << "\n";

	return 0;
}