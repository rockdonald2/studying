#include "stdafx.h"
#include <iostream>

/*

Enumerated types,
	egyike a felhasználó által meghatározott adattípusoknak(user-define data types)-
		ez egy szimpla felsorolás, amit az enum kulcsszóval jelölünk, minden felsorolt szimbolikus konstans érték.
			

*/

enum TesztFelsorolas // így kezdjük el, enum kulcsszó majd a felsorolás neve, általában nagy betüvel kezdjük.
{ // fontos a zárójel
	TESZT1, // ezek a felsoroltak
	TESZT2, // ezek a meghatározott értékek amiket tartalmazhat
	TESZT3, // általában csak nagybetüvel írjuk
	TESZT4, // vesszővel választjuk el egymástól, nem semicolonnel.
	TESZT5, // de általában valami prefixet is használunk hozzá: PREFIX_FELSOROLTNEVE
}; // fontos az utolsó zárójel után semicolon, amivel lezárjuk

// hozzárendelési példák
	// TesztFelsorolas teszt = TESZT1;
	// int teszt = TESZT1;

/*

Minden felsoroltnak saját szám értéke van, ha nem határozunk meg mi egyet az = -vel, akkor 0-tól kezdi az elsőtől, és mindengyik
	tag eggyel nagyobb az előzőnél.
		lehetséges két tagnak ugyan az az érték, de ezt jobb elkerülni.

	Ahhoz, hogy szövegként írjuk ki a felsorolást if / else if / else vagy switch-et kell használnunk és úgy kiírni.

		pl:
			void kiIrTeszt(TesztFelsorolas teszt)
			{
				if (teszt == TESZT1)
					std::cout << "szöveg";
				else if ( teszt == TESZT2)
					std::cout << "szöveg";
				else
					std::cout << "más szöveg";
			}
				de majd switchel könnyebb lesz.

*/


/*

Mivel a felsorolás számára nem foglal le memóriát a compiler, és így nem lehet forward declarálni,
	 ha több fájlban használni akarjuk tanácsos egy header fileba belefoglalni.

*/