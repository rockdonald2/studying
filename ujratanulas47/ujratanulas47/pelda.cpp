#include "stdafx.h"
#include <iostream>

// Quiz

/*

K�pzeld el, hogy te futtatsz egy weboldalt, ahol rekl�mok jelennek meg, �rj egy programot amellyel sz�mot tartod mennyi p�nzt keresel ezzel.
	hozz l�tre egy hirdet�s struct-ot, amely sz�mon tartja, h�ny h�rdet�st mutatt�l az olvas�nak, a h�rdet�sek h�ny sz�zal�k�ra kattintottak
	r�, �s mennyit kerest�l �tlagban minden r�kattintott h�rdet�s ut�n.

		olvass be �rt�ket mindh�rom taghoz a felhaszn�l�t�l, foglald bele egy funkci�ba a hirdet�s struct-ot, amely k�rja mindh�rom �rt�ket,
		�s kisz�molja mennyit kerest�l ( �sszeszorzod mind a h�rmat )

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