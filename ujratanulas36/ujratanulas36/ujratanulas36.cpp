#include "stdafx.h"
#include <iostream>

/*

logikai operátorok: 
	ezekkel az operátorokkal tudunk több kondicíót egyszerre vizsgálni.
		három darab logikai operátor van: LOGICAL NOT !
										  LOGICAL AND &&
										  LOGICAL OR ||
*/


/*

LOGICAL NOT, a logikai tagadás operátor, megfordítja egy boolean érték értékét, igazról hamisra vagy fordítva.
		lehetőleg mindig használj zárójelet, mert magas elsőbbségi rangjuk van!

*/


/*

LOGICAL OR, arra használjuk ,hogy megvizsgáljuk bármelyik kondició igaz-e a belefoglaltak közül.
	ha csak egyik igaz akkor is true-t add vissza, ha mind a kettő akkor is
		csak akkor add vissza false-t, ha mind az egész kondició hamis.

*/


/*

LOGICAL AND, arra használjuk, hogy megvizsgáljuk, hogy mindegyik kondició igaz-e.
	ha mind a kettő igaz, akkor igazat add vissza
		ha csak egyik, vagy egyiksem akkor hamisat.

*/


/*

Figyelj mikor kevered egy állításban az AND és OR operátorokat, legjobb ha zárójelet használsz, hogy tisztázd a szándékaidat.

*/

/*

De Morgan szabály!
	!( x && y ) egyenlő !x || !y
	!(x || y) egyenlő !x && !y

*/