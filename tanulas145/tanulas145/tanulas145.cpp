#include "pch.h"
#include <iostream>

/*

Exceptions and member functions,
	eddigi példák során mind non-member funkciókban használtuk a kivételeket, azonban egyformán hasznosak
		a kivételek a member funkciókban, és méginkább az overloadolt operátorokban.

		tegyünk fel egy alapvető overloadolt [](index) operátort, lásd pl.
			alapesetben nem tartalmaz semmilyen error checkinget, használhatunk assertet, de például
				mivel az overloadolt operátorok esetében korlátozott paraméterekkel dolgozunk, így sem error-kódot,
				sem bool értéket nem használhatunk, azonban a kivételek remek megoldást adnak.

*/

/*

When constructors fail,
	a konstruktőrök egy másik terület ahol a kivételek hasznosak lehetnek, ha a konstruktőr hibázik és így nem jön létre
		az object valamint a destruktőr sem hajtódik végre, simán dob egy kivételt, de fontos megjegyezni
		hogy ebben az esetben a konstruktőr maga kéne intézze a takarítást is.

*/

/*

Exception classes,
	az egyik legnagyobb gond az alapvető adattípusokkal mint kivétel típusokkal az, hogy nagyon kevés információt
		nyújtanak, egy még nagyobb probléma az az egyértelműsítés tekintettel arra, hogy mit is jelent egy kivétel
			amikor több állítás vagy funkció lehívás van ugyanazon try blokkon belül

			vegyük tekintettel a fenti overloadolt operátort,
				mit is kéne catch-elni ott?
				- azért nem sikerült mert nem megfelelő volt az index?
				- elfogyott a memória és nem tudott végrehajtódni a new?
				- a +operátor overflow okozott?

				ebben az esetben sajnos nincs könnyű út arra, hogy egyértelműsítsünk
				- használhatunk const char*-t arra, hogy meghatározzuk mi is rontódott el, de ez még mindig
				nem teszi lehetőve, hogy különböző forrásból származó kivételeket különböző módon kezeljünk
			
	egy mód, hogy ezt kezeljük az exception class.
		- az exception class az egy normális class amit arra terveznek, hogy kivételként legyen dobva
		
		a példában használva, az exception array által egy leírást kapunk az adott problémáról, 
			kontextus biztosítva, hogy mi ment balra.
			- mivel az ArrayException egy egyedi típus, pontosan eltudunk kapni egyes kivételekt, és adott
				módon kezelni őket.

*/

/*

Exceptions and inheritance,
	mivel lehetséges classokat dobni mint kivételek, valamit classok származtatva lehetnek más classokból,
		megkell vizsgáljuk az esetet amikor származtatott classot használunk mint kivétel.
		- ahogy elválik, az exception handler(catch) nemcsak az adott típussal fog találni,
			hanem azzal a classal is amit abból a típusból származtattunk

				lásd pl.
				- rossz az output, a Derived exceptiont a Base handler fogta ki?
					- a probléma az, hogy mit fentebb leírtam, hogy a Derived típust a Base handler fogja kifogni,
						mivel amikor egy kivétel tűnik fel, a try blokk után egymás után ellenőrzi le a catch blokkokat
						keresve melyik a megfelelő, mivel a Derived is a Base(is-a kapcsolat) a Base handler
						megegyezik a Derived exceptionnal és az hajtódik végre.

				- ahhoz, hogy megfelelően működjön, megkell cseréljük a két catch blokkot
					- ez által először a Derived handlerrel veti össze és az hajtódik végre

					! szabály, a derived classhoz tartozó catch blokkok hamarább kell legyenek a sorba,
						mint a base classhoz tartozók.

*/

/*

std::exception,
	rengeteg class illetve operátor a standard libraryból képes exception classokat dobni hiba esetén,
		ilyen a new illetve az std::string amelyek hiba esetén az std::bad_alloc-ot képesek dobni,
		vagy akár a dynamic_cast ami az std::bad_cast-ot

	a jó hír az, hogy az összes ilyen kivétel egyetlen classból van származtatva ami az std::exception
		az std::exception az egy interface class ami egy base classként funkcionál minden kivételhez amit
			a standard library dobhat.

	így ha handlerben használjunk az std::exception-t, képesek vagyunk minden alapvető kivételt egyetlen helyen kezelni.

		lásd pl.
		- fontos tudni, hogy a what() egy virtuális member funkciója az std::exception, ami visszaad egy C-style stringet
			arról, hogy mi rontódott el.
	
	gyakran akarjuk, hogy némely kivétel különb módon legyen kezelve
		használhatunk egy másik handlert az adott típushoz, és hagyuk, hogy a többi csak átmenjen rajta a base
			handlerig.

*/

/*

Using the standard exceptions directly,
	semmi sem dob közvetlenül std::exception kivételt, és neked sem kellene
	azonban szabadon lehet használni a többi standard exception classot, ha megfelelőek neked.
		lista: https://en.cppreference.com/w/cpp/error/exception
	std::runtime_error gyakori választás(stdexcept headerból), mivel általános neve van, illetve a konstruktőrje
		bevesz egy testreszabható szöveget

		lásd pl.s

*/

/*

Deriving your own classes from std::exception,
	természetesen lehetséges a saját exception classjaidat származtatni az std::exception classból,
		majd felülírni a virtuális const tag what funkciót a saját üzeneteddel.
			- a noexcept specifier által megigérjük, hogy a funkció maga nem fog semmi kivételt dobni.
		lásd pl.
*/