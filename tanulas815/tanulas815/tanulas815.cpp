#include "stdafx.h"
#include <iostream>

/*

Nesting types,
	nem úgy mint a funkciók amiket nem lehet egymásba fészkelni, különböző típusok belefészkelhetők a classokba.
	ahhoz, hogy ezt tedd simán meghatározod a típust a classon belül, valamelyik megfelelő hozzáférési pontosító alatt.

		! fontos megjegyezni, hogy ilyen esetekben a class namespaceként funkciónál, lásd amikor elérjük a main() elején.

Other types can be nested too,
	habár, az enumok a leggyakoribb befészkelt típusok egy classon belül, más típusokat is belehet fészkelni, olyant mint pl.
		a typedef, type alias, más class, stb.

	mint bármely normál tagja a classnak, egy befészkelt class úgyan olyan hozzáféréssel rendelkezik a körülzáró class tagjaihoz
		mint a körülzáró class. úgyanakkor, egy befészkelt class nincs semmilyen különleges hozzáférése a "this" mutatóhoz.

*/