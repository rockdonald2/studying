#include "stdafx.h"
#include <iostream>

/*

A C++ biztosít egy sor alapvető adattípust(char, int, long, float double, stb.) amik gyakran elegendők ahhoz, hogy relatíve könnyű
	problémákat oldjunk meg, de nehéz lehet velük megoldani komplex problémákat.
	A C++ egyik hasznos vonása a lehetőség, hogy saját adattípusokat határozzunk meg ami jobban megfelelő a megoldandó problémához.
	Ilyen akár a struct vagy az enum.

	Classes,
		Az OOP világban, gyakran akarjuk, hogy a saját típusunk ne csak adatot tároljon, hanem biztosítsa a saját funkcióját ami
			dolgozik a megadott adatokkal. C++-ban ezt általában a class kulcsszóval visszük véghez. Használva a class kulcsszót
			meghatározzunk egy új felhasználó által meghatározott típust amit classnak hívunk.

		A c++-ban a classok nagyon hasonlítanak a data-only structokra, kivéve azt, hogy a classok sokkal nagyobb erőt,
			rugalmasságot biztosítanak.
			
				lásd pl class-ra.

				! úgyanúgy mint egy struct meghatározás, a class meghatározás sem tesz félre semmilyen memóriát.
					Csak meghatározza, hogy hogyan kell kinézzen a class.

		A c++-ban amikor meghatározunk egy változót egy classból, azt instantiating-nek hívjuk(példával szemléltetni).
			Maga a változót hívjuk a példának az adott classból. A változót egy adott class típusból is objectnek hívjuk.
			Ilyenkor lesz lefoglalva memória az adott változónak.


	Member functions,
		A classok az adatokon kivül tartalmazhatnak funkciókat is. Egy olyan funkciót amit egy classon belül határozzunk meg
			tag funkciónak hívunk. Meghatározhatjuk őket akár belül akár kivül.
		Ahogy a struct tagjai érjük el, úgy egy class tagjait is a member selection operátorral(.)-al érjük el.



	! fontos észrevenni mennyire hasonló a structos változat a classoshoz.
		De azért van nehány különbség.
		A 'DatumStruct' változatban a példában, mi átkellett adjuk a structot a kiirDatum() funkciónak az első paraméterként.
			Másképpen a funkció nem tudta volna milyen 'DatumStruct'-ot akarunk használni. Majd kifejezetten hivatkoznunk kellett
				a paraméterre a funkción belül.

		A 'DatumClass' változatban tag funkciót használtunk. Azok kicsit másképpen mükődnek. Minden tag funkció hívás össze kell
			legyen csoportosítva egy objecthez az adott classból. Amikor lehívjuk a 'ma.kiir()' funkciót, azt mondjuk a compilernek
			hogy hívja le a 'kiir()' tag funkciót, összecsoportosítva a 'ma' objecttel.
			A teszünk egy pillantást a tag funkció meghatározására, feltesszük a kérdést mire vonatkozik a m_ev, stb..
				Az összecsoportosított objectre vonatkozik. 
					Szóval mikor lehívjuk a 'ma.kiir()' funkciót, a compiler felcseréli az m_nap-ot ma.m_nap-ra.
					Ez a mód által, az összecsoportosított object lényegében magától értetődőöen tovább lesz adva a tag
					kiválasztó operátorral a tag funkciónak. Ez az ok miatt, gyakran hívják magától értetődő objectnek.

				! az 'm_' prefix nagyon hasznos class tag változók meghatározásánál. Segít megkülönböztetni őket funkció paraméterek-
				től vagy helyi változóktól tag funkciókon belül.

				! szabály, a classok nevei nagy betűvel kezdődjenek.

		Egy megjegyzés a structokhoz:
			- Akárcsak a classok a structok is képesek funkciókat tárolni. De nem ajánlatos.

				! fontos szabály, structokat mindig csakis adattárolásra, azaz data-only, használd, sose funkciókhoz.
					a classokat pedig olyan objectekre amiknek van adatuk és funkciójuk is.

*/


/*

Konkluzió:
	A class kulcsszó lehetővé teszi számunkra, hogy saját típusokat hozzunk létre a C++-ban, mivel tartalmazhat tag változókat,
		és tag funkciókat is. A classok az OOP alapjai, és azzal fogjuk eltölteni a következő fejezeteket, valamint ennek a fejezetnek
			a többi részét, hogy felfedezzük mi minden kinálhatnak számunkra.

*/