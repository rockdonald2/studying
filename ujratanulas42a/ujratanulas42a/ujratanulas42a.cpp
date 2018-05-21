#include "stdafx.h"
#include <iostream>

/*

miért rosszak a globális változók?
	nem mindegyik globális változó rossz, itt főként nem a konstans globális változókra kell gondolni.
		az a legnagyobb gond velük, hogy bármelyik funkció megváltoztathatja az értékét, és erről a programozónak semmi figyelmeztetése nem lesz
		kivéve ha belsőleg ismeri a programot.

		második gond velük, hogy kevésbé modularissá teszik a programot,
			egy olyan program amelynek funkció semmi mást nem használnak csak paramétereket, és nincsenek mellékhatásai tökéletesen modulárisak.

		szabály!, használj helyi változót globális változó helyet amikor csak lehetséges, és kapcsold öket össze funkciókkal amelyek használják.

	
	lehet jóra is használni a globális változókat, ilyen pl. egy sound library, vagy error log,
		mert ezekből általában csak 1 van és rengeteg funkció használja őket

*/


/*

hogyan tudod mégis láthatóva tenni, hogy egy változó globális?
	fontos, használj hozzá egy prefixet, általában g_ mert ez felhívja a figyelmet, hogy az adott változó globális
	a második lehetőség, a kettőt lehet kombinálni is, tedd be őket egy namespace-be, hogy megelőzd a naming collisiont.

	második fontos, ahelyett, hogy közvetlen módon engedélyeznéd egy globális változó elérését,
		használj funkciókat amik visszaadják az értékét, hogy elzárd az adott globális változót.
			használj static előszót a globális változóra, és extern a funkcióra.

	harmadik fontos, mikor írsz egy önálló funckiót ami használ egy globális változót, nem a funkció body-ban használd az adott változót,
		hanem paraméterként a zárójelben, így segítve a modularítást.

*/


/*

nagyon fontos dolog a globális változókkal!
	ha globális változókat használsz a programodban, építsd fel úgy, hogy számolsz azzal, hogy a globális változód értéké megváltozhat.
	minimalizáld azoknak a helyeknek a számát ahol a globális változód értéke megváltozhat.

*/