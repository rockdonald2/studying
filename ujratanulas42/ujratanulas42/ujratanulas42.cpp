#include "stdafx.h"
#include <iostream>

/*

egy funkción kivül meghatározott változó a globális változó.
	a globális változóknak static durationje és file scopeja van.
		azaz static duration = létrejön mikor a program elindul, megsemmisül mikor véget ér.
		azaz file scope = csak abban a fájlban látható ahol létrehozták.

*/

/*

globális változókat az includeok alatt, de minden kód fölött hozunk létre,
	általában használunk rajtuk egy g_ prefixet.

*/

/*

a változóknak van egy harmadik sajátosságuk: linkage
	a linkage határozza meg, hogy egy azonosító többszöri megjelenése ugyan arra a változóra vonatkozik-e vagy sem.
		egy linkage nélküli változó pl. a helyi változó, azaz csak abban a limitált scopeban lehet vonatkoztatni rá.
		két azonos nevű változónak különböző funkciókban nincs linkage-e.
			egy internális linkage-el rendelkező változó, az internal variable(internális változó), bárhol használható az adott fájlban
																									ahol létrejött, de azon kivül nem.
			egy externális linkage-el rendelkező változó, az external variable(externális változó), használható az adott fájlban ahol létrejött,
																									sőt azon kivül is más fájlokban.

ha internal variable-t hozunk létre használhatjuk a static kulcsszót.
ha external variable-t hozunk létre használhatjuk az extern kulcsszót.
	
		standard szerint, egy funkción kivül létrehozott nem konstans változó externális, de egy ugyanilyen konstans változó már internális.


			ahhoz, hogy egy másik fájlban tudd használni az externális változót forward declarationt kell használnod.
				azaz újra felírni ugyanazt, csak initialization érték nélkül(zárójeles érték nélkül).


funkcióknak is ugyan olyan linkage-e van mint a változóknak.

file scope - internal linkage változó
global scope - external linkage változó

*/


/*

amikor konstans értékeket határozol meg egy header fileban, ha nem áll útjába az optimalizációnak,
	a konstans értékeket jobb egy .cpp fájlban meghatározni, és már csak a forward declarationöket belerakni a .h fájlba.
		mind a kettő ugyanúgy fog kinézni, csak a .h fájlban már nem lesznek zárójelek a változók után, azaz nincs initialization érték és
			tartalmaznia kell header guardot is.

*/

/*

// Uninitialized definition:
int g_x;        // defines uninitialized global variable (external linkage)
static int g_x; // defines uninitialized static variable (internal linkage)
const int g_x;  // not allowed: const variables must be initialized

// Forward declaration via extern keyword:
extern int g_z;       // forward declaration for global variable defined elsewhere
extern const int g_z; // forward declaration for const global variable defined elsewhere

// Initialized definition:
int g_y(1);        // defines initialized global variable (external linkage)
static int g_y(1); // defines initialized static variable (internal linkage)
const int g_y(1);  // defines initialized static variable (internal linkage)

// Initialized definition w/extern keyword:
extern int g_w(1);       // defines initialized global variable (external linkage, extern keyword is redundant in this case)
extern const int g_w(1); // defines initialized const global variable (external linkage)

*/