#include "stdafx.h"
#include <iostream>

/*

Összefoglaló lecke, a változók scopejáról, durationjéről, és linkageéről.

*/


/*

Egy azonosító scopeja meghatározza, hogy hol elérhető.

	Egy változó block scopepal(local scopepal) csak az adott blokkon belül elérhető ahol létrejött,
			ide tartozik: helyi változó, funkció paraméterek, és helyileg létrehozott típusok.

	Egy változó global scopepal(file scopepal) az egész fájlban elérhető,
			ide tartozik: globális változó, normális funkciók, valamint globálisan létrehozott típusok.

*/


/*

Egy azonosító durationje meghatározza, hogy hol jön létre és hol semmisül meg.

	Egy változó automatic durationnel létrejön azon a ponton ahol meghatározzák, és megsemmisül mikor kilép a blokkjából,
			ide tartozik: normál helyi változók.

	Egy változó static durationnel létrejön amikor a program elindul és megsemmisül mikor véget ér,
			ide tartozik: globális változó, static helyi változók.

	Egy változó dynamic durationnel létrejön és megsemmisül mikor a program kéri,
			ide tartozik: dinamikus elhelyezett változók (!hatodik fejezet!)

*/


/*

Egy azonosító linkagee meghatározza, hogy a többszöri megjelenési ugyanarra az azonosítóra vonatkozik vagy sem.

	Egy linkage nélküli változó azt jelenti, hogy csak arra vonatkozhat,
			ide tartozik: helyi változók, felhasználó által létrehozott típusok(enum, typedefs, class)

	Egy internal linkageel rendelkező változó bárhol elérhető az adott fájlban,
			ide tartozik: static globális változó, const globális változó, static funkciók.

	Egy external linkageel rendelkező változó bárhol elérhető akár az adott fájlon kivül is(forward declaration),
			ide tartozik: normális funkciók, non-const globális változók, extern const globális változók, felhasználó által létrehozott típusok


				! Néhány fontos tudnivaló:
						a funkciók alapból extern típusuak, internné lehet tenni static kulcsszóval


*/