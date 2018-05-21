#include "stdafx.h"
#include <iostream>


/*

C-style string symbolic constants,
	lehet normál módon létrehozni egy C-style stringet, és lehet const-ként is.
		a memória elhyezésükben van kis eltérés.
			amikor egy normált elhelyez a memóriában, a program lefoglal egy n hosszúságú arraynak helyet a memóriában,
				majd incializálja a stringgel ( "pelda\0" ). Ebben az esetben tudod változtatni az array elemeit.
				Az arrayt általában úgy kezeli mint egy normál helyi változót, amikor kilép a scopeból nem tudod elérni,
					így felszabadítja a számára lefoglalt memóriát.

			amikor symbolic constant, ez esetben a stringet egy csak olvasható(read-only) memóriába teszi,
				majd készít egy mutatót ami erre a memóriacímre mutat. A symbolic constant stringet nem tudod később változtatni.


				! nyugodtan használhatod a C-style string symbolic constant-t ha csak olvasható stringre van szükséged a programodban
					de mindig const-tá tedd őket

*/


/*

az std::cout és a char mutatók viszonya,
	a cout végez néhány feltételezést a szándékodról. 
		Ha egy non-char mutatót akarsz kiírni, simán kiírja az adott mutató tartalmát, azaz a memória címet,
			de ha char mutatót akarsz kiírni azt fogja feltételezni, hogy te egy stringet szándékozol kiírni,
				így ahelyett, hogy memória címet írna ki, kiírja a stringet.

*/