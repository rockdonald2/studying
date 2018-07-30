#include "stdafx.h"
#include <iostream>

/*

Shallow copying,
	az alapértelmezett copy konstruktőr, valamint az alapértelmezett hozzárendelési operátor használja ezt a fajta copy metódust, másnéven
	memberwise copy.
		- ez esetben minden tagja a classnak egyenként lesz másolva.

		Amikor a classok egyszerűek, azzaz nem használnak dinamikusan elosztott memóriát, ez nagyon jól mükődik.

			- mivel ezeket a compiler magától hozzáadja a classhoz, nincs is nagy értelme magunk megírni ezeket.

	Azonban amikor a classunk dinamikus memóriát használ, a shallow copy rengeteg gondot okozhat.
		- mivel, a shallow másolata egy mutatónak, csak a mutató címének a másolata - nem foglal le semmilyen memóriát, vagy másolja a tartalmát
			amire mutat.

*/

/*

Deep copying,
	ennek a problémának az egyik megoldása a deep másolás.
		Deep másolás során memória osztódik el a másolatnak, majd másolja a tényleges értéket, így a másolat egy elkülönített memóriában él a forrástól.

			lásd pl.


		Nagyon sok hasonlóság van a copy konstruktőr és a hozzárendelési operátor között, de van különbség:
			- önhozzárendelés check
			- return *this, hogy összeláncolható legyen
			- kifejezetten törölnünk kell minden értéket amit a string már tartalmaz



	! azonban, classok a standard könyvtárban amik foglalkozna dinamikus memóriával, mint pl. a std::string vagy az std::vector,
		kezelik a saját memóriájukat, és van overloadolt hozzárendelési operátoruk és copy konstruktőrjük.
		- szóval ahelyett, hogy magad intéznéd ezeket, használd ezeket.
*/
