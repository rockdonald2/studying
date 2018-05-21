#include "stdafx.h"
#include <iostream>

/*

Switch állítás,
	a switch állítás célzott lecserélni az összeláncolt if-else állításokat.

		switch elég egyszerűen épül fel,
			a switch kifejezés case labelekből és egy opcionális default labelből áll
			
			a kifejezés tartalmaz egy értéket amit letesztel a labelekkel egyenlőségből
			ha bármelyik case label megegyezik az értékkel, akkor a case label utáni kifejezések hajtódnak végre
				ha egyik case label se egyezik akkor a default label hajtódik végre, ha létezik.

*/


/*

egy switch kifejezést a switch kulcsszóval kezdünk ell, és utána jön zarójelben a kifejezés amit szeretnék kiértékelni.
	lehet ez egy egyszerű változó, vagy összetett kifejezések.
		egyetlen korlatozás van, muszáj integer típus legyen, nem lehet floating point szám.

a switch kulcsszó után létrehozunk egy blokkot { }

két fajta label van a switch állításban: case label, és default label.

*/


/*

az első label a case label, amit a case kulcsszóval hozunk létre, és ezt követi egy konstans kifejezés, ami lehet egy szám,
	lehet egy enum, vagy akár egy const int.

	a konstans kifejezést fogja tesztelni egyenlőségből a megadott kifejezésünkkel.
		ha a kettő egyezik akkor a case label alatti kifejezés hajtódik végre.


		! fontos tudni, mindegyik case label kifejezés egyedi érték kell legyen, nem használhatsz két kifejezést aminek értéke egyenlő.

		! de ugyanakkor lehetséges, hogy több case label ugyanazt az állítást használja,
			pl. ha több esetben teszteljük, hogy egy változó értéke mivel egyenlő.
*/


/*

a második label amit tartalmaz egy switch állítás, a default label(hívják default case-nek is),
	ami a default kulcsszóval hozunk létre

		az ez alatt található kifejezések csak akkor hajtódnak végre ha egyik case label se egyezik meg a switchben használt kifejezéssel.

	opcionális, és csak egy lehet belőle egy switch állításban.

*/


/*

a legtrükkösebb dolog a switch állításokban, hogy ha egy adott case label megegyezik a switch állításban használt kifejezéssel
	akkor a végrehajtás elkezdődik az első kifejezéssel a label után, és addig folytatódik míg valamelyik befejező kondició megjelenik:
		1. switch blokk vége
		2. goto állítás
		3. return állítás
		4. break állítás
		5. bármi más ami megállítja a program normális áramlását(exit(), vagy exception).

			! ha egyik kondició sem jön létre a fentiek közül, a casek összefolynak,
				azaz ha a második case lesz match, akkor a case 2 alatti összes case is végrehajtódik.
					
					ezt fall-through, azaz kudarcba fulladásnak hívjuk.

*/


/*

break állítás, amit a break kulcsszóval hozunk létre,
	azt mondja a compilernek, hogy végeztünk az adott switch-el(vagy whileal, do whileal, or for-al).

		amikor megjelenik egy break állítás, a végreahjtás folytatódik az az állítással ami a switch blokk után van.


		! ELHAGYNI A BREAK ÁLLÍTÁST EGY CASE LABELBEN TALÁLHATÓ ÁLLÍTÁS UTÁN AZ EGYIK LEGGYAKORIBB C++ HIBA!!!!

*/


/*

egy switch állításon belül deklarálhatsz, de nem inicializálhatsz egy változót,
	lehet az case-n kivül, vagy azon belül.

	mivel egy switch állításban található case labelek úgyanabban a scope-ban találhatóak, így az egyik case-ben deklarált változó
	felhasználható egyik másik case-ben is, akkor is ha a deklaráló case soha nem hajtódott végre.

		! csak akkor inicializálhatsz egy változót egy case-n belül ha blokkot használsz
			


*/