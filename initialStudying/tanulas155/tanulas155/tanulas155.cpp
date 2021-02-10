#include "pch.h"
#include <iostream>

/*

A fejezet bevezetésében beszéltünk arról hogyan vezethet a mutatók használata bugokhoz és memória lékekhez
	ha egy program korán return-ol mint a várt, vagy kivételt dob és a mutató nincs megfelelően törölve

	miután átvettük a move semantics alapjait ideje visszatérni a smart pointerekhez,
		ugye a smart pointerek olyan classok amelyek maguk kezeli a dinamikusan elosztott memóriájukat,
			biztosítva, hogy a dinamikusan elosztott object törölve lesz, a memória felszabadítva a megfelelő időben
			! soha ne dinamikusan helyezd el magát a smart pointert

		C++11-ben 4 smart pointer class lett bevezetve: std::auto_ptr (C++17-ben törölve),
			std::unique_ptr, std::shared_ptr, std::weak_ptr

		messze a leggyakrabban használt az std::unique_ptr

*/

/*

std::unique_ptr,
	a C++11-ben bevezettek az std::auto_ptr helyettesítőjét az std::unique_ptr-t amely olyan dinamikusan elosztott
		objectekre használnak amelyek nincsenek több object között megosztva
		! az std::unique_ptr teljesen maga kell birtokolja az objectet amit kezel, nem megosztva a birtokjogot
			több classal
		- az std::unique_ptr a "memory" headerben található meg

		lásd pl. ahol bizonyítjuk, hogy az std::unique_ptr megfelelően magába építi a move semantics-ot

Accessing the managed objects,
	az std::unique_ptr rendelkezik egy overloadolt operator*-al és operator->-al amellyel az általa használt
		erőforrásokat lehet visszaadni
		az operator* egy hivatkozást ad vissza a kezelt erőforrásra
		az operator-> pedig egy mutatót

			! az std::unique_ptr nem mindig kezel egy objectet -- talán azért mert üresen lett létrehozva
				mert az alapértelmezett konstruktőrt használtuk, vagy nullptr-t adtunk meg paraméternek,
				vagy az általa kezelt erőforrás át lett mozgatva egy másik std::unique_ptr-ba
			- szóval mielőtt használnánk ezeket az operátorokat bizonyosodjunk meg róla a beépített cast to bool
				funkcióval amely true-t ad vissza ha az std::unique_ptr, hogy kezel valamilyen erőforrást
	
std::unique_ptr and arrays,
	nem úgy mint az std::auto_ptr, az std::unique_ptr már képes arra, hogy eldöntse, hogy az array delete kell,
		vagy a sima delete, így lehet használni velük

		! de mégis jobb megoldás ha az std::array-t vagy std::vector-t használjuk, vagy az std::string-et
			mint az std::unique_ptr-t egy fixed, dinamikus arrayal, vagy C-style stringgel.

std::make_unique,
	C++14 egy hozzáadott funkcióval jön amelynek std::make_unique() a neve, ez a templated funkció létrehoz
		egy objectet a template típusból, és inicializálja a funkcióba beadott érvekkel

		lásd pl.

		- ugyan az std::make_unique használata opcionális, ajánlott az std::unique_ptr magad készítése helyett
		- ez azért van mert az std::make_unique egyszerűbb és keresebb írást igényel (amikor az automatikus
			típus levonást használjuk)
		- valamint megold egy olyan kivétel biztonsági problémát amely abból adódhat ha a C++ meghatározatlanul
			hagyja a funkció érvek megoldási sorrendjét

Returning std::unique_ptr from a function,
	lásd pl.
		a példában megtalálható kód esetében a createResource() funkció érték alapján ad vissza egy std::unique_ptr-t
		ha ez az érték semmihez sincs hozzárendelve, akkor az ideiglenes return érték kimegy scopeból és a
			Resource pedig feltakarítódik
		de ha ez hozzávan rendelve valamihez (mint ahogy a main()-ben van) a move semantics-et használva a Resource a 
			return értékből a hozzárendelt objectbe lesz átmozgatva
			! soha ne adj vissza hivatkozás vagy mutató által egy std::unique_ptr-t

Passing std::unique_ptr to a function,
	ha azt akarod, hogy egy funkció átvegye a birtokjogát a mutató tartalmának, az std::unique_ptr érték alapján
		ad be
		! mivel a copy semantics törölve van std::unique_ptr esetében használnod kell az std::move-t

	a legtöbb esetben amúgy nem akarod ezt, hogy a funkció átvegye a birtokjogot az erőforrásra,
		ugyan beadhatod hivatkozás alapján is az std::unique_ptr-t de ezt csak akkor kellene tegyed, ha
			a funkció talán megváltoztathatja, vagy cserélheti a kezelt objectet

	a legjobb ha csak maga az erőforrást adod tovább (hivatkozás vagy mutató által, attól függően, hogy megfelelő-e
		egyik null az érvnek)
		- ez lehetővé teszi, hogy szabadgondolatú maradj arra tekintettel, hogy hogyan is kezeli az erőforrást a hívó
		- ahhoz, hogy egy nyers erőforrás mutatót nyerj az std::unique_ptr-ból használhatod a get() tagfunkciót

			lásd pl.

std::unique_ptr and classes,
	használhatod az std::unique_ptr mint a classod composition tagja, így nem kell megbizonyosodnod róla, hogy
		a class destruktőr törli a dinamikus memóriát hiszen az std::unique_ptr automatikusan törlődik mikor
		a class object is törlődik
		! de ha a class object dinamikusan van elhelyezve, az object maga kivan téve a kockázatnak, hogy nem lesz
			megfelelően törölve, ez esetben még a smart pointerek sem tudnak segíteni

Misusing std::unique_ptr,
	két féle képpen lehet félrehasználni az std::unique_ptr
		- az első ha több class kezeli ugyanazt az erőforrást
		- a második ha manuálisan törlöd az erőforrást az std::unique_ptr alatt

		! az std::make_unique() mindkét esettől megóv ha azok véletlenül következnek be
*/