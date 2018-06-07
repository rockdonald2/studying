#include "stdafx.h"
#include <iostream>

/*

Return by value,
	az érték szerinti visszaadás az egyik legegyszerűbb és legbiztonságosabb a használathoz.
		egyszerűen a visszaadott érték egy másolata lesz visszaadva a hívónak.
			ilyen módon visszatudsz adni a hívónak változókat, számokat, vagy akár kifejezéseket is.

	egy újabb előny, az ,hogy ez esetben amikor változókat vagy kifejezéseket adsz vissza, nem kell aggódnod a scoping
		hiba miatt. Mivel a változó hamarabb jön létre és lesz visszaadva mint ahogy a változó megsemmisül.

	az érték szerinti visszaadás a legmegfelelőbb amikor olyan változókat adunk vissza ami a funkción belül jött létre,
		vagy olyan érveket amelyek érték alapján voltak átadva. De úgyanúgy lassú structok/classok esetében.

		Mikor használd?
			amikor olyan változókat adsz vissza ami a funckión belül jött létre
			amikor olyan érveket adsz vissza ami érték alapján volt átadva.

		Mikor ne?
			amikor built-in arrayeket, vagy mutatókat adsz vissza(return by address)
			amikor nagy structokat vagy classokat adsz vissza(return by reference)

*/


/*

Return by address,
	a cím szerinti visszaadás magába foglalja egy adott változó címének visszaadását a hívónak.
		hasonlóan a cím szerinti továbbadáshoz, a cím szerinti visszaadás csakis változót tudsz visszaadni,
			nem tud sem kifejezést, sem számot.
				de gyorsabb mint az érték szerinti visszaadás.

	úgyanakkor, a cím szerinti továbbadásnak van egy hátulütője, ha egy helyi változót akarsz visszaadni cím szerint
		határozatlan viselkedést kapsz.
			ez esetben mivel a változó kimegy scopeból, egy olyan címet fog visszaadni a hívónak ami már nincs elosztva,
				így létrehozva egy lógó mutatót.

	Mikor használd?
		amikor dinamikusan elosztott memóriát adsz vissza
		amikor olyan érvek adsz vissza ami cím alapján volt továbbadva

	Mikor ne?
		amikor olyan változókat adsz vissza ami a funkción belül lett meghatározva(return by value)
		amikor nagy structokat vagy classokat adsz vissza ami hivatkozás által volt továbbadva(return by reference)

*/


/*

Return by reference,
	hasonlóan a cím szerintihez, hivatkozás által csakis változót tudsz visszaadni.
		amikor egy változót hivatkozás alapján adunk vissza, a változóra mutató hivatkozás lesz visszaadva a hívónak.
		a hívó ezután használhatja ezt a hivatkozás arra, hogy tovább modosítsa a változót, ami hasznos lehet.
			gyors, ezért megfelelő nagy structokhoz, vagy classokhoz.

		! de ezt sem szabad helyi változó visszaadására.

	tipikusan arra használjuk, hogy olyan érveket adjunk vissza ami hivatkozás által volt továbbadva.
		lásd pl.

	Mikor használd?
		amikor hivatkozás paramétert adsz vissza
		amikor egy array elemeit adod vissza amit továbbadtak a funkciónak
		amikor nagy structokat vagy classot adsz vissza, olyant ami nem semmisül meg a funkció végén

	Mikor ne?
		amikor olyan változót adsz vissza ami a funkción belül jött létre(return by value)
		amikor built-in arrayt, vagy mutatót adsz vissza(return by address)

*/


/*

Mixing return references and values,
	lásd pl. és füzet

*/


/*

Returning multiple values,
	volt egy módszer a 7.3 leckében is, ez nem megfelelő
	
	még egy módszer data-only struct által
		lásd pl.

	harmadik módszer, úgy rendezd át a kódodat, hogy a visszaadni kivánt elemeket egyesével tud visszaadni.
	 (ahelyett, hogy egy funkciónak kellene két értéket visszaadni, csinálj két funkciót egy-egy return értékkel).

	 negyedik módszer, std::tuple ( <tuple> ), egy tuple az egy elemek sorozata ami akár lehet különböző típusból,
		amelyben mindegyik elem típusa kifejezetten meg kell legyen határozva.
			lásd pl.
*/