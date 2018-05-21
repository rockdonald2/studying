#include "stdafx.h"
#include <iostream>

/*

Pointers and consts,
	egy olyan mutató amely egy konstans értékre mutat az egy non-konstans mutató.
		ahhoz, hogy létrehozzunk egy ilyent használjuk a const kulcsszót az adattípus előtt.
		ez akár mutathat egy konstans értékre, de mutathat egy nem konstans értékre, ez esetben csak akkor modósítható az adott érték
			ha egy non-konstans azonosítón keresztül érjük el, és nem a non-konstans mutatón keresztül.
		úgyanakkor a mutató módosítható, hogy más értékre mutasson bármikor.
			séma: const adattípus *mutatóneve = &változó;

	egy konstans mutató egy olyan mutató amelynek az értéke inicializálás után nem modosítható.
		ahhoz, hogy egy ilyent hozzunk létre használjuk a const kulcsszót a * és az mutató neve között
			séma: adattípus *const mutatóneve = &változó;

				ez esetben ugye nem módosítható a mutató arra vonatkozóan, hogy más címre mutasson,
					de dereferencelés esetén az értéke igen, de csakis akkor ha non-konstans értékre mutat.

		de ugye lehetséges, hogy egy konstans mutató egy konstans értékre mutasson, ez esetben sem a mutatót, sem az értéket nem lehet
			utólag megváltoztatni.
		
*/


/*
Összefoglaló:
	egy nem konstans mutatót átlehet irányítani más címre.
	egy konstans mutató mindig ugyanarra a címre fog mutatni, és ezt nem lehet megváltoztatni
	egy olyan mutató amely egy non-konstans értéke mutat megváltoztathatja az értéket a mutatón keresztül. Ezeket nem használhatjuk konstans
		értékek esetében.
	egy olyan mutató amely egy konstans értékre mutat úgy kezeli az értéket mintha konstans lenne, akkor is ha nem az, azaz nem változtathatja
		meg azt az értéket amire mutat.

			int value = 5;
			const int *ptr1 = &value; // ptr1 points to a "const int", so this is a pointer to a const value.
			int *const ptr2 = &value; // ptr2 points to an "int", so this is a const pointer to a non-const value.
			const int *const ptr3 = &value; // ptr3 points to a "const int", so this is a const pointer to a const value.

*/