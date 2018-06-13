#include "stdafx.h"
#include <iostream>

/*

The stack and the heap,
	a memória amit a program használ általában különböző részekre van osztva, amit szegmenseknek hívunk:
		- code segment - ahol a lecompilelolt program ül a memóriában. Általában read-only.
		- bss segment ( uninitialized data segment ) - ahol a zero-inicializált global és static változókat tárolják.
		- data segment ( initialized data segment ) - ahol az inicializált global és static változókat tárolják.
		- heap(halom) - ahol a dinamikusan elosztott változók nyerik a memóriát
		- call stack(rakás) - ahol a funkció paraméterek, helyi változók, és más funkcióhoz tartozó információk vannak tárolva.

*/


/*

Heap segment,
	a halom szegmens, nyomon követi a memóriát amelyet dinamikus elosztásra használhatunk.

	amikor a C++-ban találkozol a new operátorral amely memóriát oszt el, ez a memória a program halom szegmenséből származik.
	ennek a memóriának a címe lesz átadva a new operátor által. Fontos tudni, egymást követő memória hivások, nem biztos, hogy
		egymást követő memória címeket eredményeznek.
	amikor egy dinamikusan elosztott változó törölve lesz, a memória "vissza lesz adva" a halomnak, ami ezután újra kijelölve lehet
		egy másik kérés számára. Fontos tudni, hogy egy törölni egy mutatót nem jelenti azt, hogy a változót is töröljük,
			csak visszaadja azt a memóriát ami az adott címen található az operációs rendszernek.

		Előnyök/hátrányok:
			a halomból való memória elosztás relatíve lassú.
			az elosztott memória úgy marad amig kifejezetten nincs visszaadva, vagy a program leáll.
			a dinamikusan elosztott memóriát csak mutatón keresztül lehet elérni. A mutató dereferencelése lassabb
				mintha direkt érnénk el a változót.
			mivel a halom egy nagy 'halom' memória, nagy array-ek, structok, vagy classok oszthatók el ide.

*/


/*

Call stack,
	a rakás egy sokkal érdekesebb szereppel rendelkezik. A rakás tartsa nyomon az összes aktív funkciót(azok amelyeket lehívtak,
		de még nem értek véget) a program elejétől a jelenlegi végrehajtási fázisig, és kezeli az összes elosztást a funkció 
		paramétereknek, és a helyi változóknak.

	a rakás a 'stack data structure'-ként van végrehajtva.


Stack data structure,
	az adat struktúra egy olyan programozási mechanizmus amelyet adatok rendezésére használnak, hogy így hatékony lehessen elérni.
		már láttal hasonlókat, ilyen például a struct, vagy az array.

	a számítógép programozásban, a rakás egy tartály adat struktúra, amely tartalmaz több változót(mint egy array).
		De míg az array megengedi, hogy akármelyik elemet modosítsd vagy elérd, addig a rakás sokkal korlátozotabb.
		Háromféle müveletet enged meg a rakás:
			1) Megnézni a legfelső elemet a rakáson( a top(), vagy peek() funkció által )
			2) Levenni a legfelső elemet a rakásról ( a pop() funkció által )
			3) Új elemet rakni legfelelülre a rakásra ( a push() funkció által )

		a rakás egy last-in, first-out(LIFO) struktúra.
			a legutolsó elem amit felraktál a rakásra, lesz a legelső ami lekerül onnan.

Call stack segment,
	a rakás szegmens tartalmazza azt a memóriát amit a rakás használ.
		amikor a program elindul a main() funkció felkerül a rakásra az operációs rendszer által.
		aztán a program elkezd végrehajtódni.

		amikor a funkció hívás felbukkan, a funkció felkerül a rakásra. Amikor a jelenlegi funkció véget ér, a funkció
			lekerül a rakásról. Tehát, ha réanézünk azokra a funkciókra amelyek felkerültek már a rakásra, láthatjuk
				az összes funkciót amely levolt hívva ahhoz, hogy eljussunk a jelenlegi végrehajtási fázishoz.

		a rakás lényegében egy nagy darab fix-méretű memória címek összesége.
			azok az elemek amelyek felkerültek a rakásra stack frameknek hívjuk.
				a stack frame tartja nyomon az összes adatot amely az adott funkció hívással összefügg.
			a stack pointer tartja nyomon hol van jelenleg a rakás teteje.


Call stack in action,
	hogyan is mükődik a rakás?
		1. a program találkozik egy funkció hívással
		2. a stack frame létrejön és felkerül a rakásra. A stack frame a következőkből áll:
				a return addressből, amely alapján a CPU tudja milyen címre kell visszaadnia miután a funkció véget ér.
				minden funkció érv
				bármely helyi változó memóriája
				mentett másolatai bármely registernek amelyet modosított a funkció amely vissza kell legyen állítva amikor
					a funkció visszaad.
		3. a CPU ugrik a funkció indítási pontjára
		4. az utásítások a funkcióban elkezdnek lefolyni.

	amikor a funkció véget ér:
		1. a registerek visszaállítódnak a rakásból
		2. a stack frame lekerül a rakásról. Felszabadít minden memóriát minden helyi változónak és érvnek.
		3. a return érték kezelődik.
		4. a CPU folytatja a végrehajtást a return címnél.


Stack overflow,
	a túlfolyás,
		akkor jön létre amikor a rakásban található összes memória el lett osztva, ebben az esetben a többi elosztások
			elkezdődnek túlfolyni más memória részekbe.

		általában a program leállását eredményezi.

		akkor jön létre amikor túl nagy változókat, vagy túl sok változót, vagy túl sok fészkelt funkciót használunk.


		Előnyök/hátrányok:
			- a rakásról való memória elosztása relatíve gyors.
			- a rakásból való memória elosztás scope-ban marad addig amíg rajta van a rakáson. Megsemmisül amikor lekerül róla.
			- minden memória elosztva a rakásból ismert compile idején. Tehát, ez a memória direkt módon elérhető egy változón keresztül.
			- minden a rakás eléggé kicsi, ebből adódoan nem túl jó ötlet olyan dolgokat csinálni ami sok rakás helyet foglal.
					ide tartoznak a nagy arrayek, vagy a struct-ok.

*/

