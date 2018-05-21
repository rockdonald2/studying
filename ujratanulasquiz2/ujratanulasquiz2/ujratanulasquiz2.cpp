#include "stdafx.h"
#include <iostream>

/*

az első kérdés, miért jobb a symbolic constant mint egy literal constant?
	megoldás: a literal constant(magic number) nehezebbé teszi a programodat, hogy modosítsd, illetve, hogy megértsd.
			  a symbolic constant kontextust ad, mutatva mit fejez ki a szám, így könnyebb modosítani is.

az első kérdés b fele, miért jobb a const symbolic constant mint egy #defined symbolic constant?
	megoldás: #defined symbolic constants nem mutatódnak ki a debuggerben, így nehezebb debugolni, és gyakrabban alakul ki naming collision is.

a második feladat, válaszd ki a megfelelő fájl formátumot
	megoldás: a) int, b) bool, c)const double, d) int16_t, e) double, f) long long, g) char, h) int16_t

harmadik feladat, írj egy programot amiben: a felhasználó bekell írjon 2 floating point számot(double típus!),
				utána bekell írjon egy matematikai müveletet, utána a program elvégzi a matematikai számítást és kiírja az eredményt.

negyedik feladat, írj egy rövid programot amiben szimulálod egy labda ledobását egy toronyból
		1. lekéred a felhasználótól a kezdeti magasságot ( gravitáció = 9.8 m/s^2 , és nincs kezdeti gyorsulássa(v = 0) )
		2. a program kikell írja a labda helyzetét 0, 1, 2, 3, 4, 5 másodpercekben
		3. a labda nem szabad a föld alá menjen ( a magasság 0 )
		4. a programodnak tartalmaznia kell egy header file-t ami tartalmazza a konstant változóidat: namespace sajatKonstans
		5. használj egy funkciót, hoy kiszámold a magasságát a labdának x másodperc után 
				képlet: lezuhant távolság = gravitációs_állandó * x_másodperc^2 / 2

				hajrá!
*/

/*
double lekerSzam()
{
	std::cout << "Irj be egy szamot: ";
	double szam;
	std::cin >> szam;

	return szam;
}

char lekerMuvelet()
{
	std::cout << "Ird be valamelyik matematikai muveletet a kovetkezokbol: +, -, *, / : ";
	char muvelet;
	std::cin >> muvelet;

	return muvelet;
}

void kiIrEredmeny(char muvelet, double elsoSzam, double masodikSzam)
{
	if (muvelet == '+')
		std::cout << elsoSzam << " " << muvelet << " " << masodikSzam << " = " << elsoSzam + masodikSzam << '\n';
	else if (muvelet == '-')
		std::cout << elsoSzam << " " << muvelet << " " << masodikSzam << " = " << elsoSzam - masodikSzam << '\n';
	else if (muvelet == '*')
		std::cout << elsoSzam << " " << muvelet << " " << masodikSzam << " = " << elsoSzam * masodikSzam << '\n';
	else if (muvelet == '/')
		std::cout << elsoSzam << " " << muvelet << " " << masodikSzam << " = " << elsoSzam / masodikSzam << '\n';

	else
		std::cout << "ERROR: rossz muvelet, a program leall!\n";
 }

int main()
{
	double elsoSzam;
	elsoSzam = lekerSzam();

	double masodikSzam;
	masodikSzam = lekerSzam();

	char muvelet;
	muvelet = lekerMuvelet();

	kiIrEredmeny(muvelet, elsoSzam, masodikSzam);

	return 0;

}
*/

#include "konstansErtekek.h" // a gravitacios allando miatt


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

void kiIrEsKiszamolMagassag(double kezdetiMagassag, int masodperc)
{
	double magassag = szamolMagassag(kezdetiMagassag, masodperc);
	kiIrMagassag(magassag, masodperc);
}

int main()
{
	const double kezdetiMagassag = lekerKezdetiMagassag();


	kiIrEsKiszamolMagassag(kezdetiMagassag, 0);
	kiIrEsKiszamolMagassag(kezdetiMagassag, 1);
	kiIrEsKiszamolMagassag(kezdetiMagassag, 2);
	kiIrEsKiszamolMagassag(kezdetiMagassag, 3);
	kiIrEsKiszamolMagassag(kezdetiMagassag, 4);
	kiIrEsKiszamolMagassag(kezdetiMagassag, 5);

	return 0;

}


