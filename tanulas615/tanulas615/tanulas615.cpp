#include "stdafx.h"
#include <iostream>

/*

Bevezetés az std::array-be,
	az std::array biztosít egy olyan arrayt ami nem épül le mutatóvá mikor tovább adod egy funkciónak.
		megtalálható az <array> headerben, az std namespacen belül.
			azaz elérhető, ha #include <array> és std::array;

			séma: std::array<arraytípusa, arrayhossz> arrayneve;

			úgyancsak lehet ezt a fajta array típust uniform initialization-nal, és initializer list-el inicializálni.
			! de a sémából nem hagyhatod ki az arrayhosszát, nem úgy mint a sima fix arraynál.

			elérni azonban az elemeket úgyanúgy lehet akárcsak a sima fix arraynál.

			! alapból ez a fajta array se ellenőrzi le, hogy az index amit alakítasz létezik-e, de
				ha használod az at() funkciót ami éred el az elemeket, akkor már ez megtörténik.

				pl. lásd pelda
		
*/


/*

Méret, és rendezés,
	a size() funkció használható, hogy lekérd milyen hosszú egy adott array ebből a típusból.
		! de mivel, ez a fajta array nem épül le mutatóvá mikor továbbadják egy funkcióba, ezért egy funkción belül
			is lehet használni a size()-ot.

		! nem összetéveszteni a sizeof()-al amit a sima fix arraynél használsz.
			a size() visszaadja az array hosszát, a sizeof() pedig az egy elem méretének és az elemek számának a szorzatát


	Mivel a mérete állandóan tudott egy ilyen fajta arraynek a for-each loopok tökéletesen mükődnek.

	Valamint használhatod az <algorithm> headerben található std::sort funkciót is ahhoz, hogy rendezd.
*/


/*
Konkluzió,
	std::array egy remek helyettesítő a sima fix arrayeknek. Hatékony, nem foglal el több memóriát mint a sima.
		egyetlen kisebb gondja az, hogy fura a sémája.

		! használd ezt a sima fixed array helyett.


*/