#include "stdafx.h"
#include <iostream>

/*

while statement,
	a while állítást a legegyszerűbb a 4 loop közül amit a C++ biztosít
		sémája nagyon hasonló az if állításhoz:
			
			while (kifejezés)
				állítás;

	egy while állítást létrehozunk a while kulcsszóval. Amikor a while állítás végrehajtódik a kifejezés kiértékelődik,
		ha értéke nem nulla lesz, akkor az állítás végrehajtódik.

	ugyanakkor, nem úgy mint egy if állítás esetében, amikor az állítás végrehajtása véget ért, az irányítás visszakerül
		a while állítást tetejére, és a folyamat megismétlődik.

*/

/*

Végtelen loop (infinite loops),
	vannak esetek amikor a loop egyszer sem hajtódik végre, mivel a kifejezés értéke alapból false.
	vannak esetek amikor a loop mindig true-nak értékelődik, ekkor jön létre a végtelen loop.

		egy végtelen loopot megtörni egy return állítással, break állítással, exit állítással, goto állításal, vagy
		egy kivétellel lehet, de akár a felhasználó is leállíthatja a programot.

*/


/*

loop változók (loop variables),
	gyakran, azt akarjuk, hogy egy loop meghatározott számú alkalommal hajtódjon végre.
		ahhoz, hogy ezt elérjük használhatunk egy loop változót, gyakran számlálónak(counter) hívják.
	egy loop változó egy olyan integer típusú változó, aminek az egyetlen funkciója, hogy számolja hány alkalommal
		hajtódott végre az adott loop.

	legjobb ha signed integer típust használsz loop változónak.

*/


/*

ismétlés (iteration),
	minden alkalommal amikor végrehajtódik az adott loop, az egy ismétlés.

	mivelhogy, a loop body-ja egy blokk, és minden ismétléssel abba a blokkba ki-be lépkedünk, ezért minden változó
		amit azon belül hozzunk létre, minden ismétlés esetében létrejön majd elpusztítódik.

	alapvető típusok esetében ez rendben van, de structs, vagy classes során teljesítménybeli problémákat okozhat.
		ezért az utóbbiakat jobb ha a loop előtt hozod létre.
			! a számláló, loop változódat, is a loop előtt hozd létre, mert jelenléte állandó kell legyen, folytatódnia kell.

*/


/*

Fészkelt loop (nested loop),
	lehetséges több while loopot egymásba fészkelni.

*/

