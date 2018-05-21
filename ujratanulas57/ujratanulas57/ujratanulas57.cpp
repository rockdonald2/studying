#include "stdafx.h"
#include <iostream>

/*

for statement,
	a legtöbbet használt loop állítás a c++-ban.
		akkor ideális a for loop mikor tudjuk pontosan hányszor akarjuk ismételni, mert ez lehetőséget ad, hogy könnyen 
		meghatározzunk, inicializáljunk és megváltoztassuk az értékét egy loop változónak minden ismétlés után.

		sémája:
			for (kezdő-statement; kondició-kifejezés; befejező-kifejezés)
				állítás

				egy for loopon belül létrehozott változónak sajátos scopeja van, loop scope, szóval csak azon a loopon belül érhető el.

*/


/*

egy for loop 3 lépésből értékelődik ki:
1) kezdő-állítás(init-statement) értékelődik. Általában, a kezdő-állítás egy változó meghatározást és inicializálásttartalmaz.
	csak egyszer értékelődik ki, amikor a loop először végrehajtódik.
2) kondició-kifejezés(condition-expression) értékelődik. Ha ez false lesz akkor a loop egyből véget ér, ha true lesz, akkor az állítás végrehajtódik.
3) Amiután az állítás végrehajtódott, a befejező-kifejezés(end-statement) értékelődik. Általában, ez arra hivatott, hogy incrementálja
	vagy decrementálja a változót amit létrehozunk az első lépésben, amiután ez lejár, visszaugrik a loop a második lépésre.

*/

/*

Off-by-one error,
	akkor jön létre amikor egy loop túl kevésszer, vagy túl sokszor hajtódik végre mint amit elvárnánk
		ez általában a rossz relational operator használata miatt történuik meg.
			nehéz ezeket a hibákat visszakövetni, mert a compiler nem fogja error-ként jelezni, de a program mindig a rossz eredményt fogja irni.

	amikor csak lehet teszteld a loopodat olyan értékekkel amelyekkel 1szer, 2szer, és 3szor hajtódnak végre
*/


/*

elhagyható kifejezések(omitted expression),
	lehetséges egy for loopon belül elhagyni az első, és a harmadik kifejezést,
		de ilyenkor manuálisan kell egy blokkban a for alatt ezeket létrehozni.


			for végtelen loop:
				for ( ;; )
					állítás;

*/

/*

lehetséges egy for loopon belül, több változót létrehozni és modosítani, ilyenkor vesszővel választjuk el őket.

	pl. for (iii = 0, jjj = 9; iii < 10; ++iii, --jjj)
			cout << iii << jjj;


lehetséges fészkelni is őket, úgyanúgy mint egy while loopot.
	ekkor minden ismétléssel a külső loopnak, a belső loop teljes egészében lefut.

*/