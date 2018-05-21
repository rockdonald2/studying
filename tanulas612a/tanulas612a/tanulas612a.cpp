#include "stdafx.h"
#include <iostream>

/*

A for loopok biztosítanak egy kényelmes és rugalmas megoldás arra, hogy végig ismételjünk egy arrayt,
	de könnyen elronthatjuk őket off-by-one errorokkal.

C++11 biztosít egy új fajta loopot, a for-each loopot, ami biztosít egy egyszerűbb és biztonságosabb módot arra, hogy végig
	ismételjük egy array elemeit.(vagy más listaszerű struktúrát)

*/


/*

For-each loop,
	
	sémája:

		for (elem_meghatározás : array)
			állítás;


		Amikor egy ilyen állítás megjelenik a programban, a loop végig ismételi az összes array elemet, és közben hozzárendeli
			a jelenlegi array elem értékét ahhoz a változóhoz amit az elem_meghatározás-ban létrehoztunk.
			Legjobb eredmény érdekében az elem_meghatározás-ban szereplő változó típusa úgyanaz legyen mint ami az array típusa

		! lásd példa

*/


/*

For each loop, és auto kulcsszó,
	lehet használni az auto kulcsszó, hogy a C++ eldöntse melyik adattípus a megfelelő az elem_meghatározás-ban szereplő változónak
		szóval mindig az array típusát fogja választani.
	

*/


/*

For each loop, és a hivatkozások,
	minden esetben amikor a for-each loop megismétlődik, az elem_meghatározás-ban levő változó egy másolata lesz az eredeti array elemnek
	ez sokszor nem jó, mivel túl drága, így hivatkozás által elérhetjük, hogy az elem_meghatározás-ban levő változó csak egy hivatkozás
	legyen az eredeti array elemre.
		! jó ötlet konstans-á tenni mert így csak olvasható tehetjük, ha nem akkor bármilyen változás egy elemben megváltoztatja az
		ismételt arrayt is.

		! szabály, használj hivatkozást az elem_meghatározás-ban teljesítmény okok miatt.
*/

/*

fontos megjegyezni, hogy a for-each loopok nem mükődnek mutatókkal, így pl. ha egy funkciód tartalmaz egy for-each loopot
	és a funkció az arrayt paraméterként kapja, akkor nem fog mükődni, mert ez esetben az array leépül mutatóvá.

	Emiatt a dinamikus arrayek sem fognak mükődni ezzel a loopal.

*/