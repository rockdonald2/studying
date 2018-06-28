#include "stdafx.h"
#include <iostream>

/*

Constructors,
	amikor egy class vagy struct minden tag változója publikus, képesek vagyunk őket inicializálni listával, vagy uniform-al.
		De, mikor a tag változók privátak nem vagyunk képesek ilyen módon inicializálni őket.
		Ekkor konstruktőröket kell használnunk.

	A konstruktőr egy különleges típusú class tag funkció amely automatikusan levan hívva amikor egy abból a classból származó
		objectet alkotnak. Általában arra használják, hogy tag változókat inicializáljanak a megfelelő alapértékre, vagy
		felhasználó által biztosított értékre, vagy végezzen el minden szükséges előkészűleti lépést ahhoz, hogy a classot
		használhassuk.
		
			! Meghatározott szabályai vannak annak, hogy hogyan lehet ezeket elnevezni:
				1) Muszáj úgyanaz legyen a nevük mint a classnak.
				2) A konstruktőröknek nincs return típus.(még void sem)

*/


/*

Default constructors,
	egy olyan konstruktőr amelynek nincsenek paraméterei(vagy minden paraméterhez van szolgáltatva egy alapérték) alapértelmezett
		konstruktőröknek nevezzük. Ez a konstruktőr van lehívva ha nincs felhasználó által szolgáltatott érték.
			lásd pl.

Direct and uniform initialization using constructors with parameters,
	miközben az alapértelmezett konstruktőr megfelelő abból a szempontból, hogy a változóinkat megfelelő alapértékkel biztosítsuk,
		gyakran olyan példányokat is létre akarunk hozni az adott classból amelyben vannak meghatározott értékek amiket mi szolgáltatunk.
		Szerencsére, létre lehet hozni olyan konstruktőröket amelyek paramétereket fogadnak be.
			lásd pl.

			! megfigyelhető, hogy most a classunknak két konstruktőre van.
				ez a funkció overload miatt lehetséges.
				! akárhány konstruktőrrel rendelkezhet a classod, addig amíg minden egyes konstruktőrnek van egy sajátos jegye,
					más számú, más típusú paraméterek.
*/


/*

Copy initialization using equals with classes,
	int x = 6; // Copy initialize an integer
	Fraction six = Fraction(6); // Copy initialize a Fraction, will call Fraction(6, 1)
	Fraction seven = 7; // Copy initialize a Fraction.  
						The compiler will try to find a way to convert 7 to a Fraction, which will invoke the Fraction(7, 1) constructor.


		! ezt a fajta módszer kerüld el classok esetében.
*/


/*

Reducing your constructors,
	a jelenlegi alapértelmezett konstruktőr jelentéktelen.
		Amikor konstruktőröket határozol meg, épitesz be a programodba, mindig okosan mérd fel hogyan tudod lecsökkenteni
			a konstruktőrök számát okos alapértékek biztosításával.
				lásd pl.


A reminder about default parameters,
	lásd neten.

		lényeg az, hogy amikor alapértéket használsz, sohasem ugorhatod át a legbaloldalibb értékét.
			pl. ha van egy funkció amely használ int (int, double) paraméter csoportot, nem szolgáltathatsz double értéket,
				int nélkül mert error-t kapsz.
				erre használhatsz egy másik konstruktőr default érték nélkül, double paraméterrel.


An implicitly generated default constructor,
	Ha a classod nem tartalmaz más konstruktőrt, C++ automatikusan generálni fog egy publikus alapértelmezett konstruktőrt neked.
		Ezt hívják magától értetődö konstruktőrnek.

		! szabály, mindig biztosíts legalább egy konstruktőrt a classodhoz, még akkor is ha az egy üres alapértelmezett konstruktőr.


Classes containing classes,
	classok tartalmazhatnak más classokat tag változókként.
		Amikor a külső class létrejön, a tagváltozók lehívják az alapértelmezett konstruktőrjeiket.
		Ez azelőtt jön létre, hogy a konstruktőr body-ja végrehajtódna.
			lásd pl.
*/