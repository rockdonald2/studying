#include "pch.h"
#include <iostream>

/*

Vegyük alapul a példát,
	megismertük ugye, hogy lehetséges Base hivatkozást vagy mutatót hozzárendelni egy Derived objecthez,
		ekkor pár dolgot érdemes észben tartani:
			- a Base típusú mutató/hivatkozás a Derived objectre csak a Derived object Base részét képes látni,
				a másik rész is ott van, de az elérhetetlen/láthatatlan a Base mutatón/hivatkozáson keresztül
			- azonban a virtuális funkciókon keresztül mégis elérhető egy Base és egy Derived között létező legszármaztatotabb
				funkció


		Azonban felmerül egy kérdés, mi történik akkor amikor nem használunk mutatót/hivatkozást, hanem csak simán
			egy hozzárendelünk egy Derived objectet egy Base objecthez.
			- érdekes dolog, ez esetben egy egyszerű másolás történik, mivelhogy egy Derived object két részből áll
				( base + derived ), a base része a derived objectből átmásolódik az új base objectbe, azonban a derived
					része nem.
				! ez azt jelenti, hogy levágódik a Derived része, ezt hívjuk object slicing-nak.
				

	Lelkiismeretesen használva az object slicing jó lehet, azonban helytelenül nem várt gondokhoz vezethet.


Slicing and functions,
	gondolnád, hogy az előzö példa hülyeség, mivel miért másolnál bele egy derived objectet egy basebe?
		- azonban ez így valóban ritkán fordul elő, de funkciókkal annál gyakoribban.
		lásd pl.
			- ahol a pritName() funkcióban pass by value érvényesül, így a fentebb említett másolós történet jelenik meg.
			- ez esetben nincs virtualizáció, és a Base::getValue()-re fog mindig megoldódni a hívás, mivel nincs Derived rész.

			! azonban a fenti probléma megoldható ha a paraméter hivatkozás.


Slicing vectors,
	egy újabb hiba amit az új programozók el szoktak követni a polimorfizmus beépítése vectorba.
		- lásd pl.
		- a másolós történet itt is, nincs virtualizáció.

		! azonban ez a probléma is megoldható, ez esetben mutató típus használatával, de ilyenkor muszáj a memória
			felszabadítással is foglalkozni.
			lásd pl.
			
		! de megoldható egy sokkal barátságosabb megoldással is az std::reference_wrapper hivatkozással.
			- ez egy class ami úgy viselkedik mint egy hivatkozás, de megengedi a másolást, és hozzárendelést
				nem úgy mint egy hagyományos hivatkozás, szóval kompatibilis az std::vectorral.
			! három dolgot kell ezzel kapcsolatban megjegyezz:
				1) az std::reference_wrapper a <functional> headerben található meg
				2) mikor létrehozod az std::reference_wrapper objectet az nem lehet anonymous object.
				3) amikor le akarod kérni az objectet a get() funkciót használod


The frankenobject,
	ez egy újabb veszélyes eset ahol a derived object még mindig létezik.

	a harmadik sorig minden rendben van, létrehozunk két Derived objectet és egy Base hivatkozást a második objectre.
	a negyedik sortól problémás, ekkor ugye a b hivatkozik a d2 base részére, a d2 derived részét érintetlenül hagyva.
		ekkor belemásolódik a d1, akkor majd a b hivatkozik a d1 base részére(mivel belemásolódott), és a d2 derived részére.

		ez egy frankenobject, mivel egy object több object részéből tevődik össze.

Conclusion,
	probáld elkerülni származtatott classok esetében a hozzárendelést(object slicing), és mindig amikor lehet hivatkozást használj funkció
		paraméterként ugyancsak származtatott classok esetében.

*/