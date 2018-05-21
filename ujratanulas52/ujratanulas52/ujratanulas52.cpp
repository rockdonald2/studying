#include "stdafx.h"
#include <iostream>

/*

If állítás,
	a legalapabb feltételes ág.

*/

/*

Az If állítás két részből áll, egy If részből és egy Else részből(opcionális)
	ha a megadott kondiciónális állítás(conditional statement) igaz, akkor az If hajtódik végre,
		ha false, akkor az Else hajtódik végre.

*/


/*

Ahhoz, hogy az If állítás több állítást hajtson végre használhatunk egy blokkot { }.

*/


/*

Magától értetődő blokkok,
	ha a programozó nem hoz létre egy blokkot, a program magától is létrehozhat egyet.


		! erre vigyázni kell, mivel így egy if állításon belül létrehozott változó nem használható alapból az állításon kivül.
			block scopeja, azaz a blokkból való kilépés után törlődik.

*/


/*

Lehetséges több If-Else állítást összeláncolni.

	pl.
		int main()
		{
			int x = 9;

			if (x > 10)
				std::cout << "A szam nagyobb mint 10";
			else if (x < 10)
				std::cout << "A szam kisebb mint 10";
			else
				std::cout << "A szam pont 10";

			return 0;
		}


		! De szebben, és átláthatóbban írva a felső a következő:

		int main()
		{
			int x = 9;

			if (x > 10)
				std::cout << "A szam nagyobb mint 10";
			else
			{
				if (x < 10)
					std::cout << "A szam kisebb mint 10";
				else
					std::cout << "A szam pont 10";
			}

			return 0;
		}

*/


/*

Lehetséges If állításokat egymásba fészkelni.

	! Itt fontos tudni, hogy a befészkelt Else mindig az utolsó If állításhoz kapcsolódik aminek nincsen párja ugyanabban a blokkban.
		Ha nem így akarod, használj blokkot a megkülönböztetésre.

*/


/*

Használhatod az If állítást több kondició megvizsgálására is, a logikai operátorokkal.

*/


/*

Gyakori felhasználásai:
	gyakran használják hiba ellenőrzésre.

	gyakran használják korai return-re(early returns), amikor a funkció a vége előtt teszi ezt.
		pl. Error kódok, lásd példa 5.2

	gyakran használják egyszerű matematikai függvényekben, mint a min() vagy a max() ami visszaadja a minimumját vagy maximumját
		a paramétereinek.

*/

/*

Lehetséges elhagyni egy adott If állításból az állításokat, ekkor létrehozunk egy null állítást.
	ezt úgy hozhatjuk létre, hogy az állítás helyére pontosvesszőt rakunk.

	Általában akkor használják amikor egy adott nyelv igényel egy állítást, de a programozónak nincs szüksége rá.
	pl.
		if (x > 10)
			;


			! Figyelj arra, hogy véletlenül ne zárd le így az állításaidat.
*/