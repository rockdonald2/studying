#include "stdafx.h"
#include <iostream>

int lekerSzam()
{
	std::cout << "Irj be egy egesz szamot 0-tol 255-ig: ";
	int szam;
	std::cin >> szam;

	return szam;
}

int atalakitBinaris(int szam, int pow)
{
	if (szam >= pow)
		std::cout << "1";
	else
		std::cout << "0";

	if (szam >= pow)
		return (szam - pow);
	else
		return szam;
}

int ellenorzesEgeszSzam()
{

}

