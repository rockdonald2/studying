#include "pch.h"
#include <iostream>

/*

Amikor létrehozol egy template funkciót, minden egyes példázott típus esetében úgyanazt a kartont fogja használni
	a compiler, csak úgye különböző típusokkal.
	- általában mi ezt akarjuk, de vannak esetek amikor a template funkciót kissé máshogyan akarjuk beépíteni
		egy adott adattípusra nézve

	- erre való a template specialization(specializálódás)


a példában szereplő Storage class esetében, például ha azt szeretnénk, hogy csak a Double értékek tudományos jelöléssel
	legyenek írva, az outputnál.

	- ez ebben az esetben elég egyszerű, simán létrehozol egy specializált változatot a print() funkcióból,
		mivel tag funkció, a classon kivül: ahhoz, hogy létrehozz egy ilyent, a template type-ot az adott típussal
			cseréled fel amihez átdefiniálnád.

	- ez esetben a compiler látja, hogy mi kifejezetten meghatároztuk a Double típusra a saját print() funkcióját,
		és ezt fogja használni az általános helyett
		template<> elárulja, hogy nincsen template type mert meghatároztunk minden típust.

*/