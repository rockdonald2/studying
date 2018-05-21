#include "stdafx.h"
#include <iostream>

/*

a sima felsorolások egyáltalán nem biztonságosak, mivel gyakran engednek olyan dolgokat is tenni, amiknek nincs értelmük.
	ilyen pl. különböző felsorolásokból összehasonlítani felsoroltakat, amelynél az történik, hogy mindkét felsoroltat átalakítja
		számmá, a felsorolásban elfoglalt helye alapján, és ezt a két számot hasonlítsa össze, ennek nem szabadna megtörténie.

*/

/*

enum class,
	a fenti hibából adódóan lett bevezetve
	erősen lekorlátozza a felsoroltakat, mivel ezután nem a global scopeba, vagy a block scopeba lesz a felsorolása egésze,
		hanem a felsoroltak, a felsorolás scopejában, és mostmár nem lehet direkt elérni öket, 
			csak ha a Felsorolásneve::FELSOROLTNEVE paranccsal.

				pl: Felsorolásneve teszt = Felsorolásneve::FELSOROLTNEVE;

	további fontos sajátossága, hogy "strong typing rules" vonatkozik rá, így nem lehet különböző felsorolásokat összehasonlítani.
		mivel minden felsorolás egy egyedi típus.

	illetve, mostmár nem fogja magától számmá alakítani a felsoroltakat helyük alapján, mostmár static_cast-et kell használni ehhez.

*/