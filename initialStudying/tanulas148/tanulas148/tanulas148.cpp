#include "pch.h"
#include <iostream>

/*

Mint mindennek, a kivételeknek is vannak előnyei, de érdemes beszélgetni a hátrányairól is.

*/

/*

Cleaning up resources,
	az első dolog amellyel rengeteg új programozó hibázik amikor kivételeket használ az az erőforrások feltakarítása
		amikor egy kivétel jelenik meg.

		lásd két pl.

*/

/*

Exceptions and destructors,
	nem úgy mint a konstruktőr esetében ahol a kivétel hasznos lehet arra, hogy jelezzük, hogy az object létrehozása
		nem sikerül, kivételeket sose szabad a destruktőrból dobni
	a probléma az unwinding folyamat során jelentkezik, amikor a compiler nem tudja, hogy folytassa-e az unwinding
		folyamatot vagy kezelje az új kivételt, ez esetben a program azonnal leáll

	a legjobb megoldás egy error üzenet írása egy logfileba.

*/

/*

Performance concerns,
	a kivételek alacsony teljesítményvesztéssel jelentkeznek, növelik a futtatható fájlod méretét, és lassabban
		futnak a hozzáadott ellenőrzés miatt.
	ugyanakkor, a fő teljesítménybüntetés akkor jelentkezik amikor a kivételt tényleges dobják, és a stacken kell
		vizsgálni a handler után

		- megjegyzésként, némely modern számitógéparchitektúra támogat egy kivétel modelt ami zero-cost exceptionnek
			hívnak, ez esetben nincs hibamentes runtime esetén teljesítményvesztés, de sokkal nagyobb a büntetés
				amikor egy kivételt talál.

*/

/*

So when should I use exceptions?
	akkor a legjobb használni a kivételt amikor a következők teljesülnek:
		- a hiba amit kezelni kell csak ritkán jelentkezik
		- a hiba komoly és a végrehajtás nem folytatódhat másképp
		- a hibát nem lehet ott kezelni ahol megjelent
		- nincs megfelelő alternatíva arra, hogy error kódot adjunk vissza a hívónak.

*/