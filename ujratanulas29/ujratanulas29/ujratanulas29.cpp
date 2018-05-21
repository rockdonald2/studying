#include "stdafx.h"
#include <iostream>

/*

konstants értékek: olyan értékek amelyeknek az értéke nem változtatható meg
		const kulcsszóval tudjuk ezt iktatni	

			a const értékek nem lehet modosítani, compile error-t okoz
			nem lehet uninitialized const értékek felvenni.

*/

const double gravitacio{ 9.8 }; // a const szót a típust előtt használjuk, lehet utána is, de az kevésbé olvasható.


// legtöbbször a const étékek funkció paraméterként használjuk:

void kiirEgeszSzam(const int enErtek)
{
	std::cout << enErtek;
}  // ez két dolgot biztosít: 1. megmondja a felhasználónak aki lehívja a funckiót, hogy azt az értéket nem lehet modosítani.
							// 2. bebiztosítja, hogy a funkció nem modosítja az értéket.


/*

két féle constanst van: compile-time, és runtime constants
	constexpr kulcsszóval bebiztosítjuk, hogy az a konstants csakis compile-time típusú lehet!

*/

constexpr double gravitacio2(9.8); // compile-time konstants
constexpr int osszeg = 4 + 5; // compile-time konstants

/*
void funkcio()
{
	std::cout << "Ird be a korod: ";
	int age;
	std::cin >> age;
	constexpr int enKor = kor; // nem lesz jó, ez egy runtime constant, a kor-t nem lehet meghatározni compile idején.
}
*/


/*

Minden olyan változó ami nem változtathatja meg az értékét, és aminek a kezdőértéké ismert compile-time idején constexpr
Minden olyan változó ami nem változtathatja meg az értékét, és aminek a kezdőértéke ismeretlen compile-time idején const.

*/



/*

Szimbolikus konstantsok: mágikus számok helyet használjuk, egy konstants literal értékhez adott különleges név
		két féle módon lehet őket deklarálni: objlect-like macros módon, és consts variables-el.

		1. módnak kerüld, két hibája van: nehezebb debuggolni, és elnevezés hibákat(naming conflict)-ot okozhat

*/


/*
#define MAX_TANULO_PER_OSZTALY 30	// object like macros
int max_tanulo = tantermekSzama * MAX_TANULO_PER_OSZTALY;  
*/

/*

constexpr int maxTanuloPerOsztaly { 30 };    // const variables
constexpr int maxNevHossz { 30 };

*/