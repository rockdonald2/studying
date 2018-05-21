#include "stdafx.h"
#include <iostream>

/*
1
random number generation,
	véletlenszerű számot elég egyszerű létrehozni alapfokon a c++-ban.
		fogunk egy kezdő számot(amit seednek hívunk), és különféle matematikai müveletek végzünk rajta, újra és újra,
			így hozva létre véletlenszerű számok sorozatát.
				ha elég komplex az általunk létehozott algoritmus, képesek vagyunk elég korrekt számokat létrehozni.

*/

/*
2
a c++-ben van beépített véletlenszerű számgenerátor, ami a <cstdlib> headerben található.

	két paranccsal dolgozik:
		srand() - beállítja a kezdő seedet.
		rand() - létrehozza a véletlenszerű számot 0 és RAND_MAX között ami általában 32768

*/

/*

Ha megfigyeljük a 2-ik példánál, az output, azaz a véletlenszerű számok sorozata, mindig úgyanaz az lesz.
	van amikor ez kívánatós, pl. tudományos szimulációk, vagy debugolás.

	de van amikor nem, pl. egy hi-lo játék esetében.
		ennek a megoldására kezdő seedként az órát állítjuk be
			ami a <ctime> headerben van, és a time() paranccsal használjuk.

*/

/*
4
Általában mi két szám között akarunk véletlenszerű számokat generálni, erre egy külön funkciót kell írni, ami
	egy min és egy max érték között számol véletlenszerűket.

*/


/*

Milyen egy jó PRNG?
	Első, egy jó PRNG minden számot azonos valószinűséggel kell generáljon, ez hívjuk egyenletes elosztásnak.
	Második, a módszer amivel a következő számot generálod nem szabad egyértelműnek lennie.
	Harmadik, egy jó PRNG-nek egy széles skálájú értéktartománya kell legyen, összevissza kell annak kicsi, közepes, és nagy számokat dobnia.
	Negyedik, minden PRNG periódikus, azaz egy bizonyos idő után ismétli önmagát, egy ilyen sorozatnak a hosszát hívjuk periódusnak.
		egy jó PRNG-nek hosszú periódusa kell legyen minden seed számhoz.

*/

/*

Egy a sima rand()-nál megfelelőbb PRNG a Mersenne Twister.

*/

/*

Egy PRNG-vel müködő program debugolása nehéz,
	lehet egyfajta sorozattal mükődik, mással nem.
	ezért ajánlatos egy fix rossz sorozattal mükődni debugoláskor.
		pl. srand(0);

*/

/*
5
rengeteg különféle PRNG található meg a c++11-ben a <random> headerben.

*/