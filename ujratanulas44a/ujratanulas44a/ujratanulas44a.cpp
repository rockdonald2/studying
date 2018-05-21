#include "stdafx.h"
#include <iostream>

/*

Explicit type conversion(cast)
	határozott típus átalakítás magába foglal egy utasítást a felhasználótól, hogy milyen alakítást végezzen a compiler.

		5 fajta cast van: c-style cast, static casts, const casts, dynamic casts, and reinterpret casts.
			tipp: soha ne használd a const casts-t és a reinterpret casts-t, hacsak nincs egy nagyon jó okod rá.
				(több rosszat csinálnak mint jót)

*/

/*

C-style cast,
	a standard C nyelvben az átalakítás a () operátorral történik, a zárójelbe a kivánt típust írjuk.

		tipp: ezt is kerüld, mivel a compiler nem ellenőrzi le ezt a típusú átalakítást compile idején, így akár olyan dolgokat
			is hagy megtenni amik abszurddak, így meglehet szabadulni egy const értéktől, vagy megváltozatni egy adattípust a bitformátum
			módosítása nélkül.

*/


/*

static_cast, 
	ez a legjobb megoldás arra, hogy egyik alapvető típust a másikká alakítsuk.


*/