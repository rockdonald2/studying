#include "stdafx.h"
#include <iostream>

/*

Anonymous objects,
	egy névtelen object lényegében egy olyan érték amelynek nincs neve.
		mivel nincsen nevük, így nincs mód arra, hogy rájuk hivatkozunk azután miután létrejöttek.
			- expression scopejuk vannak, azaz az adott kifejezésen belül létrejönnek, kiértékelődnek, és megsemmisülnek.

			lásd pl.

*/


/*

Anonymous class objects,
	lehetséges anonymous objectet létrehozni a saját class típusunkból is, ezt úgy hozzuk létre mint a normális objecteket,
		de kihagyjuk a változó nevét.

*/


/*

Összegzés,
	általában arra használjuk, hogy vagy továbbadjanak, vagy returnoljanak értékeket anélkül, hogy sok ideiglenes változót
		kellene létrehozni ehhez. A dinamikus memória allokáció is így mükődik.

	! fontos megjegyezni, ezek rértékekek(azaz nincs memória címük), azaz csak konstans hivatkozás, vagy érték alapján lehet
		returnolni.

*/