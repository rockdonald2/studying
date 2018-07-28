#include "stdafx.h"
#include <iostream>

/*

Copy initialization,
	tekint a következő pár sor kódra:
		int x = 5,
		ez a kód copy inicializálást használ, hogy az újonnan létrejött x változóhoz hozzárendelje az 5 értéket.

		azonban classok esetében ez egy kicsit jobban komplikált, mivel ezek konstruktőröket használnak az inicializáláshoz.


		a classok esetében lásd pl.

		! azonban a szabály az, hogy teljesen nélkülözd a copy inicializálás használatát, a uniform vagy direct a preferált
*/


/*

Other places copy initialization is used,
	van még néhány hely ahol a copy inicializálást használják, de kettőt különösen fontos megemlíteni, ez az érték szerinti továbbadás/visszaadás.

		lásd pl.

		! kétszer hívodik le a copy konstruktőr, egyszer amikor a makeNegative() funkcióba átadjuk az f paramétert, és még egyszer amikor visszaadódik
			az f.

			- azonban itt is vannak esetek amikor a copy konstruktőr kihagyódik.

*/