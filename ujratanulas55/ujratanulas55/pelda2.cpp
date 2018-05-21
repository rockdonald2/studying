#include "stdafx.h"
#include <iostream>

/*

írj egy programot ami lekér számokat, majd összeget számol belőlük

*/

int main()
{
	int szamlalo = 1;
	int osszeg = 0;

	while (szamlalo <= 10)
	{
		int x;

		std::cout << "Irj be egy szamot: ";
		std::cin >> x;

		osszeg = osszeg + x;

		++szamlalo;
	}
	
	std::cout << "A szamok osszege = " << osszeg << "\n";

	return 0;
}