#include "pch.h"
#include <iostream>

/*

std::initializer_list,
	képesek vagyunk használni initializer listet dinamikus, valamint hagyományos arrayekkel, azonban
		az előzö leckében létrehozott saját array konténer classunkkal nem.

	a C++11 előtt ez nem is volt lehetséges, azonbán utána az std::initializer_list-el lehetséges

	amikor a compiler lát egy initializer list-et, azt automatikusan átalakítja az std::initializer_list típusba,
		tehát, ha mi létrehozunk egy konstruktőrt ami egy std::initializer_list paramétert fogad be,
		létrehozhatunk objecteket initializer list használatával

		az std::initializer_list az initializer_list headerben található meg

			 ! fontos, akár az std::array-nél, vagy vectornál, az initializer_list-ben is kifejezetten megkell határoznod
				az adattípust kacsacsőrőkben, 
					pl: std::initializer_list<int>

			az std::initializer_list tartalmaz egy size() funkciót ami a hosszát adja vissza, azaz az elemek számát a listából

*/

/*

Class assignment using std::initializer_list,
	használhatjuk arra is ezt a listát, hogy új értékeket rendeljünk hozzá egy classhoz az által, hogy overloadoljuk
		a hozzárendelési operátort egy std::initializer_list paraméterrel


		! fontos, ahhoz, hogy beépíts egy konstruktőrt ami egy std::initializer_list-et használ,
			biztosíts be, hogy legalább egyet az alábbiak közül teljesítesz:
				- biztosítasz egy overloadolt lista hozzárendelési operátort
				- biztosítasz egy rendes deep-copy copy hozzárendelési operátort
				- kifejezetté teszed a konstruktőrt, hogy ne lehessen használni magától értetődő átalakításokra

*/