#include "stdafx.h"
#include <iostream>

/*

Érték általi továbbadás,
	Alapértelmezettként, minden nem-mutató érv a C++-ban érték által van továbbadva.
		Amikor egy érvet érték által adunk tovább, az érv értéke belemásolódik a megfelelő paraméterbe.

	! Mivel, az érvnek csak egy másolata van a funkciónak továbbadva, így az eredeti érvet nem tudja modosítani a funkció.

	A funkció paraméterek akár lehetnek konstans értékek is, így megelőzve, hogy megváltoztassa az értékét.

*/


/*

Előnyei és hátrányai:
	- Előnyök:
		Az érv amit érték szerint továbbadunk a funkciónak bármilyen típusból lehet(változó, szám, kifejezés, struct, class, enum).
		A továbbadott érvet nem tudja megváltoztatni a funkció amit lehívunk, megelőzve a mellékhatásokat.

	- Hátrányok:
		Struct és class másolása hatalmas teljesítmény büntetéssel járhat, főleg ha az adott funkciót sokszor hívják le.

	Mikor használjuk az érték általi továbbadást?
		Amikor alapvető adattípusokat adunk tovább, illetve enumokat, továbbá a funkciónak nem kell modosítania az érvet.

	Mikor ne használjuk?
		Amikor továbbadunk arrayt, structot, classot.

*/