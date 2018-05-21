#include "stdafx.h"
#include <iostream>

/*

Dinamikus memória elosztás,
	miért van szükség erre?
		A c++ három fajta memória elosztást támogat:
			statikus, automatikus, és dinamikust.

				a statikus a statikus és globális változók esetében találkozhatsz, a memória az ilyen típusú változókra elosztódik amikor
					a program fut, és úgy is marad az egész programon keresztül.
				az automatikus esetében akkor foglalódik le a memória amikor először megjelenik, és akkor törlődik amikor kilép az
					adott scope-ból. Annyiszor ahányszor szükséges.

						- két közös jellemzőjük van ezeknek a memória elosztás típusoknak:
							a változó / array mérete ismert kell legyen compile idején
							a memória lefoglalás és felszabadítás magától történik.

		a legtöbb normál változó vagy fix array a memóriát egy úgynevezett "rakás"ból(stack) foglalja le magának.
			ez nagyon kevés, a Visual Studio esetében olyan 1MB, efölött a program leáll.
		a dinamikus elosztás esetében a program kér memóriát az operációs rendszertől amikor szükség van rá.
			a memória nem a program limitált stackjéből származik, hanem a sokkal nagyobból amit az operációs rendszer kezel,	
				és úgy hívják, hogy halom(heap). Az akár több gigabyte is lehet.

*/


/*

Dinamikusan elosztani egyedüli változót,
	ahhoz, hogy elhelyezzünk egyedüli változót dinamikusan használjuk a new operátort:
		new int; // dinamikusan elhelyez egy integert

	ahhoz, hogy később is elérjük az adott memória címet amit félretett nekünk az operációs rendszer használhatunk egy mutatót:
		int *mutato = new int; // dinamikusan elhelyez egy integert, majd a mutatóhoz hozzárendeli a címét, hogy később elérhessük.

*/


/*

Hogyan mükődik a dinamikus elosztás?
	a gépek általában rengeteg memóriát tartalmaznak amit felhasználhat bármely applikáció.
	amikor futtatsz egy applikációt az operációs rendszer beolvassa az applikációt a memória egy részébe.
		Az a memória amit az applikáció használ több részre osztódik, mindegyik más célt szolgál:
			egy része tartalmazza a kódot, másik része a müveleteket(nyomon követi melyik funkciót hívják le, létrehoz és töröl
				globális vagy helyi változókat, stb).

	amikor dinamikusan elosztod a memóriát, arra kéred az operációs rendszert, hogy tegyen félre némi memóriát, hogy a programod használhassa.
		ha képes teljesíteni ezt a kérést, visszaadja annak a memóriának a címet amely a programodnak van garantálva.
		ettől a ponttól a programod úgy használhatja azt a memória darabkát ahogy akarja.
		amikor végzett vele, visszaadhatja a rendszernek, hogy más programok használhassák.

			! nem úgy mint a statikus, vagy automatikus elosztás esetében, a program felelős azért, hogy lekérje, és visszaadja
			a dinamikus elosztott memóriát.

*/


/*

Dinamikusan elosztott változók inicializálása,
	használhod a direct initializationt, vagy uniform initializationt:
		int *mutato1 = new int (5);
		int *mutato2 = new int { 7 };

*/


/*

Egyedüli változó törlése,	
	amikor végeztünk a dinamikusan elosztott változóval, kifejezetten megkell mondjuk a c++-nak, hogy szabadítsa fel az adott memóriát
		újrahasználásra.
	egyedüli változók esetében használhatjuk a delete operátort:

		// feltételezzük, hogy a mutató korábban elvolt helyezve a new operátorral
		delete mutato; // visszaadjuk az elosztott memóriát a rendszernek
		mutato = nullptr; // a mutatót null pointerré tesszük.

*/


/*

Mit jelent memóriát törölni?
	a delete operátor valójában nem töröl semmit, csak visszaadja azt a memóriát amire mutat, hogy újra használhassa az operációs rendszer.
	úgy tűnik mintha törölnénk egy változót, de nem így van, a mutató változónak úgyanaz marad a scopeja mint korábban, és új értéket
		lehet hozzá rendelni akárcsak más változóhoz.

		! fontos, olyan mutatót törölni ami nem dinamikusan elosztott memóriára mutat rossz dolgokhoz vezethet.

*/


/*

lógó(dangling) mutatók,
	c++ nem garantál semmit arra vonatkozóan mi történik egy felszabadított memória tartalmával, vagy az mutató értékével.
	a legtöbb esetben, a visszaadott memória úgyanazt az értéket fogja tartalmazni mint mielőtt visszaadták volna,	
		és a mutató a már visszaadott memóriára fog mutatni.

	egy olyan mutató amely visszaadott memóriára mutat lógó mutatónak hívunk. Dereferencelni, vagy törölni az ilyent nem szabad,
		mert váratlan dolgokhoz vezethet.

		! szabály, a törölt mutatókat mindig nullázd le! ( azaz értékük = nullptr)

*/


/*

A new operátor akár összeomolhat,
	amikor memóriát kérsz le az operációs rendszertől, akár az is megtörténhet, hogy nincs milyen memóriát félretegyen, amivel teljesítse
		a kérést.
	alapból, ha a fail összeomlik egy bad_alloc exceptiont fog kidobni, ha ezt a kivétel nincs rendesen kezelve akkor a program crashel.

	van egy alternatív megoldás, ha a new nem tud memóriát elosztani akkor simán adjon vissza egy null pointert,
		ezt úgy tehetjük meg, hogy a new és az adattípus közé berakunk egy (std::nothrow) állandót.

			de ha egy ilyen megoldással orvosolt mutatót akarsz majd dereferencelni akkor úgyancsak crashelni fog,
				legjobb egy if állítással leellenőrízni, hogy az elosztás sikerült-e

				int *value = new (std::nothrow) int; // ask for an integer's worth of memory
				if (!value) // handle case where new returned null
					{
					// Do error handling here
					std::cout << "Could not allocate memory";
					}

*/


/*

A null pointerek nagyon hasznosak tudnak lenni a dinamikus elosztás esetében, lényegében ebben a kontextusban azt jelentik,
	hogy nem lett lefoglalva memória az adott mutatóhoz.

*/


/*

Memória rések,
	egy dinamikusan elosztott memória résznek nincs scopeja. Akkor jön létre mikor mondod neki, és akkor törlődik amikor mondod neki,
		vagy amikor a program leáll. Azonban egy mutató ami egy ilyen memória címre mutat, követi a normál változók tulajdonságait,
			ez esetben scopeját. Ez érdekes problémák szülhet. Ha létrehozunk egy olyan funkciót amelyben van egy mutató ami
				egy dinamikusan elosztott memória címre mutat, de később nem töröljük ki azt, és a mutató kimegy a scopeból
					végleg elveszítjük az adott dinamikusan elosztott memóriát, ezt nevezzük memória résnek.

	amikor ez történik a programod utólag nem törölheti ki a dinamikusan elosztott memóriát, mert egyszerűen nem tudja hol van.
	a rendszer se használhatja mert azt hiszi a program még foglalkozik vele.

	a rendszer csak akkor tudja az ilyen memória rést felszabadítani amikor a program leáll.

		! nem csak ekkor jöhet létre memória rés, ha egy mutatónak úgy értéket rendelünk, akkor is elveszhet az adott dinamikus memória cím
			ez mind mind megoldható ha előzöleg töröljük a dinamikusan elosztott memóriát a delete-el.

*/


/*

Konkluzió,
	a new és delete operátor engedélyezi, hogy dinamikusan elosztott memóriát hozzunk létre vagy töröljünk egyedüli változónak
	a dinamikusan elosztott memóriának nincs scopeja, és addig elosztott marad míg manuálisan fel nem szabadítod, vagy a program leáll
	ne dereferencelj null pointert, vagy lógó mutatót

*/