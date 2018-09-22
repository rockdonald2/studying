#include "pch.h"
#include <iostream>

/*

The need for dynamic_cast,
	amikor polimorfizmussal dolgozik, gyakran találkozól olyan esetekkel amikor van egy mutatód egy base classhoz,
		és olyan információt akarsz elérni ami a derived classban létezik.

		lásd pl.

		- a példában található az eset, amikor a getObject() mindig egy base mutatót add vissza ami vagy egy base objectre,
			vagy egy derived objectre mutat, ha az utóbbira hogyan tudjuk lehívni az objectre a Derived::getName() funkciót?
		- használhatnánk virtuális funkciót is, de ezzel csak olyan funkciót jutattnánk a Base classba ami nem való oda,
			illetve egyéb gondok is előjönnének.
		- - azt tudjuk, hogy a C++ lehetővé teszi, hogy magától értetődöen átalakítson egy derived mutatót base mutatóvá
			(a getObject() funkció pont ezt teszi) ezt a folyamatot hívjuk upcastingnek.
			Mi lenne akkor ha lenne mód arra, hogy ezt a mutatót visszaalakítsuk derived mutatóra, ekkor képesek lennénk
				közvetlen módon lehívni a Derived::getName() funkiót.

Dynamic_cast,
	a dinamikus cast pont ezt csinálja,
		habár, a dinamikus cast más dolgokra is képes, messze a leggyakrabban használt arra, hogy átalakítson base-class mutatókat
			derived-class mutatókká. Ezt hívjuk downcastingnek.


Dynamic cast failure,
	az előzö példá rendben mükődik azért mert a base mutató egy derived objectre mutat.
		De mi van akkor ha a base mutató egy base objectre mutat?
		A válasz az, hogy a dynamic cast sikertelen lesz, és sikertelen castolás esetén null mutatót add vissza.
		- ezért minden dynamic cast után ajánlatos beépíteni egy ellenőrzést, hogy nem-e null mutatót adott vissza.

		! fontos megjegyezni, hogy a dinamikus cast runtime idején végez némi összetétel ellenőrzést(hogy megnézze az átalakítás
			elvégezhető-e) ezért teljesítmény büntetéssel jár.

		! néhány eset amikor a dinamikus cast nem végezhető el:
			1) amikor private vagy protected módú az öröklés
			2) olyan classok amik nem határoznak meg, vagy nem örökölnek virtuális funkciót(és ez által nincs virtual tablejük)
			3) bizonyos esetekben virtual base classok esetében.


Downcasting with static_cast,
	a downcastolás static_cast esetében is elvégezhető.
		de mivel a static_cast runtime idején semmiféle összetétel ellenőrzést nem alkalmaz(így nincs teljesítmény büntetés sem)
		ezért a static_cast gyorsabb, de veszélyesebb, mivel nem ellenőrzi le, hogy amit csinálsz van-e értelme.
		így a fentebb említett probléma esetében is átalakítja a mutatót, de ez nem várt hibákat eredményezhet amikor el
			próbálod érni.

		azonban a static_cast használhatod amikor egészen biztos vagy benne, hogy az átalakítás sikerülni fog
			(vagy beépítesz valamilyen ellenőrzö algoritmust), pl virtuális funkcióval


Dynamic cast and references,
	habár a fenti példa mind csak mutatókat használ, a dynamic castot hivatkozásokkal is úgyanúgy lehet használni,
		és egyformán mükődik a kettő.
			lásd pl.

		! mivel nem lehet null hivatkozást visszaadni ha az átalakítás nem sikerül, ekkor std::bad_cast exception lesz kiírva


Dynamic cast vs static cast,
	mikor használjuk dinamikus castot és mikor statikust?
		válasz egyszerű: minden esetben használj static_castot kivéve amikor downcastolsz, mert ekkor a dinamikus jobb választás.

		! de a legjobb esetben ne is használd a castot, hanem virtuális funkciókat.


Downcasting vs virtual functions,
	Általában, a virtuális funkciók jobb megoldás mint a downcast, de vannak esetek amikor a downcast egy jobb döntés:
		1) amikor nem tudod módosítani a base classot, hogy hozzáadj egy virtuális funkciót.
			(mert a base class a standard library része)
		2) amikor olyan dologhoz akarsz hozzáférést ami derived-classra jellemző.
			(olyan funkciót elérni ami csak a derived classban létezik)
		3) amikor virtuális funkciónak a hozzáadása a base classhoz értelmetlen.
			(nincs megfelelő értéke amit visszaadjon)
			- ez esetben egy pure virtual function használata elég lenne, ha nem kell példáznod a base classot.

*/