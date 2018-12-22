#include "pch.h"
#include <iostream>

/*

Partial template specialization,
	ezt nem nagyon használják, opcionális dolog, de néhány esetben hasznos lehet
	a 13.4-es fejezettel, azaz a template non-type parameterekkel van kapcsolatban

	a példában található program tökéletesen mükődik a legtöbb esetben, azonban mikor string-el próbáljuk csinálni,
		minden string karaktert külön ír, ami nem előnyös, jobb lenne egyben írni
		ezt meglehet oldani template specializationnal is, de akkor explicit módon megkell határozni az array
			hosszát, azaz csak azzal a bizonyos hosszal fog mükődni, ami megint nem jó.

			- ekkor jön képbe a partial template specialization

	ez a fajta template specializálás lehetővé teszi számunkra, hogy specializáljunk classokat(de nem különálló funkciókkat),
		ahol néhány, de nem az összes, a template parameterek közül kifejezetten megvannak határozva
		- ebben az esetben az lenne az ideális, hogy meghatározzuk a char template típust, de a size szabadon marad.

		! fontos tudni, hogy  amikor class templateket hozol létre, és öröklést használsz, mindig használd a
			származtatott classokban a *this mutatót a származtatott változok előtt.
		! vagy használd a typedef-es megoldást ami előtte van.
		- a második példa pedig megmutatja, hogy hogyan lehet egy ilyen funkciót partial templatelni úgy, hogy az a
			classban található, common base class segítségével.
			
*/