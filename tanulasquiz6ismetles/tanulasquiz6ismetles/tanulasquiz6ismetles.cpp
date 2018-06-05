#include "stdafx.h"
#include <iostream>

/*
Tégy úgy mintha egy játékot készítenél, amelyben a játékosnál 3 tárgy lehet egyszerre: életerőital, fáklya, nyílvessző.
	Használj egy enum-ot, hogy azonosítsd a különböző tárgyakat, és egy fix array-t, hogy raktározd a tárgyak számát amelyeket
		a játékos birtokol.
			A játékosnál 2 életerőital, 5 fáklya, és 10 nyílvessző kell legyen kezdésnél.
				Írj egy funkciót amelyben kiírod hány tárgy van a játékosnál összesen.
*/
/*
enum Targyak
{
	TARGY_ELETEROITAL,
	TARGY_FAKLYA,
	TARGY_NYILVESSZO,
	TARGY_SZAM,
};

int kiSzamolOsszTargy(int *kezdoTargyak)
{
	int ossz{ 0 };
	for (int index = 0; index < TARGY_SZAM; ++index)
		ossz += kezdoTargyak[index];

	return ossz;
}

int main()
{
	int kezdoTargyak[TARGY_SZAM] = { 2, 5, 10 };

	int ossz = kiSzamolOsszTargy(kezdoTargyak);

	std::cout << "A jatekosnal jelenleg " << ossz << " targy van.\n";

	return 0;
}*/

/*
Írd meg a következő programot: készíts egy struct-ot amely tartalmazza a tanulók neveit, és osztályzatát(0-100).
	Kérd a felhasználót, hogy írja be hány tanulót akar használni. Dinamikus elosztással létrehozott arrayben tárold a tanulókat.
		Majd kérd le az összes tanulót és jegyeiket.
			Amiután beírta, rendezd jegy alapján(legnagyobb először). Majd írd ki az összes tanulót és jegyet rendezett sorrendben.
*/
/*
#include <string>

struct Tanulok
{
	std::string nev;
	int jegy;
};

int main()
{
	int tanulokSzama{ 0 };
	std::cout << "Hany tanulot akarsz beirni: ";
	std::cin >> tanulokSzama;

	Tanulok *tanulok = new Tanulok[tanulokSzama];

	for (int index = 0; index < tanulokSzama; ++index)
	{
		std::cout << "Ird be az #" << index + 1 << " tanulo nevet: ";
		std::cin >> tanulok[index].nev;
		std::cout << "Ird be az #" << index + 1 << " tanulo jegyet: ";
		std::cin >> tanulok[index].jegy;
	}

	for (int kezdoIndex = 0; kezdoIndex < tanulokSzama - 1; ++kezdoIndex)
	{

		int legnagyobbIndex = kezdoIndex;

		for (int jelenlegiIndex = kezdoIndex + 1; jelenlegiIndex < tanulokSzama - 1; ++jelenlegiIndex)
		{
			if (tanulok[jelenlegiIndex].jegy < tanulok[legnagyobbIndex].jegy)
				legnagyobbIndex = jelenlegiIndex;
		}

		std::swap(tanulok[kezdoIndex], tanulok[legnagyobbIndex]);
	}

	for (int index = 0; index < tanulokSzama; ++index)
	{
		std::cout << tanulok[index].nev << " jegye " << tanulok[index].jegy << '\n';
	}

	return 0;

}*/

/*
Írj egy saját funkciót amelyben megcseréled két integer változó értékét.
	Használd a main() funkciót, hogy teszteld.
		! reference paraméterek
*/
/*
int csere(int &x, int &y)
{
	int idg;
	idg = x;
	x = y;
	y = idg;

	return x, y;
}

int main()
{
	int x = 5;
	int y = 7;
	csere(x, y);

	std::cout << "x = " << x << " | " << "y = " << y << '\n';

	return 0;
}*/

/*
Írj egy funkciót amely veszi egy C-style string karaktereit és kiírja egyesével.
	Használj egy pointert, hogy átlépkedj, és kiírd.
		Stop mikor null terminator.
			Main funkcióval teszteld a következő stringgel: "Hello, world!".
*/
/*
void kiIrString(char *string)
{
	while (*string != '\0')
	{
		std::cout << *string << ' ';
		++string;
	}
}

int main()
{
	char string[] = { "Hello, world!" };

	kiIrString(string);

	return 0;
}*/