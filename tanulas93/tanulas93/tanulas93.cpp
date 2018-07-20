#include "stdafx.h"
#include <iostream>

/*

Overloading operator<<,
	hasonló mint az operator+ overloadolása, mivel mind ketten bináris operátorok, csak a paraméter típusok különböznek.
	ha veszed az std::cout << Point esetet, a két operándus az std::cout és a Point.
		az std::cout ugye az std::ostream típus objectje.
		szóval az overloadolt funkció valahogy így néz majd ki:
			friend std::ostream& operator<< (std::ostream &out, const Point &point)
			
			lásd pl.

	bármikor amikor bináris operátorokat azt akarjuk, hogy összeláncolhatok legyenek, a bal oldali operándus mindig hivatkozás
		alapján kell legyen visszaadva.

*/


/*

Overloading operator>>,
	hasonló az operator<< overloadolásához, csak itt a típus az std::istream, ennek a része az std::cin.

		lásd pl.

*/