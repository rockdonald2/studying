#include "stdafx.h"
#include <iostream>

/*

software testing(szoftver tesztelés),
	az a folyamat amely során megbizonyosodunk arról, hogy a programunk a létező összes esetben megfelelően mükődik.

*/


/*

Hogyan teszteld a kódodat: Informális tesztelés,
	sok fejlesztő informális tesztelést végez miközben írja a kódot.
	az informális tesztelés során írsz egy ideiglenes funkciót ami leteszteli azt a kódot amit épp hozzáadtál.
		miután megbizonyosodtál róla, hogy a kód helyesen mükődik tőrlöd az ideiglenes funkciót.

*/

/*

Tesztelési tipp #1:
	írd a programodat kicsi, jól körülhatárolt funkciókba, és sokat compile-olj az írás közben.

	szabály: Sokat compile-olj, és tesztelj minden nem jelentéktelen funkciót, amikor megírod őket.

*/

/*

Tesztelési tipp #2:
	code coverage(kódlefedettség): kifejezi, hogy a forráskód mekkora mértékben hajtódott végre tesztelés közben.

	célozz a 100%-os állításlefedettségre.(statement coverage)
		statement coverage: kifejezi, hogy az állítások milyen százaléka lett letesztelve a tesztelésed során.

	szabály: bizonyosodj meg róla, hogy letesztelsz minden állítást egy funkcióban.

*/

/*

Tesztelési tipp #3:
	branch coverage(áglefedettség): kifejezi, hogy az ágak milyen százaléka hajtódott végre, úgy, hogy a true és a false ág különnek számít.
if-nek kettő van, if és else; switch-nek több.

	célozz a 100%-os áglefedettségre.

	szabály: tesztelj le minden ágat, úgy, hogy legalább egyszer true legyen, egyszer pedig false.

*/

/*

Tesztelési tipp #4:
	loop coverage(looplefedettség): kifejezi, hogy a kódodban levő loopot letesztelted és megbizonyosodtál, hogy mükődik az ha egyszersem,
		egyszer, vagy kétszer ismétlődik meg.

	célozz a 100%-os looplefedettségre.

	szabály: Használd a 0,1,2 tesztet a loopjaidon, hogy megbizonyosodj róla, hogy különböző ismétlesekkor is helyesn mükődik.

*/

/*

Tesztelési tipp #5:
	bizonyosodj meg róla, hogy a programod mükődik különböző input típusokkal, kategoriákkal.

	szabály: Tesztelj különböző kategoriájú inputokkal, hogy megbizonyosodj helyesen kezeli őket.

	pl. integer esetében, negatívszám, nulla, pozítivszám
		floating point szám esetében: 0.1 + -0.1, 0.6 + -0,6
		string: üres string, normál string, string whitespace-el, csak whitespace.
	

*/

/*

Hogyan teszteld a kódodat: tartósítsd a teszteidet.
	ebben az esetben nem törlőd ki az ideiglenes tesztelő funkcióidat, hanem megtartod későbbi tesztelésekhez is.
	
Hogyan teszteld a kódodat: Automatizáld a teszt funkcióidat.
	írsz egy funkciót ami tartalmazza mindkét tesztet és a várt eredményeket.
*/