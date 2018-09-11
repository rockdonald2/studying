#include "pch.h"
#include <iostream>

/*

Általánosságban, az derived class minden viselkedését(funkciók) örökli a base classnak.

	Calling a base class function,
		amikor lehívunk egy tag funkciót egy Derived class objectekre, először a Derived classban keresi az adott funkciót,
			ha nem találja meg, akkor szépen elkezd az öröklési láncon keresni, és azt használja fel amit legelőször megtalál.

		lásd pl.
			- ez a használat azt jelenti, hogyha a Base class viselkedési elegendő akkor csak használhatjuk azt.


	Redefining behaviors,
		ha meghatároztunk volna egy identify funkciót a derived classban az lett volna használva.
		ahhoz, hogy modosítsunk egy funkciót ami a Base classban volt létrehozva simán létrehozzuk a derived classban is.

			! fontos megjegyezni, hogy ebben az esetben amikor újrahatározunk egy funkciót az öröklödő classban,
				az adott funkció access specifierje nem marad meg, nem öröklődik, hanem olyan lesz ami alatt meghatároztuk az öröklödő classban.
					azaz, egy privát funkció a base classban lehet publikus a derived classban, vagy fordítva.

					lásd pl.



	Adding to existing functionality,
		Néhány esetben nem akarunk teljesen lecserélni egy base class funkciót a derived classban, hanem plusz funkcionalítást hozzáadni.
		a példában található esetben a derived class identify() funkciója teljesen elrejti a base class identify() funkcióját, ez nem mindig jó.
		plusz funkcionalításhoz, simán lehívjuk először a base class funkcióját majd plusz funkcionalítást adunk hozzá.
			ahhoz hogy lehívjuk a class nevét + a scope qualifier operátort használjuk.


		úgyanakkor, amikor friend funkciókkal akarjuk használni ezt a fajta lehívást, nem fog mükődni, ehelyett static_cast-et kell használjunk,
			hogy a derived class objectet Base classá alakítsuk.
				lásd pl.
*/