#include "stdafx.h"
#include <iostream>

/*

Implicit type conversion (magától értetődő típus átalakítás)
	az a folyamat amelyben az érték egyik adat típusból a másikba alakul type conversion-nek(típus átalakításnak) nevezzük.
		a type conversion több módon történhet:
			pl. hozzárendelni, vagy létrehozni egy változót egy másik adattípussal
				belefoglalni egy értéket egy funkcióba ahol a funkció paraméternek más a típusa.
				visszaadni egy értéket egy funkcióból ahol a funkció return értéke egy másik típusú.

					ezekben az esetben a compiler type conversiont fog használni, hogy egyik adattípusból a másikba alakítsa az értéket.
*/


void funkcio()
{

double d{ 5 }; // létrehozni a double típusú változót egész szám értékkel.
d = 6; // hozzárendelni a double típusú változóhoz az egész értéket.

}

void funkcio2(long random)
{

}

float funkcio3()
{
	return 3.0; // visszaadni a double érték 3.0-át egy float return típuson keresztül.
}

int p_main()
{
	funkcio2(3); // belefoglalni az int értéket egy olyan funkcióba ami long-ot kér.

	return 0;
}


/*

két alap típusú típus átalakítás van: implicit type conversion és explicit type conversion;
										magától értetődő típus átalakítás   és    határozott típus átalakítás;

*/


/*

implicit type conversiont akkor teljesít a compiler akármikor egy alapvető adat típusra számít, de egy másik alapvető adattípust kap,
	és a felhasználó nem mondta el határozottan(cast paranccsal), hogy hogyan teljesítse az átalakítást.

	minden példa fentebb implicit type conversion.

		két alap fajtája van a magától értetődő átalakításnak: promotions(előléptetés) és conversions(átalakítás)

*/


/*

numeric promotion
	ez akkor jön létre amikor, egy kisebb adattípus átalakítodik egy hasonló nagyobb adattípussá.
		pl. egy int-et előlehet léptetni long-á, vagy egy float-ot double-é.

	a feltétel, hogy "numeric promotion" jöjjön létre fedez minden típusú előléptetést, de két még fontos feltétel létezik a c++-ban:
		az egyik az integral promotion, amely magába foglal egy átalakítást egy kisebb mint int típusból(ide tartozik, bool, char, short)
			egy int-é(ha lehet) vagy unsigned int-é.
		a másik a floating point promotion, amely magába foglalja a float átalakítását double-é.

			ezek az átalakítások azért fontosak, mert kisebb adattípusokat alakítanak át int-é vagy double-é, mert ez a két legteljesítménybarátabb 
				típus a nyelvben.

			fontos tudni az előléptetésekről, hogy mindig biztonságosak, és semmilyen adatvesztéssel nem járnak.
				az előléptetés csak az adott bitformátum kiterjesztését takarja.

*/


/*

numeric conversion,
	amikor átalakítunk egy nagyobb típust egy hasonló kisebbé, vagy különböző típusok között alakítunk, ezt hívjuk numeric conversionnek.


		nem úgy mint az előléptetésnél, az átalakítással jár vagy talán nem jár az adatvesztés, mert itt akár az egész bit formátum
			átalakítása is létrejöhet, ezért gyakran használ figyelmeztéseket a compiler futtatáskor.


		rengeteg szabály létezik átalakításra, pár fontosabb:
			1. minden esetben, egy érték átalakítása egy olyan típusban amelynek nincs elég nagy tartománya, hogy támogassa az értéket,
				nem várt eredményeket vonhat maga után, ezt el kell kerülni.
			2. úgyanakkor, egy nagyobb típus átalakítása egy hasonló kisebbe általában mükődik, ha a kisebb típus tartománya megfelelő.
			3. nem egész számok esetében fontos figyelemmel követni a kerekítési hibákat, mivel ha egy double-t alakítunk float-á,
				veszíthetünk számjegyeket, mivel a float csak 7 számjegyet tud követni a pont után.
			4. int átalakítása float-á mükődik, addig amíg az érték belefér a float tartományába.
			5. float átalakítása int-é mükődik, addig amíg belefér az int tartományába, de bármilyen tizedes rész elvesztődik.

*/


/*

számtani kifejezések értékelés (evaluating arithmetic expressions)
	amikor kiértékeli a kifejezéseket a compiler lebont minden kifejezést kisebb alkifejezésekre(subexpressions), mivel a számtani műveletek
		azt követelik, hogy az operándusok(a tagok) úgyanabból a típusból legyen.
			hogy ezt bebiztosítsa a compiler a következő szabályt alkalmazza:
				ha egy operándus kisebb mint egy int, átalakítja azt int(integral promotion)
				ha még mindig nem egyeznek az operándusok, a compiler megkeresi a legnagyobb típusú operándust és azzá alakítja a másikot.


		a typeinfo header-ben található typeid() parancs kiírja a számtani átalakítás eredményét.

*/
