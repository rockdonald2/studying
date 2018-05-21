#include "stdafx.h"
#include <iostream>

/*

Tervezz egy játék részletet, amelyben szörnyek vannak. A következő szörnyeket kell tartalmazza: ogre, sárkány, ork, óriáspók, slime.
	(ehhez használj enum class-ot) Minden egyes szörnynek neve kell legyen(std::string), és egy meghatározott mennyiségű életerejük.
	Írj egy funkciót printMonster() néven amely kiírja az összes struct tag nevét. Majd main()-be írj egy példát egy ogréval, és egy
	slimemal, inicializáld őket initializer list-el, és használd a printMonster() funkciódban.

*/

#include <string>

// a felsorolás amely tartalmazza a szörnyek fajtáit.
enum class SzornyekTipusa
{
	OGRE,
	SARKANY,
	ORK,
	ORIASPOK,
	SLIME,
};

// a struct amely tartalmazza, hogy minden szörnynek kell legyen egy neve, illetve egy meghatározott életereje.
struct Szorny
{
	SzornyekTipusa szorny;
	std::string nev;
	int eletero;
};

// funkció amely kiírja a szörnyek nevét string-ben.
std::string kiIrSzornyekNeveString(Szorny szorny)
{
	if (szorny.szorny == SzornyekTipusa::OGRE)
		return "Ogre";
	if (szorny.szorny == SzornyekTipusa::SARKANY)
		return "Sarkany";
	if (szorny.szorny == SzornyekTipusa::ORK)
		return "Ork";
	if (szorny.szorny == SzornyekTipusa::ORIASPOK)
		return "Orias pok";
	if (szorny.szorny == SzornyekTipusa::SLIME)
		return "Slime";

	return
		"???";
}


void printMonster(Szorny szorny)
{
	std::cout << "Ennek a " << kiIrSzornyekNeveString(szorny) 
		<< "-nek a neve " << szorny.nev << " es van " 
		<< szorny.eletero << " eletereje.\n";
}

int main()
{
	Szorny ogre = { SzornyekTipusa::OGRE, "Torg", 145 };
	Szorny slime = { SzornyekTipusa::SLIME, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	return 0;
}