#include "stdafx.h"
#include <iostream>

/*

pointerek és arrayek,
	egy array változó tartalmazza az első elem címet, mintha egy mutató lenne.

		de tévedés, hogy egy array és egy arrayra mutató mutató ugyan az lenne.
			Mindketten az első elem címére mutatnak, de két eltérő információt tartalmaznak.
				egy array típusa "int [hossz]", míg egy arrayra mutató mutató típusa "int *"

					egy mutató által ellehet érni egy array összes elemét,
					 de egy mutató típusa által nem lehet meghatározni egy array hosszát.

			! de a legtöbb esetben lehet azonosnak tekinteni a kettőt
				pl. használhatjuk a dereference operátort(*), hogy lekérjük az első elem értékét.
							- de ilyenkor nem magát az array dereferenceljük,
								az array ( int[hossz] ), magától átalakítodik egy mutatóvá ( int * ) ,
									és azt a mutatót dereferenceljük, hogy megkapjuk azt az értéket amit a mutató címe tartalmaz.

					ez által akár hozzárendelhetünk egy mutatót egy arrayhoz.
						pl.
							int main()
							{
								int array[5] = { 9, 7, 5, 3, 1 };
									std::cout << *array; // 9-et fog kiirni
								int *mutato = array;
									std::cout << *mutato; // 9-et fog kiirni

								return 0;
							}
*/


/*

A különbség a mutató és a fix hosszúságú array között,
	az első ilyen különbség a sizeof() operátor esetében jelentkezik,
		amikor fix arrayen használjuk a sizeof visszaadja az egész array méretét, azaz az adattípus mérete szorozva az array hosszával
		amikor mutatón használjuk a sizeof visszaadja a memória cím méretét byte-ban( 32bit 4byte, 64bit 8byte )

	egy fix array tudja, hogy milyen hosszú az az array amire mutat, egy mutató nem.

	a második különbség az address-of operátor (&) esetében jelentkezik,
		amikor egy mutatóra használjuk az address-of-t a mutató változó címét adja vissza
		amikor egy array-re visszaad egy mutatót az egész arrayre.

*/


/*

fix array átadása funkcióhoz,
	amikor egy funkcióhoz adunk át paraméterként egy arrayt, nem a teljes array lesz átadva, hanem csak egy mutató.

		! amikor átadsz, használd inkább a mutató sémát az arrayhoz ( *arraynév ), mint az array sémát ( arraynév[] )

*/

/*

Bevezetés a cím szerinti átadáshoz,
	tény, hogy egy array leépül egy mutatóvá mikor továbbadódik mint paraméter egy funkcióba,	
		és ez megmagyarázza mért változik meg a rendes array is mikor egy funkció megváltoztassa az átadott arrayt.

*/

/*

olyan arrayok amelyek structsokhoz vagy classokhoz kapcsolódnak nem épülnek le amikor egy struct vagy class
	adódik át egy funkcióhoz.
		Ez egy hasznos mód arra, hogy megakadályozzuk egy array leépülését mutatóvá.

*/
