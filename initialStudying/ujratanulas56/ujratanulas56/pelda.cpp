#include "stdafx.h"
#include <iostream>


/*

írj egy programot amelyben a felhasználótól lekérsz 2 számot, majd egy menüt megjelenítve lekéred a megfelelő müveletet, és elvégzed azt.

*/

// lekér egy double értéket a felhasználótól, az if állítás a failure mode-ot küszöböli ki, ez akkor történik ha karaktert írok be.
double lekerSzam() // 2 tesztelés
{
	while (true)
	{
		std::cout << "Irj be egy szamot: ";
		double szam;
		std::cin >> szam;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32768, '\n');
			std::cout << "Ervenytelen, probald ujra.\n";
		}

		else
		{
			std::cin.ignore(32768, '\n');
		return szam;
		}
	}


}

// első menü, itt adod le hány számmal akarsz dolgozni.
int menu1() // 3 tesztelés
{
	int szamokSzama;

	do
	{
		std::cout << "Hany szamot akarsz felhasznalni: \n"
			<< "1) 1\n"
			<< "2) 2\n"
			<< "3) 3\n"
			<< "4) 4\n";
		std::cin >> szamokSzama;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32768, '\n');

			std::cout << "Ervenytelen, probald ujra.\n";

			continue;
		}
	}

	while (szamokSzama != 1 && szamokSzama != 2 && szamokSzama != 3 && szamokSzama != 4);

	std::cin.ignore(32768, '\n');
	return szamokSzama;

}

// második menü, megadod az elvégezendő müveletet
int menu2() // 3 tesztelés
{
	int op;

	do
	{
		std::cout << "Valassz ki egy muveletet: \n"
			<< "1) osszeadas\n"
			<< "2) kivonas\n"
			<< "3) szorzas\n"
			<< "4) osztas\n";
		std::cin >> op;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32768, '\n');

			std::cout << "Ervenytelen, probald ujra.\n";

			continue;
		}
	}

	while (op != 1 && op != 2 && op != 3 && op != 4);

	std::cin.ignore(32768, '\n');
	return op;

}

// a második menü alapján ami 1,2,3,4-t add vissza, kiválasztja a szám alapján a megfelelő karaktert char-ként.
char opKivalasztas(int op) // 5 tesztelés
{
	switch (op)
	{
	case 1:
		return '+';
	case 2:
		return '-';
	case 3:
		return '*';
	case 4:
		return '/';

	default:
		std::cout << "ERROR";
		return '?';
	}
}

int main()
{
ujra: // goto label, az újrafuttatáshoz
	int szamokSzama = menu1();
	int szamlalo = 1;

	double szam1 = 0;
	double szam2 = 0;
	double szam3 = 0;
	double szam4 = 0;

	// egy loop ami a számokSzama() funkció alapján annyiszor ismétlődik meg ahányszor kell.
	while (szamlalo <= szamokSzama) // 4 tesztelés
	{
		szam1 = lekerSzam();
		++szamlalo;
		while (szamlalo <= szamokSzama)
		{
			szam2 = lekerSzam();
			++szamlalo;
			while (szamlalo <= szamokSzama)
			{
				szam3 = lekerSzam();
				++szamlalo;
				while (szamlalo <= szamokSzama)
				{
					szam4 = lekerSzam();
					++szamlalo;
				}
			}
		}
	}
	
	int op = menu2();
	char opK = opKivalasztas(op);

	// ez végzi el a müveleteket,
	switch (opK) // 10 tesztelés
	{
	case '+':
		std::cout << szam1 + szam2 + szam3 + szam4 << "\n";
		break;
	case '-':
		std::cout << szam1 - szam2 - szam3 - szam4 << "\n";
		break;
	case '*':
	{
		if (szam2 == 0)
			std::cout << szam1;
		else if (szam3 == 0)
			std::cout << szam1 * szam2;
		else if (szam4 == 0)
			std::cout << szam1 * szam2 * szam3;
		else
			std::cout << szam1 * szam2 * szam3 * szam4;
		break;
	}
	case '/':
	{
		if (szam2 == 0)
			std::cout << szam1;
		if (szam3 == 0)
			std::cout << szam1 / szam2;
		if (szam4 == 0)
			std::cout << szam1 / szam2 / szam3;
		else
			std::cout << szam1 / szam2 / szam3 / szam4;
		break;
	}

	default:
		std::cout << "???";
		break;
	}

	std::cout << "\n";

	// egy rövid kód ami újrafuttatja a programot, és használ goto állítást.
	std::cout << "Ujra akarod kezdeni: 1 - igen, barmi mas - nem: ";
	int valasztas;
	std::cin >> valasztas;
	std::cin.ignore(32767, '\n');

	if (valasztas == 1) // 2 tesztelés
	{
		std::cout << "\n";
		goto ujra;
	}
	else
		return 0;
}


/*

hány tesztelést igényelne ez a kód kb.: 29 tesztelés

*/