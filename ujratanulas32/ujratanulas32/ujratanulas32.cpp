#include "stdafx.h"
#include <iostream>

/*

számtani operátorok:
	unáris operátorok ( +, -)
			csak egyetlen operándussal dolgoznak, pl: -5;

	bináris operátorok ( +, -, *, /, %)
			használnak egy bal és egy jobb operándust, pl: 3 + 5 
				az összeadás, kivonás, szorzás úgy mükődik mint a normális matematikában, kifogás nélkül.
					az osztás, a modulusz(%), a modulusz másképp maradék, kicsit máshogy mükődik.

			! ha az osztás mindkét operándusa egész szám, egész számú osztás mükődik,
										ha tizedes szám jön ki, a tizedes rész eltünik, eldobódik, de nem kerekít!

			! ha az osztás mindkét operándusa floating point érték, akkor floating point értéket is fog visszaadni, tizedes számokkal.


				használhatunk static_cast<> parancsot, arra, hogy floating point osztás végezzünk egész számokkal.

			! a maradék operator csak egész operándusokkal mükődik, ez visszaadja a maradékot egész osztás után.
					pl. 7 % 4 = 3;

					nagyon hasznos, hogy megnézzük osztható-e egy szám a másikkal.
						ha x % y == 0, akkor tudjuk, hogy az x maradék nélkül osztható az y-al.

számtani kijelölési operátorok:
	pl. x = x + 5 átírható x += 5
		x = x * 2 átírható x *= 2

*/