#include "stdafx.h"
#include <iostream>

/*

összefüggő operátorok, azaz összehasonlítók.
	6 darab van belőlük, elég egyértelműek: nagyobb, kisebb, nagyobb vagy egyenlő, kisebb vagy egyenlő, egyenlő, nem egyenlőve.
											>			<			>=					<=					==		!=
*/


/*

egész számokat elég egyértelmű összehasonlítani ezekkel az operátorokkal.

*/

/*

DE!, floating point számoknál veszélyes, a jelentkező kerekítési hibák miatt.
			a kacsacsőröket lehet használni, valódi számok esetén is, de az egyenlő, és nem egyenlő operátorok relatíve pontatlanok.

			ezért külön funkciót kell használni a valódi számok összehasonlítására.

*/