#include "stdafx.h"
#include <iostream>

/*

Egy érvet továbbadni cím alapján azt jelenti, hogy
	sokkal inkább a változó, vagyis az adott érv, címét adjuk tovább mintsem magát a változót.
		így az érv egy cím lesz, azaz a paraméter maga muszáj, hogy egy mutató legyen.
			Aztán majd a funkció dereferencelheti, hogy elérje, vagy megváltoztassa az adott értéket amire mutat.

	A cím szerinti továbbadást legtöbbször mutatóval használják, és a mutatót legtöbbször built-in arrayekkel.
		lásd pl.
		! fontos, mivel az array leépül egy mutatóvá, így nem tárolja már az információkat, ezért kell külön paraméterként
			a hosszát is továbbadni.

			!! mivel, egy null mutató dereferencelése crash-t okoz, ezért jobb beépíteni egy check-et.
				 lásd pl.

Konstans cím általi továbbadás,
	mivel a kiIrArray() funkció nem kell megváltoztassa egyik érvét sem, ezért legjobb konstanssá tenni őket.


A címek érték alapján vannak továbbadva,
	Amikor egy mutatót adsz tovább cím alapján, akkor a mutató értéke másolódik bele a paraméterbe,
		másszóval érték alapján adódik tovább,
			ha megváltoztatod a funkció paraméter értékét, csak a másolatot változtatod meg.
				azaz, az eredeti mutató érv nem lesz megváltozva.

				! de úgyanúgy tudod dereferencelni, majd megváltozatni az érv értékét. lásd első pl.

		kicsit zavaros tehát:
			Amikor továbbadsz egy érvet cím alapján, akkor a funkció paraméterbe belemásolódik a cím
				ekkor a paraméter és az érv is úgyanarra a címre mutat.
			Ha dereferenceled a paramétert majd megváltoztatod az értéket amire mutat, akkor az eredeti érték is megváltozódik.
			Ha más címre irányítod az nem fogja befolyásolni az eredeti érv értékét.

			! lásd első és harmadik példa.


Címet továbbadni hivatkozás által,
	ha az érv címet megakarod változtani egy funkción belül, akkor csak simán a címet hivatkozás alapján adod tovább.
	! lásd negyedik példa.

*/


/*

Előnyei:
	- a cím általi továbbadáskor, lehetséges a funkciónak, hogy megváltoztassa az érvet,
		ha nem akarod konstans.
	- mivel nincs másolási technika, ezért gyors, még structok és classok esetében is.
	- több változó return.

Hátrányai:
	- muszáj normál változók legyenek
	- minden értéket lekell checkelni, hogy ne legyen null.
	- mivel egy mutatót dereferencelni kell, hogy elérjük az értékét ezért ez lassabb mint az érték általi továbbadás.

Mikor használd?
	amikor arrayt adsz tovább
	amikor a mutató/nullptr egy logikailag helyes érv.

Mikor ne?
	amikor a mutató/nullptr egy logikailag helytelen érv.
	amikor structot vagy classot adsz tovább(hivatkozás)
	amikor alapvető adattípust adsz tovább(érték általi)

*/