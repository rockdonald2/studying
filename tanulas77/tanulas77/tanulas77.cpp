#include "stdafx.h"
#include <iostream>

/*

Default parameters,
	egy alapértelmezett paraméter egy olyan funkció paraméter amelynek egy alapértelmezett értéket adunk meg.
		ha ehhez a paraméterhez a felhasználó nem társít egy új felhasználó által szolgálatott értéket akkor
			az alapértelmezett érték fog felhasználodni. Ha szolgáltat akkor a felhasználó által megadott érték.

			lásd pl.


	egy funkciónak akár több alapértelmezett paramétere is lehet.

	! fontos, nem lehet például a harmadik paraméternek értéket szolgáltatni ha az első kettőhöz nem szolgáltatunk.
		ez amiatt van, hogy nem támogatott a C++-ban a következő séma: printErtek(,,3);

		azaz:
			! az alapértelmezett paraméter mindig a legjobboldalibb paraméter kell legyen.
			! ha több alapértelmezett paraméter létezik akkor a legbaloldalibb alapértelmezett paraméter kellene legyen az
				amit leginkább valószinűbb, hogy kifejezetten meghatároz a felhasználó.

	! minden alapértelmezett paraméter csakis egyszer lehet meghatározva.

	az alapértelmezett paraméter akár meglehet határozni a forward declarationbe, vagy akár a function definitionben.
		az elsőnek nincs function body-ja, a másiknak van.
			a legjobb ha a forward declarationbe határozzuk meg.

	akár alapértelmezett paraméterrel rendelkező funkciókat is lehet overloadolni, de fontos, az alapértelmezett
		paraméter nem számít olyan paraméternek ami a funkciót egyedivé teszi.
*/


