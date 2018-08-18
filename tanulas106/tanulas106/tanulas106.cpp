#include "pch.h"
#include <iostream>

/*

Container classes,
	a konténer classok azt a célt szolgálják, hogy raktározzák, és rendezzék többszöri példázatát egy másik típusnak
		- legyen az egy másik class, vagy alapvető adattípus

		rengeteg típusú container class létezik, mindegyiknek megvan a maga előnye, hátránya, valamint korlátai.
			messze a legtöbbet használt container class az array
				- de ebben az esetben nem a beépített arrayre gondolunk, hanem az std::array, vagy std::vector,
					mivel ezek dinamikusan átméreteződnek, emlékeznek a hosszúkra még akkor is ha funkcióknak adjuk tovább,
						valamint végeznek bound checkinget is.


			egy jól beépített konténer class a következő funkciókat kell ellássa:
				- létrehozzon egy üres konténer(egy konstruktőr segítségével)
				- új objecteket adjon hozzá a konténerhez
				- objecteket töröljön a konténerből
				- leadja a jelenleg konténerben levő objectek számát
				- üresítse a konténert
				- biztosítson hozzáférést a konténer objectjeihez
				- valamint rendezze a konténer tartalmát, ez opcionális


					! esetenként ki lehet hagyni néhány funkcionalítást.

					! a konténer classok a "tagja a" kapcsalattípusba tartozik
						az array elemei tagja az arraynek

*/


/*

Types of container classes,
	általában a konténer classok két variációját különböztetjük meg
		vannak az érték konténerek, amelyek kompozíciók, és raktározák objectek másolatait amit tartalmaznak
		(ez által felelnek azok létrejöttéért, valamint megsemmisüléséért)
		vannak a hivatkozás konténerek, amelyek összesítések, és raktároznak hivatkozásokat, és mutatókat más objectekre
		(ez által nem felelnek azok létrejöttéért, valamint megsemmisüléséért)

		! fontos megjegyezni, hogy a C++-ban egy konténer csak egyetlen adattípust tud raktározni, ahhoz, hogy
			több adattípussal dolgozzon két különböző konténert kell létrehozni.


An array container class,
	lásd pl.
*/