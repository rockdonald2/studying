#include "stdafx.h"
#include <iostream>

/*

határozz meg egy array-t ami magas hőmérsékleteket raktároz az év minden napjára.
	egy tizedesnyi pontossággal, majd rendeld hozzá a 0.0-t minden egyes naphoz.

*/

/*

hozz létre egy enumot a következő állatokkal: csirke, kutya, macska, elefánt, kacsa, és kigyó.
	rakd az enum-ot egy namespace-be. 
		határozz meg egy array-t egy elemmel minden állathoz, és használj egy initializer listát,
			hogy inicializáld minden elemet, hogy raktározza hány lába van az állatnak.

	használd a main funkciót, hogy kiírd hány lába van az elefántnak, a felsorolással.

*/

namespace AllatNevek
{
	enum Allat
	{
		CSIRKE,
		KUTYA,
		MACSKA,
		ELEFANT,
		KACSA,
		KIGYO,
		ALLATOK_SZAMA, // ez fogja bebiztosítani a helyes hosszát az array-nek, mivel egy array hossza nagyobb kell legyen mint az utolsó index száma 1-el.
	};
}

#include <string>

std::string visszaAdAllatNeveString(AllatNevek::Allat allat)
{
	switch(allat)
	{
	case AllatNevek::CSIRKE:
		return "csirke";
	case AllatNevek::KUTYA:
		return "kutya";
	case AllatNevek::MACSKA:
		return "macska";
	case AllatNevek::ELEFANT:
		return "elefant";
	case AllatNevek::KACSA:
		return "kacsa";
	case AllatNevek::KIGYO:
		return "kigyo";
	default:
		return "???";
	}
}

int main()
{
	double homerseklet[365] = { 0.0 };
	std::cout << "Az ev 66-ik napjan a homerseklet " << homerseklet[65] << " volt.\n";

	int labokSzama[AllatNevek::ALLATOK_SZAMA] = { 2, 4, 4, 4, 2, 0 };

	std::cout << "Egy " << visszaAdAllatNeveString(AllatNevek::CSIRKE) << "-nak/-nek van " << labokSzama[AllatNevek::CSIRKE] << " laba.\n";

	return 0;
}