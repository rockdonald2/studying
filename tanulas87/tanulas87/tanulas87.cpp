#include "stdafx.h"
#include <iostream>

/*

Destructors,
	egy újabb különleges típusú class tag, amely akkor hajtódik végre amikor egy class object megsemmisül.
		amíg egy konstruktőr arra szolgáltatott, hogy inicializálja a classot, a destruktőrök segítenek feltakarítani.

	amikor egy object kimegy a scopeból, vagy egy dinamikusan elosztott object kitörlődik kifejezetten a 'delete' kulcsszóval,
		a class destruktőr automatikusan lehívódik(ha létezik), hogy elvégezzen minden szükséges takarítást mielőtt az object
			kitörlödne a memóriából. 
			Egyszerű classok esetében, a destruktőr nem szükséges, mivel a C++ automatikusan elvégzi a takarítást számodra.
			Azonban olyan classok amelyek dinamikus memóriával dolgoznak, vagy adatbázisokkal esetleg fájlokkal, ha szükséges
				neked, hogy elvégez bármilyen karbantartást mielőtt az object törlödne, a destruktőr a tökéletes dolog erre,
				mivel általában ez az utolsó dolog ami végrehajtódik mielőtt az object törlödne.


Destructor naming,
	ahogy a konstruktőröknek úgy a destruktőröknek is van sajátos elnevezési szabályai:
		- a destruktőr neve a class neve megelőzve egy ~-el.
		- nem fogadhat be semmilyen érvet
		- nincs return típusa

		! a második szabály az feltételezi, hogy classokként egyetlenegy destruktőr létezhet, mivel így nem lehetséges overloadolni.
		általában nem szabadna neked kifejezetten lehívnod a destruktőrt(hiszen ez automatikusan történik),
			azonban a destruktőrök lehívhatják a többi tag funkciót, mivel az object nem lesz törölve a destruktőr végéig.


Destructor example,
	lásd pl.


Constructor and destructor timing,
	a konstruktőr akkor hívódik le amikor egy object létrejön, a destruktőr pedig amikor megsemmisül.
		lásd pl, ami bemutatja ezt.


RAII,
	Resource Acquisition is Initialization,
		egy programozási technika amely alapján minden erőforrás használat össze van kapcsolva az object élettartamával automata
			durationnel(pl. nem dinamikusan elosztott objectek).
		a C++-ban a RAII bevan építve classok alapján destruktőrökkel és konstruktőrökkel.
		az erőforrás(memória, fájl, adatbázis kezelés, stb.) általában megszerzett az object konstruktőrjében.
		az erőforrás fel lesz szabadítva a destruktőrben, amikor az object tőrlödik.
		az elsődleges előnye a RAII-nak, az, hogy segít elkerülni az erőforrás lékeket(nem szabadítjuk fel a memóriát pl.),
			mivel az összes erőforrást tartalmazó object automatikusan takarítódik.

		a RAII paradigma alatt, az olyan objectek amelyek erőforrást tartalmaznak nem kellene, hogy dinamikusan elosztva legyenek.
			ez amiatt van mert a destruktőrök csak akkor vannak lehívva amikor egy object megsemmisül.
			a rakáson található objecteknél ez automatikusan történik.
			azonban dinamikusan elosztott objectek esetében, a felhasználó felelős ezért, ha elfelejti megtenni erőforrás és a
				memória a class objecthez is elvesztődik.

		! szabály, ha a classod dinamikusan eloszt memóriát, használd a RAII paradigmát, és ne osszd el a classod objectjeit
			dinamikusan.


		! megjegyzés,
			amikor használod az exit() funkciót, a programod azonnal leáll, és nem lesz semmilyen destruktőr lehívva.
*/