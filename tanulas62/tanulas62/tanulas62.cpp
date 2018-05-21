#include "stdafx.h"
#include <iostream>


/*

Fix hosszúságú array inicializálása,
	úgyanúgy mint egy normál változó az array elemek sincsenek inicializálva keletkezéskor.

		lehet inicializálni elemről elemre, de ez nagy hosszúságú arrayek esetében nem kényelmes.

		Szerencsére, van egy átfogó út a initializer listával,
			séma: int primSzam[5] = { 2, 3, 5, 7, 11 };

				ha egy initializer listában több elem van mint az array hossza, akkor error-t nyom a compiler
				ha kevesebb akkor a maradék elemek 0-val lesznek inicializálva.

		De akár lehet uniform incializálással is
			pl. int primSzam[5] { 2, 3, 5, 7, 11 };
				! nincs egyenlő !

*/


/*

Elhagyható hosszúság,
	Ha incializálsz egy fix array elemeit initializer listával, a compiler ki tudja "találni" az array hosszát neked,
		és elhagyhatod az array létrehozásában a hossz-t a [] zárójelben.

			int primSzam[5] = { 2, 3, 5, 7, 11 }; // kibővitetten elmondod a compiler-nek hány változót akarsz
			ugyanaz mint a
			int primSzam[ ] = { 2, 3, 5, 7, 11}; // hagyod, hogy a compiler döntse el hány kell.

*/


/*

Egyik nagy dokumentáció probléma az array-kel, az, hogy egy integer nem szolgál semmilyen információval az index jelentéséről.

	Az egyik megoldás erre ha egy felsorolást (enum) használunk, ahol egy felsorolt extra, amit használunk az array létrehozásánál
		és jelöli az array helyes hosszát.


	Ha enum class-ot használunk akkor static_cast<>()-el kell integerré alakítanunk a felsoroltakat, mert alapból ezt nem teszi meg.
		Ebben az esetben jobb a sima enum-al maradni, és azt namespace-be rakni.

*/


/*

Továbbadni array-t egy funkcióba,
	amikor továbbadunk paraméterként egy array-t akkor, nem jön létre egy másolat arról az array-ről mint egy normál változó esetében,
		így képes az adott funkció megváltoztatni az adott array értékét, és így a rendes array értékét is.

			Hogy ezt elkerüljük használhatod az array paramétert constként.

*/


/*

Sizeof és array,
	a sizeof operátort lehet használni array-on, és vissza fogja adni az egész méretét az arraynek(array hossza * elemek mérete).
	Ebben az esetben nem kell a [] zárójel, kivéve ha egy elemre gondolsz.
		! fontos, mivel ahogy a c++ kezeli a továbbadást array-ek esetében, ez nem fog rendesen mükődni funkció paraméter esetében.

*/


/*

Egy fix array hosszának megállapítása,
	egy trükk, ahhoz, hogy megkapjuk egy nem ismert array elemeinek számát, eloszthatjuk az egész array sizeof-ját, az egy elemre
	jutó sizeoffal.

			séma: sizeof(array) / sizeof(array[0])

		! fontos ezt abban a funkcióban használd ahol az array létrejött, és csakis fix array esetében.

*/


/*

Egy skálán kivüli array indexelése,
	amikor egy 5 elemű azaz 0,1,2,3,4 array-nek a 6-ik elemét(5) akarjuk indexelni és ahhoz értéket hozzárendelni,
		a compiler nem fog error-t dobni, vagy ezt ellenőrízni, simán hozzárendeli, oda rendeli ezt az értéket ahol a 6-ik elem lett volna.
			Ebben az esetben meghatározatlan viselkedés lesz, lehet crashelni fog, lehet egy másik változó értékét írja át.

		Szabály: bizonyosodj meg róla, hogy helyes indexeket használsz a skálán belül amikor array-el dolgozol.

*/



