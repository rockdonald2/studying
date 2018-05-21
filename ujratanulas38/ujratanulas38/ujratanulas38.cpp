#include "stdafx.h"
#include <iostream>

/*

bit manipuláló operátorok, manipulálnak, megváltoztatnak, befolyásolnak, egyéni biteket egy változon belül.
	egy kis történet, régen a memória drága volt, így ösztönző volt, hogy a memóriának minden kis bitje értékesen legyen felhasználva
		vegyünk egy bool típust, ami hiába foglal csak el 1 bitet, a memóriában 1 teljes byte-ot kitölt, azaz 7 bit kárba vész.
			a bit manipulálásával lehetővé válik, hogy 8 bool típust szórítsunk 1 byte-os változóba.
				ez régen hasznos volt, manapság már kevésbé, mivel a memória elérhetőbbé vált, és így a programozók inkább írnak
					olyan programokat amiket könnyű karbantartani és megérteni, mint ami hatékony.
						csak olyankor használják amikor a maximális optimalizáció szükséges.


		6 darab van belőle: left shift, right shift, bitwise NOT, bitwise OR, bitwise AND, bitwise XOR
							   <<         >>            ~           |              &           ^


		bit manipuláció esetén egyértelműen csakis unsigned egész típusú adatot használj.
	

*/


/*

Bitwise left shift, és bitwise right shift operátorok.
	a bitwise left shift operátor arébb "tolja"(váltja) a bitek bal oldal felé.
		pl. ha 3 << 1, akkor azt mondjuk a gépnek, hogy váltsa balra 1 pozicióval a 3-ban található biteket.
			tehát, 3 = 0011, és 3 << 1 = 0110, vagy 3 << 2 = 1100, vagy 3 << 3 = 1000
					! azok a bitek amik kicsúsznak tolás esetén örökre elvesztődnek.

	a bitwise right shift operátor jobbra váltja a biteket.
		pl. ha 3 = 0011, és 3 >> 1 = 0001

		fontos megjegyezni, hogy változoknak a bitjeit is lehet váltani.

*/


/*

Bitwise NOT operátor,
	legkönnyebb megérteni, csak átváltja minden bitet az ellentétére, 1-ből 0-át csinál, vagy fordítva.

*/


/*

Bitwise AND és OR operátor,
	hasonlít a logikai AND operátorhoz, és OR operátorhoz.
		pl. 5 | 6, tehát ha az oszlopban valamelyik 1, vagy mindkettő akkor az az oszlop 1 lesz, ha mindkettő 0 akkor 0.
			tehát 0101
				  0110
				  0111 - 7
			5 & 6, ugyanúgy mükődik csak itt mindkettő 1kell legyen ahhoz ,hogy az oszlop is 1 legyen.
					0101
					0110
					0100 - 4
*/


/*

Bitwise XOR operátor,	
	hasonlóan mükődik mint az OR operátor, exkluzív OR-nak is nevezik.
		az oszlop csak akkor lesz 1, ha csakis egy operándusa 1, összetett kifejezések esetén pedig akkor ha páratlan számú 1-esek vannak.
			pl:
				0101
				0110
				0011 - 3

*/


/*

Bitwise hozzárendelési(assignment) operátorok
	<<=, >>=, |=, &=, ^=
		gyors hozzárendelést könnyítik meg
			pl. x = x << 1 helyett x <<= 1

*/
