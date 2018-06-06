#include "stdafx.h"
#include <iostream>

/*

Az érték általi továbbadás számos esetben megfelelő de van pár korlátozása. 
	Először, amikor nagy structokat vagy classokat adunk tovább készít egy másolatot ami hatalmas teljesítmény probléma. 
	Másodszor, képtelen megváltoztatni az eredeti érvet. A hivatkozás általi továbbadás ezt megoldja.


Amikor egy változót hivatkozás által adunk tovább, csak simán meghatározzuk a funkció paramétert mint hivatkozás, 
	nem mint normál változó.

void foo(int &x); // ahol az &x egy hivatkozás

Amikor lehívjuk ezt a funkciót az &x egy hivatkozás lesz az érvre. 
Mivel a hivatkozás ugyanúgy viselkedik mint a rendes változó, bármilyen változás az eredeti érvet is megváltoztatja.


Néha egy funkció több értéket kell visszaadjon.
Egy funkciónak mivel csak egy lehet, ezért ezt hivatkozások által tudjuk megoldani.
	! Lásd pl.

Korlátozottságok,
	Nem konstans hivatkozások csak nem konstans l-értékeket használhatnak(változók), 
		így egy hivatkozás nem használhat egy konstans l-értékeket, vagy r-értékeket.(kifejezések, vagy számok)

Konstans hivatkozás általi továbbadás,
	Amikor egy érvet hivatkozás által adunk tovább, egy hivatkozás készül az eredeti érvre, 
		és így nem játszódik le másolás. Ez lehetővé teszi, hogy nagy structokat 
			vagy classokat adjunk tovább minimális teljesítmény hibával.

	Ez lehetséges gondokat szül, mivel ha csak read-only érvet akarunk, így konstanssá kell tenni a hivatkozást.
	Ez bebiztosítja, hogy az eredeti érvet ne tudja módosítani a funkció amiben felhasználjuk.

	
		! Amikor hivatkozás által adsz tovább értéket, mindig használj konstans hivatkozást, 
			hacsak nem kell megváltoztatni az értéket.

Hivatkozás egy mutatóra,
	Lehetséges egy mutatót tovább adni hivatkozás által, és így megváltoztatni a mutató címét teljesen.

	Úgyanakkor, simán továbbadhatsz egy array mutatót hivatkozás által.
		Ez hasznos, ha szükséged van arra, hogy a funkció változtassa az arrayt, vagy ha szükséges van az array információira
			(pl. sizeof(), vagy for-each), de ahhoz, hogy ez müködjön kifejezetten megkell határoznod az array hosszát
				a funkció meghatározásban a paraméterben.

				! lásd pl.

*/

/*

Előnyei:
	- a hivatkozás lehetőve teszi, hogy megváltoztassuk egy adott érv értéket, ami sokszor hasznos.
		ha ezt nem szeretnénk használjunk konstans hivatkozást.
	- mivel itt nincs másolási technika, mint az érték szerinti továbbadáskor, ezért gyors, akár nagy structok vagy classok
		esetében is.
	- használhatjuk több return érték eléréséhez.
	- muszáj őket inicializálni, így nem lehetséges null értéket kapni.

Hátrányok:
	- mivel nem konstans hivatkozások nem lehetnek inicializálva konstans l-értékekkel, vagy r-értékkel,
		így az érvek amiket így adunk tovább muszáj normál változók legyenek.
	- nehéz megállapítani, hogy egy paraméter amit nem konstans hivatkozás által adunk tovább az input, output vagy mindkettő.
		okos használata a konstans-nak, valamint a név suffixoknak hasznos lehet és segíthet.
	- lehetlen megmondani, hogy egy funkció lehívás megváltozatja az érvet vagy sem.
		Az érték által továbbadott, vagy a hivatkozás által továbbadott érvek úgyanúgy néznek ki.
			Csak a funkció meghatározás alapján tudjuk megállapítani a különbséget.
				Ez ahhoz vezethez, hogy a programozó nem veszi észre, hogy a funkció megváltozatja az érv értékét.

Mikor használjuk?
	Amikor structot vagy classot adunk tovább(csakis konstans hivatkozás által)
	Amikor a funkciónak megkell változtatnia az érvet.
	Amikor szükséged van egy fix array információira egy funkcióban.

Mikor ne?
	Amikor alapvető adattípusokat adunk tovább, amiket nem kell változtatni(használd inkább az érték szerintit).
*/
