#include "stdafx.h"
#include <iostream>

/*

goto állítás,
	ez egy áramlást kontrolláló állítást ami kényszeríti a CPU-t, hogy egy másik helyre ugorjon a kódban.
		ezt a helyet a statement label-el határozzuk meg.

			! fontos, a goto statement, és a statement label úgyanabban a funkcióban kell legyen.

		vannak szabályok, például nem ugorhatsz át egy változót ami úgyanabban a blokkban van inicializálva mint a goto.

		pl.
			goto ugras;
			int x = 5;
		ugras:    // ez az ugrás érvénytelen.

*/

/*

Átlagban, a goto statementeket nem szabad használni, jobb elkerülni.
	A legfontosabb probléma a goto-val az, hogy engedi a programozónak, hogy önkényesen ugráltassa a végrehajtási pontot.
		így jön létre a spaghetti kód, ami egy olyan kód aminek a végrehajtási útja hasonló egy tál spaghettihez,
			összekuszált, így nehezítve a kód megértését.

*/


/*

SOHA NE HASZNÁLD A GOTO-T, HACSAK NEM SZÜKSÉGES.

*/