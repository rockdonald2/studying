#include "stdafx.h"
#include <iostream>

/*

a static kulcsszót a legösszezavaróbb szó az egész nyelvben, mert más helyen mást jelenthet.
	a globális változók esetében a static kulcsszót az internal linkage-re vonatkozik, ami szerint csak az adott programban elérhető a változó.
	a helyi változók esetében a static kulcsszót automatic durationről static durationre vált, ami szerint a változó nem semmisül meg a blokk
		elhagyása után, hanem megmarad, de elérhetetlen lesz.

			gyakorta használjuk egyedi ID-ek megfogalmazásakor.

*/

/*

gyakori prefixe az s_ amivel jelöljük a static durationös helyi változókat.

*/