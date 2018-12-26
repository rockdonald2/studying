#include "pch.h"
#include <iostream>

/*

Esetenként olyan szituációkba is belefuthatsz amikor el akarsz kapni egy kivételt, de nem akarod(vagy nem tudod)
	abban a pillanatban teljesen kezelni amikor elkaptad. 
	Ez gyakori abban az esetben amikor logolni akarod a problémát, de átakarod adni a hívónak a problémát,
		hogy tényleges ő kezelje.

		- lényegében azt jelenti, hogy a catch blokkból egy újabb kivételt dobunk, ami nem feltétlen azonos típusú
			a catch által megfogott kivétellel, így elérve, hogy felfele terjedjen a stacken a hívóhoz

*/

/*

Rethrowing an exception(the wrong way)
	egyik megoldás, hogy dobjuk ugyanazt a kivételt, egyik módszer erre a direkt dobás, de ez esetben
		nem ugyanaz a kivétel lesz dobva mint amit elkaptunk hanem a copy-inicializált másolata az adott kivétel 
			változónak.
		- ez például származtatott class esetében slicinghoz vezethet, azaz a derived objectból base lesz.
			lásd pl.
*/

/*

Rethrowing an exception(the right way)
	szerencsére, a C++ biztosít egy módot arra, hogy úgyanazt a kivételt dobjuk tovább,
		használjuk a throw parancsot, de változó asszociálás nélkül.
			lásd pl
			- ez esetben pontosan ugyanaz a kivétel lesz továbbdobva, nincs másolatkészítés, nincs slicing,
				sem teljesítményvesztés

			! szabály, ha kivételt továbbdobsz, használd a throw kulcsszót önmagába
*/