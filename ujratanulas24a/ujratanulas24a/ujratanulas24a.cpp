#include "stdafx.h"
#include <iostream>

/*

ide tartoznak a meghatározott(lefixált) skálájú egész számok

		4 ilyen van, 8 unsigneddel.
		int8_t, int16_t, int32_t, int64_t
		uint8_t, uint16_t, uint32_t, uint64_t

				! sajátos headerrel lehet elérni ezeket, neve cstdint

				figyelj: az int8_t gyakran char-ként jelenik meg. Kerüld a használatát.


		a meghatározott skálájú egész számok nem biztos, hogy támogatottak minden achitekturán, vagy lehet nem annyira performansak.
*/


#include <cstdint>

int main()
{
	std::int16_t i(5);
	std::cout << i << '\n';
	return 0;
}


/*

		gyors és legkisebb ( fast and least)

		int_fast#_t biztosít számodra egy egész számot ami a leggyorsabb típus minimum # bitnyi bőséggel.
				például: int_fast32_t biztosítja számodra a leggyorsabb 32 bites egész szám típust.

		int_least#_t biztosít számodra egy egész számot ami a legkisebb típus minimum # bitnyi bőséggel.
				például: int_least32_t biztosítja számodra a legkisebb egész szám típust ami min. 32bites.

*/


/*

egész számok használati tippek:

		int-et használj ha, nem számit az egész szám mérete, például ha kort kérsz le, vagy számolsz 1től 10ig, akkor nem számít, hogy
		az int 16-os vagy 32-es, egyformán be fog férni a skálájába, a legtöbb esetben ez elég lesz.

		int_fast, ha a változód garantálva van, hogy egy bizonyos méretet tölt ki, és a teljesítményt preferálod
		int_least, ha a változód garantálva van, hogy egy bizonyos méretet tölt ki, és preferálod a memória megőrzést, a teljesitménnyel szemben.
			ez a legjobb ha sok változónak utalsz helyet

		csak akkor használj unsigned változót, ha van egy kényszerítő indokod.

*/