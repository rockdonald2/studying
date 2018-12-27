#include "pch.h"
#include <iostream>

/*

A try és catch blokkok elég jól mükődnek a legtöbb esetben, de van egy különleges eset amelyben nem elégségesek.
	lásd pl.

	ilyen szituációkban használhatjuk a try blokk kissé megváltoztatott verzióját a function try blokkot.

*/

/*

Function try blocks,
	a funkció try blokkok arra vannak tervezve, hogy lehetővé tegyik, hogy létrehozz egy kivétel kezelőt 
		egy teljes funkció bodyja köré, ahelyett, hogy csak egy kódblokk köré.

		lásd pl.

		- megjegyzés, hogy a catch blokk ugyanazon bekezdési szinten áll, azaz a try blokk illetve a funkció vége
			közötti kivételeket kapja el
		! lényeges különbség, hogy funkció try blokk esetében muszáj egy kivételt dobni a catchből, vagy
			továbbdobni a jelenlegi kivételt.
		! majdnem mindig csak konstruktőr esetében van használva

Don't use function try to clean up resources,
	amikor egy object létrehozása sikertelen, a destruktőr nem lesz lehívva
	tehát, talán kisértésbe eshetsz, hogy ezt a funkció try-t használd az class tisztítására amely részlegesen
		erőforrást foglalt le mielőtt sikertelen lett.
	de, egy sikertelen object tagjaira való hivatkozás nem meghatározott viselkedést okoz(undefined behavior) mivel
		az object "halott" mielőtt a catch blokk végrehajtódna.
	ez azt jelenti, hogy a funkció try nem használható ilyenfajta class takarításra.
	

		! főként arra hasznos, hogy logoljunk hibákat mielőtt továbbadjuk a kivételt a stacken, 
			vagy arra, hogy megváltoztassuk a kivételt típusát

*/