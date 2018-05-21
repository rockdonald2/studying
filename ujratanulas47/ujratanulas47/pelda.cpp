#include "stdafx.h"
#include <iostream>

// Quiz

/*

Képzeld el, hogy te futtatsz egy weboldalt, ahol reklámok jelennek meg, írj egy programot amellyel számot tartod mennyi pénzt keresel ezzel.
	hozz létre egy hirdetés struct-ot, amely számon tartja, hány hírdetést mutattál az olvasónak, a hírdetések hány százalékára kattintottak
	rá, és mennyit kerestél átlagban minden rákattintott hírdetés után.

		olvass be értéket mindhárom taghoz a felhasználótól, foglald bele egy funkcióba a hirdetés struct-ot, amely kírja mindhárom értéket,
		és kiszámolja mennyit kerestél ( összeszorzod mind a hármat )

*/


struct Hirdetes
{
	int hirdetesSzama;
	double rakattintottSzazalek;
	double atlagKereset;
};

void kiirErtek(Hirdetes weboldal)
{
	std::cout << "Hany hirdetest mutatott a weboldal: " << weboldal.hirdetesSzama << "\n";

	std::cout << "Hany szazalekara kattintottal ra: " << weboldal.rakattintottSzazalek << "\n";

	std::cout << "Mennyit kerestel atlagban a hirdetesekkel amelyekre rakattintottak: " << weboldal.atlagKereset << "\n";
}

int main()
{
	Hirdetes weboldal;

	int x;
	std::cout << "Hany hirdetest mutatott az oldalad: ";
	std::cin >> x;
	weboldal.hirdetesSzama = x;

	double y;
	std::cout << "Hany szazalekara kattintottak ra: ";
	std::cin >> y;
	weboldal.rakattintottSzazalek = y;

	int z;
	std::cout << "Mennyit kerestel atlagban ezzel: ";
	std::cin >> z;
	weboldal.atlagKereset = z;

	kiirErtek(weboldal);

	std::cout << "Napi kereseted a hirdetesekbol egyenlo " << static_cast<double>(x) * (y / 100) * z << " \n";



	return 0;
}