#include "stdafx.h"
#include <iostream>



/*

array,
	egy összesítő(aggregate) adattípus a c++-ban, lehetőséget ad, hogy sok változót tároljunk egy adattípusból egy azonosítón keresztül.

	egy array változó meghatározásakor használunk egy [] zárójelet, hogy megmondjuk a compiler-nek ez egy array változó,
		úgyanakkor a zárójelbe, hogy hány változót tegyen félre, raktározzon. ( ezt hívjuk egy array hosszának )

			pl. int tesztEredmeny[30]; // tegyen félre 30 integer változót egy fix hosszúságú array-ben.
					- ebben a példában létrehoztunk egy fix hosszúságú arrayt tesztEredmeny néven, 30-as hosszúsággal.
						egy fix array egy olyan array amelynek a hosszúságát már compile-time idején is tudjuk.
							amikor lefut a tesztEredmeny[30] akkor a compiler 30 integert fog félretenni ennek az arraynek.

								ugyanaz mintha ezt történne:
									int tesztEredmeny1;
									int tesztEredmeny2;
									....
									int tesztEredmeny30;

*/


/*

A változókat amelyek az array-ben találhatóak elemeknek hívjuk.
	az elemeknek nincs saját, egyedi nevük, ahelyett egyes elemeket elérni egy arrayból úgy lehet, hogy használjunk az array nevét,
		majd a név mellett az indexelési operatort ( [] ), és a paramétert amit indexnek hívunk, ami meghatározza melyik elemet akarjuk.
			ez a folyamat az indexelés.

				a fenti arrayben az első elem a tesztEredmeny[0], az utolsó a tesztEredmeny[29]
					! fontos, a számolás 0-tól kezdődik, és nem 1-től.

					egy N hosszúságú array skálája(range) 0tól, N-1ig terjed

*/


/*

Egy array bármelyik adattípusból felépülhet.
	De ugyanakkor structs-ból is, meg array-ból.
		pl. struct Teglalap
			{
				int hossz;
				int szelesseg;
			}

			Teglalap tgl[5]; // meghatározzunk egy array-t 5 Teglalap-al.

			ahhoz, hogy elérjük a struct tagját egy array elemnek, először kiválasztjuk, hogy melyik array elemet akarjuk,
				majd használjuk a tag kiválasztási operátor(member selection operator), hogy kiválasszuk a struct tagot amit akarunk.

				pl. tgl[0].hossz = 22;

*/

/*

C++-ban, egy array indexe muszáj integral típusú legyen, ide tartozik az char, short, int, long, long long, de akár még egy bool is
	ahol a true index 1 és a false index 0. Egy array indexe lehet akár egy betűszerinti(literal) érték, egy változó, vagy akár
		egy kifejezés ami integral típusú eredményt hoz.

		int array[5]; // declare an array of length 5

		// using a literal (constant) index:
		array[1] = 7; // ok

		// using an enum (constant) index
		enum Animals
		{
		ANIMAL_CAT = 2
		};
		array[ANIMAL_CAT] = 4; // ok

		// using a variable (non-constant) index:
		short index = 3;
		array[index] = 7; // ok

		// using an expression that evaluates to an integer index:
		array[2+3] = 7; // ok

*/


/*

Fix hosszúságú array meghatározása,
	amikor meghatározzunk egy fix hosszúságú array-t, az array hossza(a szám a [] zárójelek között) muszáj egy compile-time konstans legyen.
	Azért mert egy fix array hossza muszáj ismert legyen compile idején.

	// using a literal constant
	int array[5]; // Ok

	// using a macro symbolic constant
	#define ARRAY_LENGTH 5
	int array[ARRAY_LENGTH]; // Syntactically okay, but don't do this

	// using a symbolic constant
	const int arrayLength = 5;
	int array[arrayLength]; // Ok

	// using an enumerator
	enum ArrayElements
	{
	MAX_ARRAY_LENGTH = 5
	};
	int array[MAX_ARRAY_LENGTH]; // Ok

		! nem konstans értékek, vagy runtime konstans nem játszik, nem megfelelő.

*/

/*

Egy fix array esetében két fajta korlátozottság létezik:

	Fix array esetében a hossza nem állítható felhasználó input alapján, vagy bármilyen érték alapján ami runtime idején jön létre.
	Fix array esetében van egy fix hossz amit nem lehet modosítani.

*/