#include "stdafx.h"
#include <iostream>

#include <iomanip> // std::setprecision-hez.
#include <typeinfo> // typeid() parancshoz
int main()
{
	int szam = 30000;
	char kar = szam;
	std::cout << static_cast<int>(kar) << "\n"; // 48-at fog kiírni, overflow lép fel.

	int szam1 = 2;
	short szam2 = szam1; // átalakítja az int típust shorttá.
	std::cout << szam2 << "\n";

	double szam3 = 0.1234;
	float szam4 = szam3; // átalakítja a doublet floattá.
	std::cout << szam4 << "\n";

	float szam5 = 0.123456789; // 9 pont utáni számjegy, a float csak 7-et támogat.
	std::cout << std::setprecision(9) << szam5 << "\n"; // meghatározzuk, hogy 9-et írjon ki.
		// de 0.123456791 -- kerekítési hiba.

	int szam6 = 12;
	float szam7 = szam6; // int alakítása floattá.
	std::cout << szam7 << "\n";

	float szam8 = 4.2;
	int szam9 = szam8; // float átalakítása int-é.
	std::cout << szam9 << "\n";

	
	//számtani átalakítás
	short szam10 = 2;
	short szam11 = 3;
	std::cout << typeid(szam10 + szam11).name() << " " << szam10 + szam11 << "\n"; // megmutatja az a + b számtani művelet típusát.
		// ez esetben integral promotion történik, mindkét operándust int-é alakítja a compiler.


	double szam12 = 6.0;
	short szam13 = 1;
	std::cout << typeid(szam12 + szam13).name() << " " << szam12 + szam13 << "\n";
		// ez esetben az integral promotion nem elég, hanem először a short-ot int-é alakítja előléptetéssel, majd
			// megkeresi a legnagyobb priorítású operándust a double-t és azzá alakítja a short-ból lett int-et.

	return 0;
}