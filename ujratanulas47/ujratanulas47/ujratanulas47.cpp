#include "stdafx.h"
#include <iostream>

/*

structure, röviden struct,
	egy olyan felhasználó által meghatározott csoportosító adattípus, amely segítségével több, különböző adattípusú változót tudunk
		egyetlen egységgé csoportosítani.

*/

/*

egy struct meghatározása egyszerű,
	elkezdjük a struct kulcsszóval, majd ezt követi a csoportunk neve, nagy kezdőbetüvel, majd { }; sémával a tagok.
		pl. struct Felhasznalo
			{
				short id;
				std::string name;
				int age;
			};

				fontos tudnivaló, hogy nincs memória lefoglalva a csoport számára, csak futás során.


		Ahhoz, hogy használjuk az általunk meghatározott struct-ot, ez esetben a Felhasznalo-t, simán meghatározunk egy változót
			a mi típusunkkal.
				pl. Felhasznalo joe; 
						és ilyenkor kerül memória lefoglalásra az adott változónak.

		Amikor létrehozunk egy ilyen változót, mint Felhasznalo joe; , joe hivatkozik a teljes structra, és minden tagjára.
			amikor el akarunk érni egyes tagokat, hogy értéket adjunk hozzá, használjuk a member selection operator-t, ami egy . (pont).
				pl. joe.id = 2;
					joe.name = "Joe";
					joe.age = 22;

		Struct tag változók, mint a fentiek, úgy viselkednek mint normális változók, így lehet normál műveleteket rajtuk végezni,
			pl. összehasonlítás, összeadás, növelés, vagy hozzárendelés.


		A C++ támogat egy gyorsabb utat ahhoz, hogy inicializáld a változókat, már meghatározáskor.
			pl. Felhasznalo joe = {2, "Joe", 22}; 
				ha pár tagot nem inicializálsz ilyen módon, az az alap értékre fog inicializálodni, ami a 0.0.

		C++11-től kezdődöen lehetséges meghatározni a non-static tagoknak egy alap értéket.
			pl. struct Felhasznalo
				{
					short id = 1;
					std::string name;
					int age = 18;
				};

					és ezután úgyanúgy lehet használni a uniform inicializálást, mint fentebb.

		Nagy előnye a struct-oknak, hogy fel tudjuk őket használni funkció paraméterként, így az összes tagot tudjuk használni a funkción
			belül.

		Úgyanakkor, a funkciók képesek struct-okat returnolni.

		Lehet structokat fészkelni.
			pl. struct Felhasznalo
				{
					short id;
					std::string name;
					int age;
				};

				struct Weboldal
				{
					Felhasznalo joe;
					int felhasznalokSzama;
				};   így a Felhasznalo struct is része lesz a Weboldal struct-nak.

				Weboldal enWeboldalam;
					
					ha leakarjuk kérni, vagy hozzárendelni értéket, kétszer kell használnunk az operátort,
						pl. enWeboldalam.joe.id;

					úgyanakkor lehet fészkelt inicializálást is végrehajtani,
						pl. Weboldal enWeboldalam = {{ 1, "Joe", 22} 1};


		Egy struct mérete általában akkor mint az összes tag méretének az összege, de nem mindig.
			Meghatározható, hogy egy struct mérete legalább akkora mind az összes tagnak az összege, de lehet nagyobb is.

		
		Ahhoz, hogy egy struct-ot elérhetőve tegyél több fájl között, foglald egy header fileba, és includeold.
			Ha egy struct változót akarsz elérhetőve tenni, használd az extern kulcsszót.
*/