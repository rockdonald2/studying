#include "stdafx.h"
#include <iostream>

/*

auto kulcsszó,
	az auto kulcsszó c++11 előtt, csak egy kibővített út volt ahhoz, hogy meghatározzuk egy helyi változó automatic durationjét.
		értelmetlen volt.

	az auto kulcsszó c++11 után, nagyon hasznos, mivel mikor meghatározol egy változót, az auto szót lehet használni az adattípus helyén
		majd a meghatározott értékből ki találja melyik a legmegfelelőbb típus az adott értékre.
			pl. auto szam = 5.0; // mivel az 5.0 egy double szám, így double típust fog hozzárendelni az auto szó.
				ez akár mükődik return esetén is.

				fontos tudni, hogy az auto szót csak inicializált, vagyis értékileg meghatározott, változóknál lehet használni.
					pl. auto szam; nem mükődik.
						de auto szam = 1; mükődik és int lesz az auto választása.

				fontos tudni, hogy az auto szót nem lehet használni funkció paraméterek esetében.

	c++14 után, nem csak változóknál, de funkcióknál is lehet használni az auto szót, hogy magától válassza ki a return típust.
		de ezt jobb elkerülni, mert több hibához vezethet, de változók esetében jó.

*/