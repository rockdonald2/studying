#include "pch.h"
#include <iostream>

/*

Uncaught exceptions,
	szóval az előbbi néhány példában a funkció feltételezte, hogy a hívó kezelni fogja a kivételt
	- de mi van akkor ha valójában senkisem fogja?
		lásd pl.

		amikor egy throw jelenik meg, a program leellenőrzi, hogy a funkció tudja-e kezelni, mivel nem tudja
			unwindeol és a kontroll visszatér a main() ami után a program leáll mivel a main() sem tudja kezelni.
			! ezt teljes egészében el akarjuk kerülni

*/


/*

Catch-all handlers,
	mivel lehetséges úgy funkciót lehívni, hogy nem tudjuk pontosan hogyan mükődik és milyen throw típus dobhat,
		ezért használjuk a catch-all handler, ami bármilyen típusú exception képes kezelni.
		- úgy mükődik mint egy normális catch blokk, csak az ellipszis operátort használja, azaz az adott adattípus
			helyett (...) használ.
			! fontos, általában mindig a catch blokk sorban az utolsó helyet foglalja el
			! gyakorta üres, így elkap minden nem várt kivételt, és megelőzi a stack unwindet a program tetejéig,
				de nem végez különleges error kezelést
				
	egy másik érdekes használata a catch-all handlernek az a main() becsomagolása,
		- ez esetben ha egy funkció dob egy kivételt amit nem tud megfogni, az a kivétel unwindeol a stacken
			amíg a catch-all handler nem kezeli, ez által képesek vagyunk még egy error üzenetet kiírni,
				illetve pl. játékok esetében a játék állását menteni, megelőzzük a main() leállását

*/


/*

Exception specifiers,
	ez egy opcionális dolog, nagyon ritkán használják a gyakorlatban, és maga a C++ alkotója(Bjarne Stroustrup) is
		egy sikertelen probálkozásnak tartja.

		- ez egy mechanizmus ami lehetővé teszi számunkra, hogy a funkció meghatározásban meghatározzuk, hogy
			a funkció dobhat-e vagy sem kivételeket.
			így el lehet dönteni, hogy kell-e try blokkba tenni vagy sem.

			- három féle típus van belőle, mindegyiknek a throw(...) a sémája

		először, használhatjuk az üres throw állítás, hogy jelezzük a funkció nem dob kivételt
			int doSomething() throw();
			- ebben az estben a doSomething() dobhat kivételt, de azt önmaga kell kezelje
		másodszor, használhatjuk a különleges throw állítást, amikor meghatározzuk a throw adattípusát
			int doSomething() throw(double);
		végül, használhatjuk a catch-all throw állítást, amikor nem határozzuk meg a throw adattípusát
			int doSomething() throw(...);
				! nincs értelme az egésznek, ne használd, sokan nem is tudnak a létezéséről.
*/