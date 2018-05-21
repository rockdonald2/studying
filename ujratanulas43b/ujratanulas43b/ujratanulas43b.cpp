#include "stdafx.h"
#include <iostream>

/*

Namespaces,
	
	de először beszéljünk a naming conflictról,
		ez akkor lép fel ha két azonosító lép be ugyan abba a scope-ba és a compiler nem tudja elkülöníteni melyiket használja.

		ezért vezették be a namespace ötletét ami segít ilyen típusú problémákat orvosolni.


	a namespace meghatároz egy olyan kód zónát amelyben minden azonosító garantáltan egyedi.
		minden globális változó illetve, normális funckió alapból a global namespacebe tartozik.
		létrehozhatjuk a saját namespaceünket a namespace kulcsszóval, bármi meghatározva egy felhasználó által létrehozott namespaceben
			az adott namespace része, nem a global namespace-é.

		amikor megakarjuk mondani a compiler-nek, hogy melyik namespace-ben keresse az adott kódot, a scope resolution operatort(::) használjuk.
			ha nem írunk semmilyen namespace-t az operátor elé, akkor a global namespace-re gondolunk(::funkcio).
			
		használhatjuk többször ugyanazt a namespace nevet, más fájlban vagy ugyanabban, ez esetben ugyanúgy az adott namespace része lesz a kód.

		a namespace-ket egymásba lehet fészkelni, akárcsak a blokkokat.
			két féle képpen lehet:
				pl:
					namespace Foo										namespace Foo::Goo
					{														{
						namespace Goo											csinálj valamit
						{									vagy			}
							csinálj valamit
						}
					}

		továbbá, lehet namespace "becenevek"(alias)-t beállítani ha több összefészkelt namespaceünk van.
				pl.
					namespace Boo = Foo::Goo;


			!tanács, ha lehet óvakodj fészkelni a namespaceket.
*/