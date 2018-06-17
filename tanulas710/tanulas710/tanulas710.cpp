#include "stdafx.h"
#include <iostream>

/*

Std::vector capacity, and stack behavior,
	nemúgy mint a beépített arrayok esetében, vagy az std::array esetében, amik csak a hosszukra emlékeznek,
		az std::vector tartalmaz két különböző tulajdonságot, hossz és kapacitás.
			a hossz azt fejezi ki, hogy hány elemet használunk az arrayben,
			a kapacitás azt fejezi ki, hogy hány elemet helyeztünk el a memóriában.

		lásd pl.

		! fontos tudni, hogy a kapacitás garantáltan legalább akkora mint az array hossza, de lehet akár nagyobb is.


	a második példában átméreteztünk egy adott vectort kevesebb elemmel, de a kapacitása nem változik.
		ez azért van mert a vector nem szabadította fel a memóriát, csak megjegyzi, hogy azután már csak az első 3 elem érvényes.
		a vector képes elosztani, és felszabadítani memóriát, de jobban szereti nem megtenni ezt.


Array subscripts and at() are based on lenght, not capacity,
	az index[] operátor és az at() funkció hatótávolsága a hosszon alapszik, és nem a kapacitáson.
		! az array nem méretezi át magát egy hívásra alapozva az index[] operátor vagy az at() funkció által.

*/


/*

Stack behavior with std::vector,
	habár, az std::vector használható mint egy dinamikus array, akár használható mint egy rakás, mint egy stack.
		ahhoz, hogy ezt tegyük használhatunk három kulcsfontosságú funkciót ami megegyezik a rakás müveleteinkkel.
			push_back() - felhelyez egy elemet a rakásra.
			back() - visszaadja a legfelső elemet a stackről.
			pop_back() - levesz egy elemet a rakásról.

			lásd pl.

	nem úgy mint az at(), vagy az index[] operátor esetében, ez a fajta rakás mükődés átméretezheti a vectort.
		ebben a példában a vector 3-szor lett átméretezve.
		ahhoz, hogy elkerüljük ezt a drága müveletet használhatjuk a reserve() funkciót amellyel egy bizonyos nagyságú
			kapacitást elhelyezhetünk a vector számára.

*/


/*

Vectors may allocate extra capacity,
	amikor egy vector átméreteződik, a vector talán még több kapacitást fog elhelyezni mint ami szükséges,
		hogy biztosítson egyfajta szabad helyet a jövőbeli méretezéseknek, hogy csökkentse a szükséges méretezési müveleteket számát.

		lásd 3 pl.
*/