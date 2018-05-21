#include "stdafx.h"
#include <iostream>

double lekerSzam()
{
	// végtelen loop, addig amíg a felhasználó érvényes inputot nem ad.
	while (true)
	{
		// alap megoldás arra, hogy inputot kérjünk a felhasználótól.
		std::cout << "Irj be egy szamot: ";
		double szam;
		std::cin >> szam;

		// leellenőrzi ha a extraction sikertelen
		if (std::cin.fail()) 
		{
			std::cin.clear(); // vissza rak normal mode-ba
			std::cin.ignore(32768, '\n'); // kitörli a plusz karaktereket
			std::cout << "Input ervenytelen, probald ujra.\n";
		}
		else
		{
			std::cin.ignore(32768, '\n'); // kitörli a plusz karaktereket
			return szam; // returnolja a helyes értéket.
		}
	}
}

char lekerOperator()
{
	while (true)
	{
		std::cout << "Ird be valamelyik matematikai muveletet: +, -, *, /: ";
		char op;
		std::cin >> op;

		// char-ok csak egy input értéket vesznek be, értelmetlen sikertelen extraction-nek a tesztelése.

		std::cin.ignore(32768, '\n'); // kitöröl minden plusz karaktert

		if (op == '+' || op == '-' || op == '*' || op == '/')
			return op;
		else
			std::cout << "Ervenytelen muvelet, probald ujra.\n";
	}
}

void kiIrEredmeny(double szam1, char op, double szam2)
{
	if (op == '+')
		std::cout << szam1 + szam2 << "\n";
	else if (op == '-')
		std::cout << szam1 - szam2 << "\n";
	else if (op == '*')
		std::cout << szam1 * szam2 << "\n";
	else if (op == '/')
		std::cout << szam1 / szam2 << "\n";

	else
		std::cout << "Ervenytelen input, probald ujra.";
}

int main()
{
	double szam1 = lekerSzam();
	double szam2 = lekerSzam();
	char op = lekerOperator();

	kiIrEredmeny(szam1, op, szam2);

	return 0;
}