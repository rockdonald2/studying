#include "stdafx.h"
#include <iostream>

/*

Overloading the parenthesis operator,
	ez egy nagyon érdekes operátort, mert teret enged, hogy meghatározzuk nemcsak a paraméterek típusát, hanem a számát is.
	- fontos megjegyezni tag funkciókként overloadoljuk és a non-object orientált programozásban az operátort() a funkció hívás
		operátora.


	ez például multi-dimenzionális arrayoknál jön képbe, ahol a normál operátor[] overloadja nem elegendő és az operátort()
		egyik módosított fajtáját kell használjuk.

			lásd pl.

	ez egy nagyon flexibilis operátor de rengeteg problémát szül.
		- rengeteg esetben, mint pl. itt is, nem tudjuk kitalálni, hogy ez az operátor() különben mit is csinál?
			anélkül, hogy látnánk a meghatározását.

	! vagy akár használhatjuk ezt az operátort mint functors, azaz olyan classokhoz amelyek úgy mükődnek mint egy funkció.

*/