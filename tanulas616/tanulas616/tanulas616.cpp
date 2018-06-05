#include "stdafx.h"
#include <iostream>

/*

Bevezetés az std::vector-ba,
	az std::vector biztosít egy olyan dinamikusan elosztott arrayt amely saját magának kezeli a memóriát.
		- azaz, létrehozhatsz egy olyan arrayt amely runtime idején tudja meg milyen hosszú, anélkül, hogy kifejezetten
			elosztanod, és felszabadítanod kellene a memóriát new és delete segítségével.
		- megtalálható a <vector> headerben.


		séma: std::vector<adattípus> arraynév;
			- lehet inicializálni uniformmal, initializer listtel.

			! fontos, nem kell belefoglalni inicializáláskor az array hosszát a sémába.
			
		úgyanúgy mint az std::arraynél, elemválasztáshoz használhatod a klasszikus [] operátort, vagy az at() funkciót.
			különbség az, hogy az elsőnél nincs határ check, a másiknál meg van.

		simán lehet az ilyen fajta arrayt újrainicializálni, ilyenkor saját magát átméretezi az új értékekkel.

*/


/*

Az ilyen fajta dinamikus array megelőzi a memória leakeket,
	amikor egy vector kimegy a scopeból automatikusan felszabadítja a memóriát amit használt(ha szükséges).
		ez megelőzi a memória szivárgást.

*/


/*

Nem úgy mint a sima dinamikus array esetében ami mivel egy mutató így nem tudja az array hosszát, egy vector megjegyzi az array hosszát
	és lekérhető a size() funkcióval.

*/


/*

Átméretezés,
	nagyon egyszerű a resize() funkcióval.

	! fontos tudni, átméretezéskor a meglévő elemek értékei megmaradnak, és az újak pedig az alapértelmezett értékkel lesznek
		inicializálva, legtöbbször 0-val.

*/


/*

Bool tömörítése,
	az std::vector képes 8 darab boolen típust egyetlen byte-ba tömöríteni.

*/


/*
Konkluzió,
	az std::vector nyújtotta dinamikus array nagyon hasznos, mert automatikusan kezeli a memóriát, ismeri a hosszát,
		valamit még át is lehet méretezni

		! ha lehet ezt használd.



*/