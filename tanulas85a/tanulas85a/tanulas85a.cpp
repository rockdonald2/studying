#include "stdafx.h"
#include <iostream>

/*

Az ez előtti leckében a tag adatokat egy konstruktőrben hozzárendelés operátorral inicializáltuk.
		ez hozzárendelés és nem inicializálás.
	Ez a séma érvényes a C++-ban, de nem mutat be jó stílust(és kevésbe hatékony mint az inicializálás.)
	Néhány adattípus muszáj inicializálva legyen azon a soron ahol meghatározzák, pl. const-ok, hivatkozások.
		Értékeket hozzárendeni egy consthoz vagy hivatkozáshoz a konstruktőr bodyjában nem elégséges néhány esetben.

*/


/*

Member initializer lists,
	ahhoz, hogy megoldjuk a fenti problémát, a C++ biztosít egy metódust class tag változók inicializálásra
		a tag inicializáló lista. Ne téveszd össze az initializer list-el amit array értékek hozzárendelésére használunk.

	három féle módon lehet inicializálni: copy, direct, vagy uniform.

		lásd pl.

	a member initializer list a konstruktőr paraméterek után van beillesztve, egy :-al kezdődik és utána van felsorolva
		az összes változó amit inicializálni kell együtt az értékkel, elválasztva egy ,-el.

		- itt is használhatsz default értéket
		- így tudsz hivatkozást, vagy const értéket inicializálni.

		! használd a member initializer list-et hozzárendelés helyett.


Uniform initialization,
	! szabály, használd a uniform initialization-t a direct helyett.


Initializing array members with member initailizer lists,
	képzelj el egy classot ami tartalmaz egy array tagot
		C++11 előtt nem tudtunk member initializer list-el hozzárendelni értékeket, csak zerozni.
		C++11 után már képesek vagyunk uniform initialization-el hozzárendelni értékeket.
			lásd pl.


Initializing member variables that are classes,
	egy member initializer list arra is használható, hogy olyan tagok inicializáljunk amelyek classok.
			lásd pl.


Formatting your initializer lists,
	C++ rengeteg rugalmasságot ad arra vonatkozóan, hogyan lehet formázni az initializer list-et, és ez igazán csak rajtad múlik.
		De azért van néhány javaslat:
			- ha az initializer list elfér ugyanazon a soron amelyen a funkció neve is van, akkor minden egy sorra kerül.
			- ha nem, akkor a következő sorra kerül az initializer list.
			- de akár lehet mindegyiket külön-külön sorra tenni, veszővel elválasztva a sorokat és az első kettösponttal kezdődve.


Initialzier list order,
	Meglepő, de a változókat az initializer list-ben nem abban a sorrendben vannak inicializálva ahogy mi megadtuk, hanem
		amilyen sorrendben megvannak határozva a classban.

		! - mindig figyelj arra, hogy ne inicializálj tag változót olyan sorrendben amely alapján egy másik tag változótól függ.
		  - inicializáld a változóidat az initializer list-ben olyan sorrendben ahogy megvannak határozva a classban.

*/