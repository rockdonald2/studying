#include "pch.h"
#include <iostream>

/*

A templatek segíthetnek nekünk, hogy általánosított class templateket hozzunk létre,
	majdnem úgyanúgy mükődik mint a sima template funkció.

*/

/*

Templata class felbontása külön fájlokra,
	a hagyományos módszer miszerint a class definició, majd a tag funkció definiciók külön egy .h és egy .cpp fájlba
		kerülnek az itt nem fog mükődni(linker error)

		ehelyett 3 módszert lehet használni:
			vagy mindent egy .h fájlba teszel, ez nem mindig a leghatékonyabb de biztos megoldás
			vagy megoldod a classot .h fájlba, majd a tag funkció definiciókat .inl(inline) fájlba teszed, majd ezt
				csatolod a .h fájlba.
			vagy használod a három-fájlos megközelítést, miszerint template class megy a .h-ba,
				a class tag funkciók mennek a .cpp fájlba, majd hozzáadsz egy harmadik fájlt
					amely tartalmazza az összes class példázást amelyikre szükséged lesz.

						- a harmadik fájlba a template class classnév<adattípus>; sémát kell használni
							a class példázat explicit létrehozásához.

*/
