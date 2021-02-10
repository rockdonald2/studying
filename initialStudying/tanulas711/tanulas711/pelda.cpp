#include "stdafx.h"
#include <iostream>

/*void szamoljLe(int szamlalo)
{
	std::cout << "felkerul " << szamlalo << '\n';
	if (szamlalo > 1)
		szamoljLe(szamlalo - 1);
	std::cout << "lekerul " << szamlalo << '\n';
}

int main()
{
	szamoljLe(5);
	
	return 0;
}*/

/*// egy funkció ami kiszámolja az 1 és az input érték közötti számok összegét(mind a kettőt belefoglalva)
int osszegAddig(int osszegaddig)
{
	// ha a szám 0, vagy negatív return 0;
	if (osszegaddig <= 0)
		return 0;
	// ha a szám 1, akkor return 1. Ez a befejezési kondicíó.
	else if (osszegaddig == 1)
		return 1;
	// rekurzív funkció hívás.
	else
		return osszegAddig(osszegaddig - 1) + osszegaddig;
}

int main()
{
	std::cout << osszegAddig(5) << ' ';

	return 0;
}*/

// fibonacci

/*int fibonacci(int szam)
{
	if (szam == 0)
		return 0;
	if (szam == 1)
		return 1;
	return fibonacci(szam - 1) + fibonacci(szam - 2);
}

int main()
{
	for (int szamlalo = 0; szamlalo < 13; ++szamlalo)
		std::cout << fibonacci(szamlalo) << ' ';

	return 0;
}*/