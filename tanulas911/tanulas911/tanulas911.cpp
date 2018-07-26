#include "stdafx.h"
#include <iostream>

/*

A inicializálási típusok átismétlése,
	a C++ három féle inicializálási módszert támogat: direct, uniform vagy copy inicializálás.
		lásd pl.

*/


/*

Copy constructor,
	a copy konstruktőr egy olyan konstruktőr amelyet arra használunk, hogy egy új objectet hozzunk létre amely egy
		meglévő másolata.

		úgyanúgy mint egy alapértelmezett konstruktőr esetében, ha nem szolgáltatunk mi egy copy konstruktőrt
			a compiler saját maga hoz egyet létre, ami a memberwise initializationt használja, ami azt jelenti,
			hogy minden egyes tag értéke közvetlenül inicializálódik annak a classnak a tagjaival amelyet másolunk.

			lásd pl.


Preventing copies,
	megelőzhetjük a másolatok létrejöttét azzal, hogy a copy konstruktőrt priváttá tesszük.

	valamint ki is lehet hagyni a copy konstruktőrt az inicializálásból
		pl. Fraction fiveThirds(Fraction(5,3));
			- amely így direkt módon lesz inicializálva.
				- ez a folyamatot hívjuk kihagyásnak(elision).

*/