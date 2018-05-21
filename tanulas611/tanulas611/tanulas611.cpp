#include "stdafx.h"
#include <iostream>


/*

változó hivatkozás(reference variable),
	két alapvető változó típust ismertünk eddig: normál változó, és mutató.

		a harmadik a változó hivatkozás ami úgy viselkedik mint egy álnév egy adott értéknek vagy tárgynak.
			három féle van: hivatkozás egy non-konstans értékre, hivatkozás egy konstans értékre, r-érték hivatkozás.

*/


/*

Hivatkozás egy non-konstans értékre,
	egy ilyent úgy hozzunk létre, hogy a hivatkozás típusa és neve közé egy &-t rakunk.

		séma: adattípus &hivatkozásneve = érték;

*/

/*

Hivatkozások mint álnevek,
	egy hivatkozás általában úgy viselkedik mint a változó amire hivatkozik.
		olyan mint egy álnév az adott tárgyra amire hivatkozik.

*/


/*

l-érték, illetve r-érték,
	l-értékek olyan tárgyak amelynek van egy meghatározott memória címük(pl. változók) ami fenáll egy egyedüli kifejezés mögött.
	r-értékek, olyan ideiglenes értékek amelyeknek nincs egy meghatározott memória címük, és csakis expression scopejuk van.
		r-értékek tartalmazzak a kifejezés értékét(pl. 2+3), de a betüket is.

*/

/*

a hivatkozásokat muszáj inicializálni,
	egy non-konstans hivatkozást csak non-konstans l-értékkel lehet inicializálni, nem lehet sem konstans l-értékkel, vagy r-értékkel.

		int x = 5;
		int &ref1 = x; // okay, x is an non-const l-value
 
		const int y = 7;
		int &ref2 = y; // not okay, y is a const l-value
 
		int &ref3 = 6; // not okay, 6 is an r-value

*/


/*

Miután egy hivatkozást inicializáltál, nem lehet módosítani, hogy más változóra hivatkozzon.

	int value1 = 5;
	int value2 = 6;
 
	int &ref = value1; // okay, ref is now an alias for value1
	ref = value2; // assigns 6 (the value of value2) to value1 -- does NOT change the reference!

*/


/*

Hivatkozások mint funkció paraméterek,
	hivatkozásokat legtöbbször úgy használják mint funkció paramétereket, mert így a hivatkozás paraméter úgy viselkedik mint egy álnév
		az adott érvre, és nem úgy mint egy másolat az érvről amit továbbadtak mint paraméter.
			ez így sokkal teljesítménybarátabb ha az érv nagy, vagy drága másolni.

			#include <iostream>

			// ref is a reference to the argument passed in, not a copy
			void changeN(int &ref)
			{
			ref = 6;
			}

			int main()
			{
			int n = 5;

			std::cout << n << '\n';

			changeN(n); // note that this argument does not need to be a reference
			// prints 6
			std::cout << n << '\n';
			return 0;
			}


			Akárcsak egy paraméterként továbbadott mutató, a hivatkozás általi továbbadás is képes az eredeti változó értéket módosítani.

			! adj tovább érveket non-konstans hivatkozások által ha az érvet módosítania kell a funkciónak
*/


/*

Hivatkozások használata ahhoz, hogy C-style arrayokat adjunk tovább funkcióknak,
	a legrosszabb dolog a C-style arrayokra vonatkozóan, hogy leépülnek egy mutatóvá amikor kiértékelik.
		ha hivatkozásként adjunk tovább akkor ez a leépülés nem valósul meg.

			! ahhoz, hogy ez müködjőn a paraméterben meg kell határozni az array hosszát

*/


/*

Hivatkozások mint rövidítések,
	egy másodlagos, sokkal kevesebbszer használt, célja a hivatkozásoknak, hogy könnyebb elérést biztosítsanak a fészkelt adatokhoz.
		pl. structok esetében	: other.something.value1 = 5;
								  int &ref = other.something.value1;
								  ref = 5;

*/


/*

Hivatkozások vs. mutatók,
	a hivatkozás úgy mükődik mint egy mutató ami magától dereferencelve lesz amikor elérik.
		int value = 5;
		int *const ptr = &value;
		int &ref = value;

			*ptr = 5;
			ref = 5; // a kettő ezután ugyanaz.

			mivel a hivatkozásokat muszáj egy érvényes tárgyhoz inicializálni és nem lehet null, ez által sokkal biztonságosabbak mint
				a mutatók.

			ha egy dolog mindkettővel megoldható, jobb a hivatkozást használni.

*/


/*
Összefoglaló:
	a hivatkozások teret adnak arra, hogy álneveket alkossunk más tárgyakhoz vagy értékekhez.
		Egy non-konstans értékre mutató hivatkozást csakis non-konstans l-értékkel lehet inicializálni.
		a hivatkozásokat nem lehet újrainicializálni.

	a hivatkozásokat legtöbbször funkció paraméterként használják, ha a funkció modosítja egy adott érv értékét,
		vagy amikor el akarjuk kerülni, hogy másolni kelljen az eredeti érvet.


*/