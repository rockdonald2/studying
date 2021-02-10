#include "pch.h"
#include <iostream>

/*

A kivételek három kulcsszóval vannak beépítve amelyek kapcsolatba állnak egymással: throw, try, catch

*/

/*

Throwing exceptions,
	a throw állítást arra használjuk, hogy jelezzük, hogy egy kivétel vagy error jelent meg
	ahhoz, hogy használjuk ezt az állítást használjuk a 'throw' kulcsszót követve azzal az értékkel bármely adattípusból amellyel jelezni akarod, hogy error jelent
		meg.
		- általában ez lehet egy error kód, vagy egy leírás a problémáról, vagy egy saját exception class
			lásd pl.

*/

/*

Looking for exceptions,
	a kivétel dobás csak az egyik része a kivétel kezelési folyamatnak, 
	a 'try' kulcsszót használjuk arra, hogy meghatározzunk egy állítás blokkot(try block)
		- ez a blokk úgy viselkedik mint egy figyelő, aki kivételeket keres amiket majd dob bármelyik állítás a try blokkon belül.
			lásd pl.

*/

/*

Handling exceptions,
	a kivételek kezelése a catch blokk feladata
	a 'catch' kulcsszót használjuk arra, hogy meghatározzunk egy catch blokkot amely kezeli a kivételt egyetlen adattípusra nézve.
		lásd pl.

		! a try blokk és catch blokk együtt mükődik -- a try blokkot észlelnek bármilyen kivételt amiket majd az állítás dob a try blokkon belül,
			aztán ez a megfelelő catch blokkhoz írányítja kezelésre.

		! szigorúan minden try blokk után legalább egy catch blokk kell legyen, de lehet több is egymás után

		Miután egy kivételt elkap a try blokk és a megfelelő catch blokkhoz irányítva kezelve is van, a kivételt kezeltnek lehet tekinteni,
			és a kód végrehajtódása folytatodik normálisan a catch blokk után

*/

/*

Mit csinálnak általában a catch blokkok,
	ha üres a catch blokk akkor is "kezelt"-nek van nyílvánitva a kivétel, de gyakorta a catch blokkok errort üzenetet írnak ki(console vagy log fileba),
		visszaadnak egy értéket, vagy error kódot a hívónak, vagy a catch blokk egy másik kivétel dob(ez esetben nem az eredeti(megelőzö), hanem a következő try
			blokk kezeli)

*/