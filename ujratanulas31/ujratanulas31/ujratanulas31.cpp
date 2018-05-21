#include "stdafx.h"
#include <iostream>

/*

matematikában, egy müvelet ( operation ) az egy matematikai számítás, ami magába tömörít nullát vagy több bemenő értéket ( operands ), ami létrehoz
																																	kimenő értéket.
		A müveleti szimbólumokat ( +,-) hívjuk operátoroknak ( operator ).
					ezek ugyanúgy mükődnek mint a rendes matematikában.

		az a sorrend ami szerint elvégzi ezeket a műveletek elsőbbségi sorrendnek hívjuk ( operator precedence ).
			ha két müveleti szimbólumnak ugyanaz az elsőbbsége, akkor a müveleti asszociativítás ( operator associativity ) dönti el, 
														hogy jobbról balra, vagy fordítva végezze el.


				! szabály:
						ha a kifejezésed használ különböző operátorokat, használj zárójeleket, hogy tisztázd milyen sorrendben
						tervezted a műveleteket elvégezni, akkor is ha technikailag feleslegesek.
*/

/*

QUIZ

		zárójelekkel jelöld melyikek végződnek el először:
			a) x = ((3 + 4) + 5);
			b) x = (y = z);
			c) (z *= ((++y) + 5));
			d) ((a || (b) && (c) || d;))

*/