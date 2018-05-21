#include "stdafx.h"
#include <iostream>


#include <string>


enum class SzornyTipus
{
	OGRE,
	SARKANY,
	ORK,
	POK,
	SLIME,
};

struct Szorny
{
	SzornyTipus tipus;
	std::string nev;
	int eletero;
};

std::string kiIrSzornyNeve(Szorny szorny)
{
	if (szorny.tipus == SzornyTipus::OGRE)
		return "Ogre";
	if (szorny.tipus == SzornyTipus::SARKANY)
		return "Sarkany";
	if (szorny.tipus == SzornyTipus::ORK)
		return "Ork";
	if (szorny.tipus == SzornyTipus::POK)
		return "Pok";
	if (szorny.tipus == SzornyTipus::SLIME)
		return "Slime";
	else
		return "???";
}

void kiIrSzorny(Szorny szorny)
{
	std::cout << "Ez egy " << kiIrSzornyNeve(szorny) << " , akinek a neve " << szorny.nev << " es van " << szorny.eletero << " eletereje.\n";
}

int main()
{
	Szorny ogre = { SzornyTipus::OGRE, "Torg", 145 };
	Szorny slime = { SzornyTipus::SLIME, "Blurp", 23 };

	kiIrSzorny(ogre);
	kiIrSzorny(slime);

	return 0;
}