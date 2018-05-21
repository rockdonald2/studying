#include "stdafx.h"
#include <iostream>

/*

írj egy funkciót calculate() néven, ami fog két integert, és egy char-t ami egy matematikai müveletet tartalmaz
	használj egy switch állítást, hogy végrehajtsd a megfelelő matematikai müveletet a számokon, és visszaad az eredményt.

	ha egy értelmetlen operátort használtak a funkcióban, a funkciónak egy errort kell írnia
		osztás esetében integer osztást használj, azaz a tört rész elmarad, de nem kerekítődik.

*/


int calculate(int x, int y, char op)
{
	switch (op)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '%':
		return x % y;
	default:
		std::cout << "ERROR: ertelmetlen operator" << "\n";
		return 0;
	}
}

int lekerSzam()
{
	std::cout << "Irj be egy egesz szamot: ";
	int x;
	std::cin >> x;

	return x;
}

char lekerOperator()
{
	std::cout << "Ird be valamelyik matematikai operatort: +, -, *, /, %: ";
	char op;
	std::cin >> op;

	return op;
}

int _main()
{
	int szam1 = lekerSzam();
	int szam2 = lekerSzam();
	char op = lekerOperator();

	std::cout << "Az eredmeny = " << calculate(szam1, szam2, op) << "\n";

	return 0;
}