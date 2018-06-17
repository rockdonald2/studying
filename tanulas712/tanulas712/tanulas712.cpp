#include "stdafx.h"
#include <iostream>

/*

Handling errors, cerr, and exit,
	amikor programokat írsz elkerülhetetlen, hogy hibákat véts.
	ebben a részben a különböző hibatípusokról lesz szó, és, hogy azokat hogyan lehet kezelni.

		két kategória van: séma(syntax) és jelentéstani(semantic) hiba.

*/


/*

Syntax errors,
	a séma hiba akkor jelentkezik amikor olyan kódot írunk ami nem felel meg a C++ "nyelvtanának".
		pl. ha 5 nem egyenlő 6-al akkor írd ki "nem egyenlő".
				ez egy séma hiba
			a helyes:
				if ( 5 != 6 )
					std::cout << "nem egyenlo";

		 - általában könnyű ezeket kijavítani és mindig kimutatja a compiler.

*/


/*

Semantic errors,
	jelentéstani hibák akkor jelentkeznek amikor egy kód séma alapján helyes, de mégsem azt teszi amit a programozó szeretne.
	
		- ezeket a hibákat a compiler nem mutatja ki, és gyakran elég nehéz megoldani.
				különböző hatással rendelkezhet a programra nézve:
					nem jelenik meg, rossz output, korrupt adatok, program crash, változó viselkedés.


		- különböző módok alapján jöhet létre jelentéstani hiba
				- logic error, amikor az állítás logikája helytelenül van megírva.
						pl. x <= 5;
								cout << "x nagyobb mint 5";
								de mivan ha pontosan 5? => logikai hiba.
				- violated assumption, amikor a programozó feltételezi valamiről, hogy az csak igaz/hamis, és helytelen.
						pl. std::string hello = "Hello, world!";
							std::cout << "Enter an index: ";
 
							int index;
							std::cin >> index;
 
							std::cout << "Letter #" << index << " is " << hello [index] << std::endl;

							- ebben az esetben a programozó feltételezi, hogy a felhasználó csak 0 és a string hossza közötti
								számot fog megadni. De mivan ha nagyobbat?

*/


/*

Defensive programming,
	egy olyan program tervezési forma amely magába foglalja az olyan részek megállapítását ahol ilyen fajta feltételezési
		dolgok létrejöhetnek, és olyan kódokat ír ezekhez amelyet észreveszi és kezeli ezeket, ez által a program
		kiszámítható módon reagál amikor ezek megjelennek.

Detecting assumption errors,
	elkaphatunk nagyjából minden feltételezést amit lekell ellenőrznünk az alábbi 3 hely egyikében:
		- amikor a funkciót lehívják, a hívó talán olyan paramétert adott tovább ami helytelen, vagy jelentéstanilag értelmetlen.
		- amikor a funkció returnol, a return érték talán mutathatja, hogy hiba fordult elő.
		- amikor a program inputot fogad(user/file), és az input talán nem a megfelelő formában van.

	tehát, amikor defenzíven programozunk három dolgot kell észben tartanunk:
		- minden funkció tetején, ellenőrízd le, hogy bármely paraméter megfelelő értékkel rendelkezik.
		- amiután a funkció returnolt, ellenőrízd le az értékét(ha van), és bármely más error jelentő mechanizmust, hogy lásd
			ha bármilyen hiba előfordult.
		- igazolj bármely felhasználó inputot, hogy megbizonyosodj róla, hogy teljesíti-e a várt formátumi, vagy határi kritériumokat.
		

Handling assumption errors,
	néhány tipikus módszer amivel megoldható a hiba:
		1) Csendesen ugord át a kódot ami arra alapoz, hogy a feltételezés helyes:
			void printString(const char *cstring)
			{
		   // Only print if cstring is non-null
			if (cstring)
			 std::cout << cstring;
			}

				- ha a mutató null, nem ír ki semmit. Ez akkor jó opcíó ha az állítás nem kritikus, nem befolyásolja a program
					logikáját.

		2) Ha egy funkcióban vagyunk, returnolj egy error kódot a hívónak, és hagyd, hogy a hívó intézze a problémát.

		3) Ha egy programot azonnal akarunk befelyezni használhatjuk az exit() funkciót a <cstdlib> headerből,
				az exit() funkcióba írt érték egy error kód az operációs rendszerhez.

		4) Ha a felhasználó egy helytelen inputot írt be, kérd, hogy újat írjon be.

		5) a cerr, egy újabb mechanizmus amivel error üzenetet írhatunk ki.
				a cerr egy output stream(pont mint a cout), ami az <iostream>-ben van meghatározva,
				általában, a cerr kiír egy error üzenetet a képernyőre, de akár egyénileg átírányithat egy fájlra.

		6) Ha valamilyen grafikus környezetben dolgozol(MFC, SDL, QT, stb..), gyakori, hogy egy pop-up üzenet boxban küldjük
			ki az error kódot és utána leállítsuk a programot.
*/