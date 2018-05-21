#include "stdafx.h"
#include <iostream>

/*

írj egy programot, amely lekér egy számot a felhasználótól, majd annak kiszámolja a faktoriálisát.

*/

int lekerSzam()
{
	std::cout << "Irj be egy szamot amelynek kiakarod szamolni a faktorialisat: ";
	int szam;
	std::cin >> szam;

	return szam;
}

int main()
{
	int szam = lekerSzam();
	int szamlalo = 1;
	int faktor = 1;

	while (szamlalo <= szam)
	{
		faktor = faktor * szamlalo;
		++szamlalo;
	}

	/*
	pl. ha beírok 4-et, akkor ez 1*1, majd 1*2, majd 2*3, majd 6*4
	*/

	std::cout << "A szam faktorialisa: " << faktor << "\n";

	return 0;
}