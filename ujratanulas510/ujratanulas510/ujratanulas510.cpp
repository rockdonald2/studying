#include "stdafx.h"
#include <iostream>

/*

std::cin, extraction, invalid text input,
	amior egy programot megírsz ami valamilyen text input-ot használ fel kell készülnőd arra, hogy a felhasználó
		félre fogva használni a programodat, pl. rossz karaktereket ír be.

		Minden olyan program ami felkészül az ilyen esetek megoldására, kezelésére robusztusnak tartják.

*/

/*

std::cin, buffers, extraction,
	amikor a std::cin után a >>operátort használjuk ezt hívják extraction-nek, ekkor az adott változóba rakjuk az input-ot.
	amikor a felhasználó a >>operátor miatt megkapja az input lehetőséget, és ezután adatot ad le az >>operátor segítségével,
		az az adat ideiglenesen egy buffer-be tárolódik, ami szimplán csak egy része a memóriának arra lefoglalva, hogy ideiglenesen
		adatot tároljon, amíg az egyik helyről a másikra mozog az adat.
			ebben az esetben a buffer tárolja az adatot amíg el nem jut a cél változóhoz amibe végleg tárolni fogja.

	amikor az extraction operátor(>>operátor) használva van a következő folyamat zajlik le:
		ha már van adat az input bufferben, az az adat extractálva lesz.
		ha az input bufferben még nincs adat, akkor a felhasználó lehetőséget kap, hogy adat vigyen be extractálni egy változóba.
			amikor a felhasználó enter-t nyom akkor egy '\n' karakter is helyezve lesz az input bufferbe.
		a >>operátor annyi adatot extractál amennyit csak tud az input bufferből a változóba.
		bármely adat amelyiket nem tudja extractálni tovább ott marad az input bufferbe a következő extractálásig.

*/

/*

validating input(bevíteli érvényesítés),
	az a folyamat amikor leellenőrzi, hogy a felhasználó input-ja megfelel-e annak amit a program elvár, azt hívjuk beviteli érvényesítésnek.

	három alap módja van ennek:
		Inline(sorban, ahogy a felhasználó beírja),
			megelőzzük azt, hogy a felhasználó már alapból rossz inputot adjon be.
		Post-entry(beírás utáni, amiután a felhasználó már beírta),
			hagyjuk, hogy a felhasználó azt írjon be amit akar egy string-be, majd ellenőrízni, hogy a string helyes-e,
				ha igen akkor átalakítsuk a string-et a végső változó formába.
			hagyjuk, hogy a felhasználó azt írjon be amit akar, majd hagyjuk, hogy az std::cin és a >>operátor extractáljon,
				ha tud, ha nem kezelje az error eseteket.

*/

/*

érvénytelen szöveges input fajtái(types of invalid text input),
	négy fajta van:
		1. amikor az extraction sikerül, de az input értelmetlen a program számára.
		2. amikor az extraction sikerül, de a felhasználó több inputot ír be mint kellene.
		3. amikor az extraction sikertelen.
		4. amikor az extraction sikerül, de a felhasználó overflow-olja a számot.

! szóval ahhoz, hogy robusztussá tegyünk egy programot, számításba kell venni a fenti fajtákat, és olyan kódot írni ami
kezeli ezeket.

*/

/*

1, az extraction sikerül, de az input értelmetlen,
	pl. amikor egy matematikai müveletet kérsz a felhasználótól de ő egy más karaktert ír.

	ezt a legegyszerűbb megoldani, simán input érvényesítéssel.
		3 lépésből áll általában:
			1) Checkold vajon a felhasználó input az-e amire számítasz.
			2) ha igen, return-old az értéket.
			3) ha nem, mond el a felhasználónak, és csináld velük újra.

*/


/*

2, az extraction sikerül, de nagyobb az input mint kellene,
	pl, Enter a double value: 5*7
		Enter one of the following: +, -, *, or /: Enter a double value: 5 * 7 is 35

		ez esetben hiába jó az output, az egész formátum el van rontva.

		ahhoz, hogy ezt kezeljük simán el kell vetni az esetleges plusz karaktereket.
			elég egyszerű, séma: std::cin.ignore(32767, '\n');

*/

/*

3, az extraction sikertelen,
	pl. ha egy karaktert ír be szám helyett.
			a program egy double értéket vár, így a karakter végig az input bufferben marad és az std::cin belép a failure mode-ba.

		megoldása: 
		if (std::cin.fail()) // has a previous extraction failed?
		{
		// yep, so let's handle the failure
		std::cin.clear(); // put us back in 'normal' operation mode
		std::cin.ignore(32767,'\n'); // and remove the bad input
		}
*/


/*

4, az extraction sikerül, de a szám overflow,
	pl. egy 16 bites változóba, ami -32768 és 32767 között tud adatot tárolni és 40000 írsz be.
	
	ekkor ugyanúgy failure mode-ba lép, úgyanúgy lehet megoldani mint a sikertelen extraction-t.

*/
