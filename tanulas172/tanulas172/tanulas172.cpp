#include "pch.h"
#include <iostream>

/*

String construction,
	a string classnak rengeteg konstruktőrje van amelyet stringek létrehozására lehet használni
		lásd pl.

		! fontos megjegyezni, hogy a string::size_type size_t-t jelent amely ugyanaz az unsigned int típus
			mint amit a sizeof operátor ad vissza
			- a tényleges mérete a környezettől függ

Constructing strings from numbers,
	egy megjegyezhető hiányossága az std::string-nek az, hogy nem vagyunk képesek stringet létrehozni számokból
	- a probléma az, hogy nem tud számot átalakítani basic_string-é
	- ahhoz, hogy ezt megold és átalakít számot stringgé, az az, hogy behozod az std::ostringstream classot
	az std::ostreamstring képes arra, hogy elfogadja inputot számtalan forrásból: char, számok, string, stb.
	képes arra, hogy outputolja ezeket a stringeket (vagy az operátor>>-al vagy az str() funkcióval)
		lásd pl.
		! az a megoldás kikerüli az error checket, így lehetséges, hogy a tX beillesztése az oStream-be sikertelen,
			egy megfelelő válasz esetén exceptiont dobna, ha a beillesztés sikertelen.

Converting strings to numbers,
	hasonló megoldás mint a fenti.

*/