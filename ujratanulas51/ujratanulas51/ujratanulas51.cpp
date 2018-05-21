#include "stdafx.h"
#include <iostream>

/*

a program lefolyásának, áramlásának befolyásolása,

	amikor elindítsz egy programot, a program sorra veszi a main()-ben található kifejezéseket és végrehajtja őket, majd véget ér a program
	a main() végével. A kifejezések sorozata amiket a CPU végrehajt, a program végrehajtási útvonalának nevezzük(execution path).
		az eddig oldott programok mind egyenesvonalú programokat voltak, szekvenciális áramlással, azaz mindig úgyanazon az úton hajtódtak
		végre.

	gyakran, szeretnénk olyan programokat létrehozni, amelyeknek olyan adataik vannak amikkel nem rendelkezünk compile-time idején.
		pl. ha kiszeretnénk írni 0tól, egy adott számig, amit a felhasználó beírt, az összes számot, nem tudnánk megtenni míg
			nem ísmerjük a számot a felhasználótól.

	! De szerencsére a c++-nak vannak áramlást kontrolláló állításai, amik segítenek a programozónak, hogy befolyásolja a CPU végrehajtási
	sorrendjét a program során.

*/


/*

Az első ilyen állítás a Halt(leáll),
	ez a legalapabb kontrolláló állítás, ami leállítja a programot.
		a haltot az exit() funkción keresztül lehet használni, ami a <cstdlib> header része.

			az exit() funckió tartalmaznia kell egy egész számot paraméterként, amit visszaad a rendszernek exit codeként,
				úgyanúgy ahogy a return is visszaadja a main() értékét.

	leggyakrabban javíthatatlan hibák jelentkezése esetén állítják le ezzel a programot.


pl.
	int main()
		{
			std::cout << "Kiir valamit";  // ezek a sorok végrehajtódnak
			valamilyenFunkcio();

			exit(0); // véget ér a program, és visszaadja a 0-ást exit codeként a rendszernek

			std::cout << "Kiir meg valamit"; // ezek a sorok soha nem hajtódnak végre
			return 0;
		}
		
		
*/


/*

A második kontrolláló állítás a Jump(ugrás),
	a második legalapabb ilyen állítás, a Jump hatására a CPU egyik állításról a másikra ugrik
	három típusát különböztetjük meg: goto, break, continue.

		! a funkció hívások is jumpokat hajtanak végre, mivel funkció hívás esetén a mainből a végrehajtás a lehívott funckió
		kezdetére ugrik, majd a funkció végrehajtása után, vissza arra a helyre ahol abbamaradt előzőleg.

*/


/*

A harmadik kontrolláló állítás a Conditional Branch(feltételes ág)
	ez egy olyan állítás ami egy adott kifejezés értéke alapján szervezi a program végrehajtását.

	a legalapabb feltételes ág, az If állítás, de ilyen állítás akár a Switch is.

*/


/*

A negyedik kontrolláló állítás a Loop(hurok)
	ez egy olyan állítás ami addig hajt végre egy adott állítás sorozatot amíg a megadott kondició hamis lesz.
	négy fajtát különbözetünk meg: while, do while, for, és for each(ezt majd kicsit később)

*/

/*

Az ötödik fajta kontrolláló állítás az Exception(kivétel)
	a kivétel kinál egy olyan mechanizmust ami segít hibák kezelésében egy funkcióban.
		ha a funkcióban megjelenik egy hiba, amit az nem tud kezelni, a funkció indíthat egy kivételt,
		ez által a CPU egy olyan kód blokkra ugrik, ami képes az ilyen fajta hibákat kezelni.

	ez egy eléggé összetett mechanizmust, majd később fogjuk venni(14.-ik fejezet)

*/