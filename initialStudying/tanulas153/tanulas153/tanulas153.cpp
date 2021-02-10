#include "pch.h"
#include <iostream>

/*

Copy constructors and copy assignment == copy semantics
	a copy konstruktőr arra használjuk, hogy inicializáljunk egy classt az által, hogy egy másolatot készítünk
		egy objectből amely ugyanabból a classból származik
	a copy assignment által egyik classt egy másik létező classba másoljuk bele

	- alapból a C++ biztosít egy copy konstruktőr és assignmentet, ha nincs kifejezetten írva egy helyettesítő
	- ezek a compiler által biztosított funkciók shallow copyt csinálnak, amely problémák okozhat
		olyan classoknak amelyek dinamikus memóriaelosztást használnak
		! classok amelyek dinamikus memóriaelosztást használnak kifejezetten kell saját copy assignment és
			konstruktőrt biztosítaniuk

		lásd auto_ptr class példa

			- ez egy olyan auto_ptr példa amely nem crashel, de nem is hatékony, mivel röviden mivel egyszer a copy
				konstruktőrt hívjuk ahhoz, hogy a res-t egy ideiglenes objectbe másoljuk, majd copy assignmentel
				belemásoljuk az ideiglenes objectet a mainresbe, ez alapján mi elhelyezünk majd törlünk
				a memóriából 3 különböző objectet összben.

			ezt sokkal hatékonyabban végre lehet hajtani move semantics-al

*/

/*

Move constructors and move assignment == move semantics
	C++11 két új funkciót vezetett be ahhoz, hogy a move semantics megfelelő legyen: move konstruktőr, move assignment
		operátor
		mialatt a copy konstruktőr és copy assignment célja az, hogy egyik objectet egy másikba másoljon,
			addig a move konstruktőr és move assignment célja az, hogy az adatok(erőforrások) birtokjogát az egyik
				objectről a másikra ruházza át.(így kikerülve a drága másolást)

	a move konstruktőr és move assignment meghatározása hasonlóan működik a copy megfelelőjükkel, de míg a copy
		típusúak egy const l-érték hivatkozást használnak paraméterként, addig a move típusú nem const r-érték
			hivatkozást.

			lásd pl.

			lényegében a move constructor és assignment minden esetben ellopja az egyik object erőforrását
				a másikba, így 3 létrehozás-törlődés helyett csak egy zajlik le
				! csak akkor hívódik le ha mi magunk határoztuk meg, mert az alapértelmezett move típus
					ugyanazt végzi mind a copy (másolatot készít és nem mozgat), illetve ha r-érték
					értékkategóriájú a beadott érv (literal, vagy temporary érték)

The key insight behind move semantics
	a kulcs gondolat a move semantics és copy semantics mögött, hogy különböző viselkedést tudjunk létrehozni
		l-értéknek illetve r-értéknek, mivel az l-értékek esetében pl. a = b, nem várnánk el, hogy a 'b' érték
			bármiféle módon megváltozzon, míg ha egy r-értékkel dolgozunk amit értelmetlen másolgatni
			tudjuk, hogy azt később úgyse használhatnánk, és mégis olcsón tudjuk az erőforrásait máshova mozgatni

Move functions should always leave both objects in a well-defined state,
	a példában feltűnhet, hogy mind a move konstruktőr és a move assignment az a.m_ptr nullptr-ra teszi át
		ez furának tűnhet, hiszen az a.m_ptr egy ideiglenes r-érték, így minek takarítanánk fel utána, ha
			úgyis törlődik a funkció végén?
	Válasz egyszerű: ha úgy hagynánk, a funkció végén valóban törlődne, de mivel az a.m_ptr és az m_ptr
		ugyanarra az objectre mutat, az m_ptr ezután egy logó mutató lenne, hiszen a memória cím törlődött
		- azonban a következő leckében lesz olyan amikor az "a" l-érték is lehet, ott pedig az a "a" nem
			lenne egyből törölve, és tovább lehetne lekérdezni mielőtt az élettartama lejár

Automatic l-values returned by value may be moved instead of copied,
	a generateResource() funkcióban a res valójában l-érték, mégis amikor érték által returnoljuk
		ahelyett, hogy másolva lenne, mozgatva lesz, hiszen a C++ van egy olyan szabálya, hogy
		lehetséges automatikus objecteket amelyek egy funkcióból adnak vissza érték által
			mozgatni, még akkor is ha l-értékek
			- hiszen az res úgyis törlődik a funkció végén

			- a compiler ennél jobbat is tud csinálni, kitudja hagyni az egész copy műveletet (ami elkerüli, hogy
				a copy vagy move megtörténjen), ebben az esetben semmi a copy konstruktőr, sem a move nem hívódik le

Disabling copying,
	néha a move képes classoknál azt akarjuk, hogy töröljék a copy konstruktőrt és assignment operátort, hogy
		megbizonyosodjunk3 róla, hogy nem történik másolás

		lásd pl. 
*/