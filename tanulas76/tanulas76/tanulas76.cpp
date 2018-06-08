#include "stdafx.h"
#include <iostream>

/*

Function overloading,
	az egy olyan vonása a C++ nyelvnek, mely szerint lehet akár több funkciónak úgyanaz a neve,
		amíg különböző paramétereket használ.
		lásd pl.

*/


/*

! egy funkció return típusa nem számít egyediségnek
	sokkal egyszerűbb ha csak az érvek alapján döntjük el melyik funkciót akarjuk használni, mintha a return-t is számításba vennénk
	ami sokkal több analízist igényelne.

		pl.
			int getRandomValue();
			double getRandomValue();
				- a két funkciónak úgyanaz a paramétere, de különböző a return, mégis a compiler errort fog jelezni.

				! legjobb megoldás különböző neveket használni, vagy 'out' paramétert használni.

				a második esetben egyedi lesz, de ahhoz, hogy ezt használd szükséged lesz majd egy ideiglenes változóra ami
					tárolja az output-ot.
					valamint az érv típusa tökéletesen megkell egyezzen a paraméter típusával.
					! nem ajánlott ez a módszer.


! typedef-ek nem számítanak különbözőnek
	mivel a typedef nem hoz be egy új típust, csak egy 'álnevet' egy meglévőre a paraméter nem számít különbözőnek.

*/


/*

Hogyan lesznek párosítva a funkció hívások az 'overloaded' funkciókkal,
	egy 'overloaded' funkcióra való hívás három lehetséges kimenetellel rendelkezhet:
		1) pár találva, a hívás megoldódott egy adott overloaded funkció által
		2) nem talált párt, az érvek egyik overloaded funkcióval sem egyeznek meg.
		3) kétértelmű pár találva, az érvek több mint egy overloaded funkcióval egyeznek meg.(error)

	amikor egy 'overloaded' funkció hívódik le, C++ a következő lépéseken megy keresztül ahhoz, hogy megállapítsa
		melyik funkciót volt lehívva:
		1) Először, a C++ próbál keresni egy pontos párt. Egy olyan esetet amelyben az érv pont megegyezik a paraméterrel.
		2) Ha nincs pontos pár, C++ megpróbál keresni egy pár előléptetés által,
			azaz vannak olyan adattípusok amelyek maguktól átalakulnak egy nagyobbrendű típussá.
		3) Ha nem lehetséges az előléptetés, akkor a C++ megpróbál standard átalakítás által párt találni
		4) Végül, C++ próbál keresni egy párt felhasználó által meghatározott átalakítás által.
			(class)

*/


/*

Kétértelmű párok,
	ha minden egyes 'overloaded' funkció egyedi paramétere kell legyen, hogyan lehetséges, hogy egy hívásnak akár több
		párja is lehet?

		mivel minden átalakítás egyenlő, legyen az akár standard, vagy felhasználó általi, ha egy funkció hívás
			többel is párt alkot az átalakítások miatt, egy kétértelmű pár jön létre.

			! ez egy compile-time error, amit megkell oldani mielőtt compileolnál.

			megoldási módszerek:
				- gyakran a legjobb megoldás az ha egy új 'overloaded' funkciót hozunk létre más paraméterrel, ami
					pontosan az amit érvben használunk.
				- akár használhatsz static_cast<>()-ot is ahhoz, hogy átalakítsd abba a típusba ami neked kell.
				- ha számot használsz akár használhatod a suffixokat is, hogy bebiztosítsd a megfelelő típust.
					pl. u(unsigned) vagy f(float)

*/


/*

Ha egy funkciónak több érve is van,
	az összes érv szépen sorjában meglesz vizsgálva, a párosítási szabályok által.
		szóval, a kiválasztott funkciónak muszáj biztosítania egy jobb párt mint az összes többi,
			legalább egy paraméterrel, és nem rosszabbul mint az összes többi paraméter.

*/


// ! használd az 'overloaded' funkciókat, hogy a programodat egyszerűbbé tedd.