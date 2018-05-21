#include "stdafx.h"
#include <iostream>

/*int main()
{
	std::cout << "Irj be egy szamot: ";
	int szam1;
	std::cin >> szam1;

	std::cout << "Irj be egy masik szamot: ";
	int szam2;
	std::cin >> szam2;

	if (szam1 == szam2)
		std::cout << "A ket szam egyenlo.\n";
	else if (szam1 != szam2)
		std::cout << "A ket szam nem egyenlo.\n";
	if (szam1 > szam2)
		std::cout << "Az elso szam nagyobb mint a masodik szam.\n";
	else if (szam1 < szam2)
		std::cout << "A masodik szam nagyobb mint az elso szam.\n";
	if (szam1 >= szam2)
		std::cout << "Az elso szam nagyobb vagy egyenlo mint a masodik szam.\n";
	else if (szam1 <= szam2)
		std::cout << "A masodik szam nagyobb vagy egyenlo mint az elso szam.\n";
	else
		std::cout << "Nem tudom battya', val' error.";

	return 0;
}*/

#include <cmath> // kell a fabs funkció használatához
bool valodiSzamOsszehasonlitoFunckio(double szam1, double szam2, double absEpsilon, double relEpsilon)
{
	double kulonbseg = fabs(szam1 - szam2); // a fabs() funkció segítségével kiszámítjuk az első és második szám közötti különbségek,
													// és pozítiv számként jelenítjük meg.
	if (kulonbseg <= absEpsilon)   // ha ez a különbség kisebb vagy egyenlő mint a nekünk megfelelő elfogadási abszolút minimum, akkor
													// igaznak nyilvánítja és a két szám egyenlőként jeleníti meg.
		return true;

	// ha ez nem müködik, mert közel 0-hoz elbukik.

	return kulonbseg <= ((fabs(szam1) < fabs(szam2) ? fabs(szam2) : fabs(szam1)) * relEpsilon);
			// ez a Knuth algoritmus
					/*
						bal oldalt, a kulonbseg jelőli a kettő közti távolságot pozítiv számként

						jobb oldalt, kiszámoljuk a legnagyobb elfogadható értéket, amelyiknél a két szám egyenlő lesz.
							ehhez, a funkció kiválasztja a nagyobbat a két szám közül, és beszorozza a relatív epszilonnal.
									a relatív epszilon itt egy százalékot jelképez.
										tehát ha az epszilon 1%, akkor 1/100, tehát 0.01 a relatív epszilon.
					*/
}

int main()
{
	double a = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;

	std::cout << valodiSzamOsszehasonlitoFunckio(a-1., 0.0, 1e-12, 1e-8);

	return 0;
}