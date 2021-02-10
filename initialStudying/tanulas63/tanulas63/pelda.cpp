#include "stdafx.h"
#include <iostream>

using namespace std;

/*

írd ki a következő arrayt: int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 }; egy loopal.

*/

/*

Adott az array az első feladatból. 
	Kérd a felhasználót, hogy írjon be egy számot 1-től 9-ig. Ha nem megfelelőt ír be újra és újra kérd.
		Amint beírta a megfelelő számot 1 és 9 között, írd ki az arrayt.
			Majd keresse meg az arrayben a számot amit beírt és írja ki az indexét.

*/

/*int main()
{
	int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	const int elemekSzama = sizeof(array) / sizeof(array[0]);
	
	for (int szamlalo = 0; szamlalo < elemekSzama; ++szamlalo)
	{
		cout << array[szamlalo] << ' ';
	}

	cout << "\n";

	return 0;
}*/

/*int lekerSzam()
{
	int szam;
	do
	{
		cout << "Irj be egy szamot 1 es 9 kozott: ";
		cin >> szam;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32768, '\n');
		}
	} while (szam != 1 && szam != 2 && szam != 3 && szam != 4 && szam != 5 && szam != 6 && szam != 7 && szam != 8 && szam != 9);

	cin.ignore(32768, '\n');
	return szam;
}

bool leellenorizSzam(int szam)
{
	if (szam == 1 || szam == 2 || szam == 3 || szam == 4 || szam == 5 || szam == 6 || szam == 7 || szam == 8 || szam == 9)
		return true;
	else
		return false;
}

void teszt()
{
	int szam = lekerSzam();
	std::cout << szam << "\n";
}

int main()
{
	int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };

	const int elemekSzama = sizeof(array) / sizeof(array[0]);

	int szam = lekerSzam();
	bool vSzam = leellenorizSzam(szam);

	

	if (vSzam)
	{
		for (int szamlalo = 0; szamlalo < elemekSzama; ++szamlalo)
		{
			cout << array[szamlalo] << ' ';
		}

		std::cout << "\n";

		for (int szamlalo = 0; szamlalo < elemekSzama; ++szamlalo)
		{
			if (array[szamlalo] == szam)
			{
				std::cout << "Beirt szam " << szam << " indexe a " << szamlalo << "\n";
				break;
			}
		}
		
	}

	
		
	
	return 0;
}*/

/*

Modosítsd a programot ami ahelyett, hogy a maxScore tárolja a legmagasabb pontszámot, inkább egy maxIndex nevü változó tárolja
a legmagasabb pontszám indexét.

*/

/*int main()
{
	int scores[] = { 84, 92, 76, 81, 56 };
	const int numStudents = sizeof(scores) / sizeof(scores[0]);

	int maxScore = 0; // keep track of our largest score
	int maxScoreIndex = 0;

					  // now look for a larger score
	for (int student = 0; student < numStudents; ++student)
		if (scores[student] > maxScore)
		{
			maxScore = scores[student];
			maxScoreIndex = student;
		}

	std::cout << "The best score was " << maxScore << " and its index is " << maxScoreIndex << '\n';

	return 0;
}*/