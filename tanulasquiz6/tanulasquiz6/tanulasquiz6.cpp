#include "stdafx.h"
#include <iostream>

/*

írsz egy játékot amelyben a játékos 3 fajta tárgyat tud birtokolni: eletero ital, faklya, nyilak.
	használj enumot, hogy azonosítsd ezeket a tárgyakat, és egy fix arrayt, hogy raktározd az adott tárgyból hány darab van a játékosnál.
	a játékosnak 2 eletero itala, 5 faklyaja, és 10 nyila kellene legyen.
	írj egy funkciót ami összegezi a tárgyakat, és kiírja összesen hány tárgya van a játékosnak.
	a main() írja ki az összegző funkció eredményét.

*/
/*
enum Targyak
{
	ELETEROITAL,
	FAKLYA,
	NYILAK,
	TARGYAKSZAMA,
};

int SzamolOsszTargyak(int *targyak)
{
	int osszTargyak{ 0 };

	for (int index = 0; index < TARGYAKSZAMA; ++index)
		osszTargyak += targyak[index];

	return osszTargyak;
}


int main()
{
	int kezdoTargyak[TARGYAKSZAMA] = { 2, 5, 10 };

	std::cout << "A jatekosnal levo osszes targy szama: " << SzamolOsszTargyak(kezdoTargyak) << "\n";

	return 0;
}*/

/*

Írj egy programot melyben, készítesz egy structot ami tartalmazza a tanuló első nevét és osztályzatát(0-100).
	kérd le hány tanulót akar beírni. Dinamikusan arrayal tárold a tanulókat. Majd kérd le a neveket és osztályzatot.
		amiután beírta az összest, rendezd osztályzat alapján. Majd írd ki a rendezett sorrendet.

*/
/*
#include <string>
#include <algorithm>

struct Tanulo
{
	std::string nev;
	int jegy;
};

int main()
{
	int tanulokSzama{ 0 };
	do
	{
		std::cout << "Hany nevet akarsz beirni? ";
		std::cin >> tanulokSzama;
	} while (tanulokSzama <= 1);

	Tanulo *tanulok = new Tanulo[tanulokSzama];

	for (int index = 0; index < tanulokSzama; ++index)
	{
		std::cout << "Ird be #" << index + 1 << " nevet: ";
		std::cin >> tanulok[index].nev;
		std::cout << "Ird be #" << index + 1 << " jegyet: ";
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
		std::cout << tanulok[index].nev << " jegye: " << tanulok[index].jegy << '\n';


	delete[] tanulok;

	return 0;
}*/

/*

Írj egy saját funkciót amelyben két változó értékét cseréled fel. Írj egy main funkciót amiben teszteled.

*/
/*
int csere(int &x, int &y)
{
	// csinálunk egy ideiglenes mentést az első számról
	int idg = x;

	// majd felcseréljük az első szám értékét a másodikkal.
	x = y;

	// majd belehelyezzük az ideiglenes értéket a második számba, ergó az első értéket a másodikba.
	y = idg;

	return x, y;
}

int main()
{
	int x = 5;
	int y = 7;

	csere(x, y);

	if (x == 7 && y == 5)
		std::cout << "A csere megtortent.\n";
	else
		std::cout << "Hiba, a csere nem sikerult.\n";

	return 0;
}*/

/*

Írj egy funkciót amelyben kiírsz egy C-STYLE stringet karakterekként.
	Használj egy mutatót amellyel végig lépdelsz a karaktereken és egyesével kiírod őket.
		Akkor álljon le amikor eléri a null terminátort(\0).
			Használj egy main funkciót amellyel teszteled, a teszt string: "Hello, world!".

*/
/*
void kiIrKarakterek(char *string, int stringHossz)
{
	for (int index = 0; index < stringHossz; ++index)
	{
		if (!(string[index] == '\0'))
		{
			std::cout << string[index] << ' ';
		}
		else
			break;
	}
}


int main()
{
	char string[] = { "Hello, world!" };
	int stringHossz = sizeof(string) / sizeof(string[0]);

	kiIrKarakterek(string, stringHossz);

	return 0;
}*/