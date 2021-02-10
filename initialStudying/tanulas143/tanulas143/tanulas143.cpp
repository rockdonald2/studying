#include "pch.h"
#include <iostream>

/*

Ebben a leckében azt vizsgáljuk, hogy hogyan interaktál a kivétel kezelés a funkciókkal

*/

/*

Throwing exceptions outside of a try block,
	az előzö leckében a throw állítások mind a try blokkon belül voltak, ha ez szükséges lenne a kivételeknek csak
		limitált haszna lenne.
	az egyik leghasznosabb tulajdonsága a kivétel kezelésnek az, hogy a throw állításnak nem szükséges közvetlenül
		a try blokkon belül lennie mivel a kivételek a throw után a stacken felfele terjednek.
	ez lehetővé teszi, hogy a kivételek egy sokkal modulárisabb módon kezeljük

		lásd pl.

	A folyamat amikor egy kivétel bukkan fel:
		először, a program elkezdi vizsgálni, hogy a kivételt lehet-e azonnal kezelni(ami azt jelenti, hogy
			egy try blokkon belül volt throwolva). Ha nem tudja, a jelenlegi funkció leáll, és a program leellenőrzi,
				hogy a funkció hívója tudja-e kezelni a kivételt, ha ő sem akkor leállítja a hívót és
				megnézi, hogy a hívó hívója tudja-e kezelni a kivételt.
				Minden funkció így véget ér amíg egy kezelőt nem talál a kivételnek, vagy addig amíg a main() is véget ér,
					anélkül, hogy a kivételt kezelve lett volna. Ez a folyamat az unwinding the stack.

		másik pl.

*/