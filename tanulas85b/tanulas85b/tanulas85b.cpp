#include "stdafx.h"
#include <iostream>

/*

Non-static member initialization,
	amikor egy classot írsz, amely több konstruktőrt is tartalmaz, egyesével meghatározni minden alapértéket az összes taghoz
		minden egyes konstruktőrben felesleges kódot eredményez.
		ha megakarod változtani egy tag alapértékét, az összes konstruktőrhöz hozzá kell nyúlj.

		C++11-től kezdődöen lehetséges normál class tag változóknak(amelyek nem használják a 'static' kulcsszót) egy alap
			inicializáló értéket megadni közvetlenül.
				lásd pl.

		A nem-statikus tag inicializálás, biztosít alapértékeket a tagváltozókhoz amelyeket a konstruktőrjeid fognak használni, ha
			a konstruktőrök nem biztosítanak inicializáló értékeket a változókhoz maguk(az initializer list-el).
		Ha biztosítva vannak alap inicializáló értékek, és a konstruktőr inicializálja a tagokat az initializer list-el,
			az initializer list-nek lesz elsőbbsége.
		Ha nem létezik alapértelmezett konstruktőr, van biztosítva alap inicializáló érték, és van egy konstruktőr ami két
			paramétert fogad be, nem lehet paraméter nélkül létrehozni objectet, mert kéri a két paramétert és nincs alap-
			értelmezett konstruktőr ami létrehozza az objectet.

			! szabály, használd a nem statikus tag inicializálást, hogy alapértékeket határozz meg a tag változóidnak.

*/