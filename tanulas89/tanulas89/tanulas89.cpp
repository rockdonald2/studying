#include "stdafx.h"
#include <iostream>

/*

Defining member functions outside the class definition,
	minden class amit eddig írtunk annyira egyszerű volt, hogy képesek voltunk a tag funkciót beépíteni közvetlenül a class
		meghatározásba.

	Úgyanakkor, ahogy a classok hosszabb és bonyolultabbak lesznek, minden tag funkciót elhelyezni a classba nehezebbé teheti a 
		class kezelését és a vele való dolgozást. Egy olyan classot használni ami már megvan írva, szükségelteti, hogy megértsük
			a public interfészét, és nem azt, hogy hogyan mükődik a felszín alatt. A tag funkció beépítésének a részletei pont
			útban állnak.

	Szerencsére, a C++ biztosít egy útat arra, hogy szétválasszuk a "meghatározás" részét a classnak a "beépítés" részétől.
		Ezt úgy tesszük, hogy meghatározzuk a class tag funkcióit a classon kivül, ahhoz, hogy ezt tegyük simán meghatározzuk
		a tag funkciókat a classnak úgy mintha normál funkciók lennének, de előtagba a scope resolution operátorral(::) odahelyezzük
		a class nevét.

		lásd pl. 1) minden a classban
				 2) a tag funkciók a classon kivül.
				 3) ráadás példa

*/


/*

Putting class definitions in a header file,
	A class meghatározásokat belehet rakni egy header fájlba így elősegítve az újrafelhasználhatóságot.
		Hagyományosan, a class meghatározások kerülnek egy header fileba úgyanazon néven mint a class,
			és a tag funkció meghatározódnak a classon kivül egy külső cpp fájlba úgyanazon a néven mint a class.

*/


/*

What should I define in the header file vs the cpp file, and what inside the class definition vs outside?
	Csábító lehet, hogy minden tag funkció meghatározást a header fájlba tegyél, a classon belül.
	Ez úgyan lefog compileolni, de van néhány hátulütője. 
		Először, ez telezsúfolja a class meghatározásodat.
		Másodszor, olyan funkciók amelyek a classon belül vannak meghatározva magától értetődöen 'inline'-ok.
			Amik nagy funkciók esetében amiket sok helyről hívnak le, felduzzaszthatja a kódodat.
		Harmadszor, ha bármit megváltoztatsz a kódodban a header fájlban, az összes fájlt újra kell compileolj ami használja
			azt a headert. Ha a kódot a .cpp fájlban módosítod, csak a .cpp fájlt kell újra compileold.


	Azaz:
		- olyan classok esetében amik egyetlen fájlban lesznek használva, és nem igazán újrahasználhatók, határozz meg mindent
			a .cpp fájlban ahol a classt is használják.
		- olyan classok esetében amelyeket több fájlban használnak, vagy általános újrahasználhatóságra törekszel,
			határozd meg őket a .h fájlban ami úgyan azt a nevet használja mint a class.
		- Jelentéktelen tag funkciók(jelentéktelen konstruktőrök, destruktőrök, elérhetőségi funkciók, stb.) meghatározható a classon
			belül.
		- Nem-jelentéktelen tag funkciók egy .cpp fájlban kellene meghatározva legyenek aminek úgyan az a neve mint a class.


		! alapértelmezett paramétereket a tag funkciókhoz a class meghatározásban(a header fájlban) határozunk meg, ahol
			látható bárki számára aki #includeolja a headert.


			lásd az egészet a tanulas89pelda.sln-be.

*/