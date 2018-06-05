#include "stdafx.h"
#include <iostream>

/*

Paraméterek vs. érvek,
	Az általános használatban ezt a két fogalmat gyakran felcserélik. Úgyanakkor, nekünk meg kell különböztetnünk őket.

		Egy funkció paraméter, az egy változó amelyet meghatározunk a funkció meghatározásban.

		Egy érv, az egy érték amit továbbadunk a funkciónak.

		Amikor lehívnak egy funkciót, minden egyes paraméter úgy jön létre mint egy változó, és az érvek értéke belemásolódik a paraméterbe.
			Hiába nem jönnek létre a paraméterek funkció blokkon belül, úgyanúgy helyi scopepal rendelkeznek, amit azt jelenti, hogy
				létrejönnek amikor a funkcióra hivatkoznak, és megsemmisül amikor a blokk véget ér.

		Három alapvető metódus van arra, hogy érveket adjunk tovább egy funkciónak: értek alapján, hivatkozás alapján, cím alapján.

*/


void foo(int x); // funkció bejelentés(function prototype) -- melyben az x egy paraméter.

void foo(int x) // funkció meghatározás (ami egyben bejelentés is) -- melyben az x egy paraméter.
{
	// ..
}

void funkcio()
{
	int y{ 0 };
	foo(6); // a 6 egy érv, amit továbbadunk az x paraméternek.
	foo(y + 1); // az y + 1 kifejezés értéke egy érv amit továbbadunk az x paraméternek.
}