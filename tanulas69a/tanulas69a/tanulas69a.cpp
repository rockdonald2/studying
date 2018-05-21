#include "stdafx.h"
#include <iostream>

/*

Dinamikus elosztásű array,
	egy ilyen elosztású array esetében elég ha az array hosszát runtime idején tudjuk

		ahhoz, hogy elhelyezzünk és felszabadítsunk dinamikusan egy arrayt, használjuk a new[] és delete[] operátort.

*/


/*

A dinamikusan elosztott arrayek nagyon hasonlóak a fixed arrayekhez,
	egy dinamikusan létrejött array úgy kezdi életét mint egy mutató, ami az array első elemének címére mutat.
		úgyanolyan korlátozottságai vannak mint egy leépült arraynek, azaz a mutatóból nem derülhet ki az array hossza, vagy mérete.
		egy különbség van, a dinamikus arrayt manuálisan kell felszabadítani a delete[] operátorral.

*/



/*

Dinamikusan eloszott arrayek inicializálása,
	ha egy dinamikusan elosztott arrayt akarsz 0-val inicializálni a séma elég egyszerű:
		int *array = new int[length]();

	c++11-től lehetséges dinamikus arrayek esetében intializer list-et használni.
		int *array = new int[5] { 9, 7, 5, 3, 1 };
			! vigyázz, nincs egyenlő a típus és a lista között

				! nem tudsz c-style stringet létrehozni dinamikusan elosztott char arrayhez.
					char *array = new char[14] { "Hello, world!" }; // doesn't work in C++11

*/

/*

Egy dinamikusan létrehozott array engedélyezi, hogy lefoglalás idején add meg a hosszát, azonban a c++ nem ad egy beépített módot arra,
	hogy átméretezz egy már lefoglalt arrayt.

	! magadtól is csinálhatod, de jobb elkerülni

	Szerencsére, az std::vector-ral már ez is lehetséges, ad egy átméretezhető arrayt.

*/