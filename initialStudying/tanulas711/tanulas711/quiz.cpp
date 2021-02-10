#include "stdafx.h"
#include <iostream>

// 1
/*
Egy N számnak a faktoriálisa(N!) az összes szám szorzata 1-től a N számíg(0! = 1).
	Írj egy rekurzív funkciót ennek értelmében. Teszteld az első 7 faktoriálissal.
*/
/*
int faktorialis(int szam)
{
	if (szam == 0)
		return 1;
	if (szam == 1)
		return 1;
	else
		return faktorialis(szam - 1) * szam;
}

int main()
{
	std::cout << "faktorialis " << faktorialis(5);

	return 0;
}*/


// 2
/*
Írj egy rekurzív funkciót amely vesszi egy integer input számait, és különszedve őket összeadja.
(pl. 357 = 3 + 5 + 7). Teszteld 93427-el aminek 25 a számjegyeinek összege.
*/
/*
int szamjegyekOsszege(int szam)
{
	if (szam == 0)
		return 0;
	if (szam == 1)
		return 0;
	else
		return szamjegyekOsszege(szam / 10) + szam % 10;
}

int main()
{
	std::cout << szamjegyekOsszege(357);

	return 0;
}*/

// 3
/*
Írj egy rekurzív funkciót ami az int inputot átalakítja binárissá.
*/
/*
void atalakitBinaris(int szam)
{
	if (szam == 0)
		return;

	atalakitBinaris(szam / 2);

	std::cout << szam % 2;
}

int main()
{
	int szam;
	std::cout << "Irj be egy szamot:";
	std::cin >> szam;

	atalakitBinaris(szam);

	return 0;
}*/