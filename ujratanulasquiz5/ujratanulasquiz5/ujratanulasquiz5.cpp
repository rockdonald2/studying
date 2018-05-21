#include "stdafx.h"
#include <iostream>

#include "konstansErtekek.h" // a gravitacios allando miatt


/*

Módosítsd úgy a quiz2-ben levő programot, hogy a labda pont annyi ideig esik a toronyból, ameddig leér a földre.

*/

/*
// ez a funkcio lekeri a kezdeti magassagot, eleg egyertelmu
int lekerKezdetiMagassag()
{
	std::cout << "Ird be a torony kezdeti magassagat meterben: ";
	int kezdetiMagassag;
	std::cin >> kezdetiMagassag;

	return kezdetiMagassag;
}

double szamolMagassag(int kezdetiMagassag, int masodperc)
{
	// itt jon kepbe a formula
	double lezuhantMagassag;
	lezuhantMagassag = (sajatKonstans::gravitacio * masodperc * masodperc) / 2;
	double jelenlegiMagassag;
	jelenlegiMagassag = kezdetiMagassag - lezuhantMagassag;

	return jelenlegiMagassag;
}

void kiIrMagassag(double magassag, int masodperc)
{
	if (magassag > 0.0)
		std::cout << "A labda " << masodperc << " masodpercben " << magassag << " meteren van." << '\n';
	else
		std::cout << "A labda a foldon van." << '\n';
}

void kiIrEsKiszamolMagassag(double kezdetiMagassag)
{
	double megvaltozottMagassag = kezdetiMagassag;

	for (int szuksegesMasodperc = 0; megvaltozottMagassag > 0; ++szuksegesMasodperc)
	{
		double magassag = szamolMagassag(kezdetiMagassag, szuksegesMasodperc);

		megvaltozottMagassag = magassag;

		kiIrMagassag(magassag, szuksegesMasodperc);
	}
}

int main()
{
	const double kezdetiMagassag = lekerKezdetiMagassag();


	kiIrEsKiszamolMagassag(kezdetiMagassag);

	return 0;

}

*/


/*

Csinálj egy hi-lo játékot, amiben a programod először kiválaszt egy random integert 1-től 100-ig.
A felhasználónak van 7 próbálkozása, hogy eltalálja a számot.

	Ha a felhasználó épp nem találja el a számot, a program írja ki, hogy a tipp túl nagy, vagy túl kicsi.
		Ha pont eltalálta, írja ki, hogy győzött.
	Amikor ellőtte a próbálkozásait a program írja ki ,hogy játék vége, majd a számot.
	A játék végén kínáljon fel lehetőséget, hogy újrapróbálja egy új számmal.
		'y' és 'n'

*/


/*

program részei: 1. kiválasztani a random számot 1-től 100-ig
				2. összehasonlítani a felhasználó számát a kiválasztott számmal
				3. játékújrakezdés

*/

#include <cstdlib> // a rand-hoz és srand()-hoz
#include <ctime> // a time()-hoz

// kivalaszt egy szamot egy min és egy max érték között
// a játék esetében kiválasztja azt a számot amit a felhasználónak el kell találni.
int randomSzam(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

// tesztfunkció
void teszt()
{
	std::cout << randomSzam(1, 100);
}

int felhasznaloTipp()
{
	while (true)
	{

	int tipp;
	std::cin >> tipp;

	if (std::cin.fail())
		{
		std::cin.clear();
		std::cin.ignore(32768, '\n');
		std::cout << "ERROR! Ervenytelen karakterek.\n" <<
			"Probald ujra: ";
		}
	else
		{
		std::cin.ignore(32768, '\n');
		return tipp;
		}

	}
}

// a jatek hi-lo része, itt tippel a felhasználó a kivalasztottSzamra.
bool jatek(int kivalasztottSzam, int probalkozas)
{
	for (int szamlalo = 1; szamlalo <= probalkozas; ++szamlalo)
	{
		std::cout << "Probalkozas #" << szamlalo << ": ";
		int tipp = felhasznaloTipp();

		if (tipp > kivalasztottSzam)
			std::cout << "A probalkozasod tul nagy.\n";
		else if (tipp < kivalasztottSzam)
			std::cout << "A probalkozasod tul kicsi.\n";
		else
			return true;
	}

	return false;
}

// tesztfunckió
void teszt2()
{
	int kivalasztottSzam = randomSzam(1, 100);
	int probalkozas = 7;
	jatek(kivalasztottSzam, probalkozas);
}

bool jatekUjrakezdes()
{
	char bill;

	do
	{
		std::cout << "Szeretned ujrakezdeni a jatekot (i/n)?";
		std::cin >> bill;
	} while (bill != 'i' && bill != 'n');

	return (bill == 'i');
}

int main()
{
	srand(static_cast<int>(time(0))); // kezdeti seed a rendszer órájához állítva
	rand(); // első lekérés, discard.

	constexpr int probalkozas = 7;

	std::cout << "Jatszunk egy jatekot. Gondolok egy szamra 1 es 100 kozott. Van " << probalkozas << " probalkozasod eltalalni azt.\n";

	do
	{
		int kivalasztottSzam = randomSzam(1, 100);
		bool nyert = jatek(kivalasztottSzam, probalkozas);

		if (nyert)
			std::cout << "Gyoztel! Eltalaltad a szamot amire gondoltam.\n";
		else
			std::cout << "Veszitettel! A helyes szam a " << kivalasztottSzam << " volt.\n";
	} while (jatekUjrakezdes());

	std::cout << "Kosz a jatekot!\n";
	

	return 0;
}