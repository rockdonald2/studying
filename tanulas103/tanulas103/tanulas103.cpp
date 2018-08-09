#include "stdafx.h"
#include <iostream>

/*
! egy összetétel kapcsolatban, az egész object felel a részek mükődéséért.

Aggregation,
	ahhoz, hogy valami összesítés legyen, az object és a részek között a következő kapcsolat kell legyen:
		- a rész tagja az objectnek
		- a rész tagja lehet egyidejüleg akár több objectnek
		- a rész élettartamát nem az object kezeli
		- a rész nem tud az object létezéséről

			- amikor összesítés alakul ki, az object nem felel a részek létrehozásáról, valamint amikor az összesítés megsemmisül
				nem felel törlésükről sem.

			! az összesítés egy "van egy" kapcsolat.

			- az összesítés is egy rész-egész viszony, akárcsak az összetétel.



Implementing aggregations,
	az összesítésben úgyanúgy használunk tag változókat, de ezek leginkább hivatkozások vagy mutatók, amelyek olyan objectekre mutatnak
		amelyek a class scopeján kivül jöttek létre.
			Tehát, az összesítés változói vagy konstruktőrök alapján vannak feltöltve, vagy üresen jönnek létre, és később
				töltődnek fel hozzáférési funkciókkal.

			! mivel ezek a részek a class scopeján kivül jöttek létre, amikor a class megsemmisül, a hivatkozás vagy mutató változó is megsemmisül,
				de nem törlődnek.

				lásd pl., amelyben a Tanár-Osztály viszony, mivel az Osztálynak "van egy" tanára



				! fontos szabály, mindig a legmegfelelőbb kapcsolat típust építsd be ami teljesíti szükségleteidet, nem gondolva
					a való életben használatos dolgokra, nem azt amit helyesnek gondolsz az életre nézve.
*/


/*

Summarizing composition and aggregation,
	Összetétel:
		- általában normál tag változókat használ
		- használhat mutató változókat is ha az összetétel maga kezeli a visszaadást is
		- felelős a részek létrejöttéért és törléséért is.

	Összesítés:
		- általában olyan mutatókat vagy hivatkozásokat használ tag változóként amelyek az összesítő class scopeján kivül
			létrejött objectekre mutatnak.
		- nem felelős a részek létrejöttéért és törléséért sem.


		! akár keverni is lehet őket, olyan classokat létrehozni amelynek egyes változói összetételesek, mások pedig összesítőek.

*/