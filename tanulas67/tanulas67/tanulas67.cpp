#include "stdafx.h"
#include <iostream>

/*

Az address-of operátor(&),
	az address-of operátort lehetőséget ad, hogy megnézzük melyik memória címen található meg az adott változó.

*/

/*

A dereference operátor(*),
	a dereference operátor lehetőséget ad, hogy elérjünk egy értéket egy adott címen.
*/


/*

A pointerek, azaz mutatók,
	a mutató egy változó ami tartalmazza a memória címet mint értéket.
		a mutatókat gyakran tekintik a C++ egyik legnehezebben értelmezhető dolgának, pedig nagyon egyszerű ha rendesen elmagyarázzák.

*/


/*

Meghatározni egy mutatót,
	egy mutatót úgy határozunk meg mint egy normális változót, csakhogy használunk egy csillagot az adattípus és a változónév között.
		pl. int *iPtr; // egy mutató int értékre
			double *dPtr; // egy mutató double értékre.

				akár lehet tenni az adattípus mellé, vagy kettő közé.
				amikor több mutató hozunk létre egyszerre akkor mindegyik mellett ott kell legyen.
					! legjobb gyakorlat, ha amikor változóhoz hozunk létre mutatót akkor a név mellé rakjuk.
					! legjobb gyakorlat, ha amikor funkcióhoz hozunk létre mutatót akkor az adattípus mellé rakjuk.
		
*/


/*

Érték hozzárendelése egy mutatóhoz,
	mivel a mutatók csak memória címeket tartalmazhatnak, amikor hozzárendelünk egy értéket egy mutatóhoz, az érték egy cím kell legyen.
	a legegyszerűbb ha egy különböző változó memória címét rendeljük hozzá.

		! fontos, a mutató típusa megkell egyezzen azzal a változó típusával amelyre mutat.
		! egy mutatóhoz nem lehet számot hozzárendelni, sem konkrét memória címet.

*/


/*

Az address-of operátor egy mutatót ad vissza,
	fontos megjegyezni, hogy az address-of operátor nem a címét adja vissza hanem egy mutatót a címére az adott változónak, aminek
		a típusa megjegyezik a lekért változó típusával.

*/


/*

Dereferencing pointers,
	amiután már megvan a mutatók ami mutat valamire, a másik gyakori dolog amit csinálni szoktak, hogy meg dereference-lik a mutatót
		hogy lekérjék az értékét annak amire mutat.
			Egy dereferenced pointer értéke abból származik amit tartalmaz egy adott memória cím.

*/

/*

Miután hozzárendeltük, egy mutató értékét újra hozzá lehet rendelni egy másik értékhez,
	int value1 = 5;
	int value2 = 7;
 
	int *ptr;
 
	ptr = &value1; // ptr points to value1
	std::cout << *ptr; // prints 5
 
	ptr = &value2; // ptr now points to value2
	std::cout << *ptr; // prints 7

		ebben az esetben a ptr-re a következő igazak:
			ptr ugyanaz mint a &value
			*ptr ugyanúgy van kezelve mint a value

		Mivel a *ptr ugyanúgy van kezelve mint a value, ezért úgyanúgy lehet hozzá értékeket rendelni mint ha egy sima változó érték lenne.
*/


/*

Érvénytelen mutatók dereference-e,
	a mutatók eredendően nem biztonságosak, és a nem megfelelő mutató használhat a legjobb út, hogy crasheld a programot.

	Amikor egy változót dereference-lünk, akkor a program megpróbál hozzáférni a memória helyhez ami hozzá van rendelve a mutatóhoz,
	és lekérni a benne levő memória tartalmat. Biztonsági okokból a modern operációs rendszerek sandbox applikációi ahhoz, hogy 
	megakadályozzák, hogy nem megfelelően hassunk más applikációkkal, és hogy megvédjék az operációs rendszer stabilitását.
	Amikor egy applikáció megpróbál hozzáférni egy memória helyhez ami nem volt hozzárendelve az operációs rendszer által,
	az operációs rendszer leállítja a programot.

*/


/*

Egy mutató mérete,
	egy mutató mérete attól függ, hogy milyen architekturát használ az adott executable file compileloláskor,
		egy 32-bit-es executable 32-bites memória címet használ - így egy mutató egy 32-bit gépen 32bit azaz 4byte.
		egy 64bit-es executable 64-bites memória címet használ - így egy mutató egy 64-bit gépen 64bit azaz 8byte.

		ez mindig igaz, nem számít, hogy mire mutat.

		! ez azért igaz mindig, mert a mutató csak a memória címet használja, és a bitek száma amit felhasznál, hogy elérje
		az adott memória címet egy adott gépen mindig állandó.

*/


/*

Mire használhatók a mutatók?
	1, az arrayok a mutató segítségével vannak beépítve a nyelvbe.
		a mutatókat használhatjuk, hogy végigismételjünk egy arrayt ( mint egy alternatíva az indexek helyett ).
	2, ez az egyetlen út arra, hogy dinamikusan rendeljünk hozzá memóriát valamihez a C++-ban.
		ez a leggyakoribb használati módja
	3, felhasználható, hogy nagy mennyiségű adatot adjunk át egy funkcióba, egy olyan úton ami nem foglalja magába, hogy az egész
		adatot átmásoljuk.
	4, felhasználható, hogy átadjunk egy funkciót mint paraméter egy másik funkcióba
	5, felhasználható, hogy elérjünk egy polymorphism-et, amikor inheritence-el foglalkozunk.
	6, felhasználható arra, hogy egy struct/class rámutasson egy másik struct/class-re, hogy létrehozzon egy láncot.
		ez hasznos amikor egy összetetebb adat strukturákkal dolgozunk, mint linked listák, vagy trees.

*/


/*

konkluzió,
	egy mutató tartalmazza egy adott változó memória címet. Lehet a mutatókat dereference-ni ami visszaadja az értéket annak a címnek
		amit tartalmaz. Ha rossz értéket dereference-elsz akkor crashel a programod.

		! legjobb gyakorlat, amikor a mutató egy változóra mutat, hogy a csillagot a változó név mellé rakod.
		! legjobb gyakorlat, amikor a mutató egy funkcióra mutat, hogy a csillagot az adattípus mellé rakod.

*/