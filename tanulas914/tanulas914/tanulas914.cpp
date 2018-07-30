#include "stdafx.h"
#include <iostream>

/*

Szóval az hozzárendelési operátort= arra használjuk, hogy egy értéket egy objectből átmásoljunk egy másik már létező objectbe.

	Assignment vs Copy constructor,
		a különbség a hozzárendelés és a copy konstruktőr között nagyon egyszerü:
			- a hozzárendelés modosít egy már létező objectet, míg a copy konstruktőr létrehoz egy új objectet egy másik alapján.

			összefoglalva:
				- ha az új object létre kell jöjjön mielőtt a másolás megtörténne -> copy konstruktőr
				- ha az új object nem kell létre jöjjön mielőtt a másolás megtörténne -> assignment operátor

				lásd pl.

*/


/*

Self-assignment,
	C++ engedélyezi az önhozzárendelést.

	ez esetben egy object saját magához lesz hozzárendelve.

	ez még normál esetben semmi problémát nem szül, amíg nem dolgozunk dinamikusan elosztott memóriával.

		- ez esetben ha egy objectet saját magával probálunk meg hozzárendelni, akkor rossz outputot kapunk.
		- lásd net.


	Detecting and handling self-assignment,
		azonban szerencsére észrevehetjük ha önhozzárendelés történik, lásd pl. ahová beépítettük ezt.

*/


/*

Default assignment operator,
	nem úgy mint más operátorok esetében, a compiler biztosít egy alapértelmezett publikus hozzárendelési operátort.
	ez is memberwise hozzárendelést biztosít, csakúgy mint a copy konstruktőr.

	úgy mint más konstruktőrök és operátorok esetében, meg tudod előzni a hozzárendelést az által, hogy törlöd vagy priváttá teszed az operátort.

*/