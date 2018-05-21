#include "stdafx.h"
#include <iostream>

/*

kétféle konstants van a c++-ban: szimbolikus, és betűszerinti. (symbolic, literal)

	először: a betűszerinti,
		olyan értékek amik közvetlenül a kódba vannak iktatva, állandóak(konstantsok) mivel nem tudod megváltoztani az értéküket.
		

*/

void funkcio()
{
	bool azEnNevemZsolt = true; // boolean változó "azEnNevemZsolt"-hoz hozzá van rendelve a boolen betűszerinti állandó "true"
	int x = 5; // az egész szám x-hez hozzá van rendelve az állandó érték az 5-t.
	std::cout << 2 * 3; // 2 és a 3 egész szám betűszerinti állandók( are integer literals)
}

// két féle képpen lehet floating point literals-okat iktatni

void funckio2()
{
	double pi = 3.14159; // a pi egy double literal
	double avogadro = 6.023e23; // az avogadro szám az 6.023 x 10^23
	double elektron = 1.6e-19; // egy elektron töltése 1.6 x 10^-19
}

/*

a számszerű literals-ok-nak lehetnek útótagjai amik meghatározzák a típusát, 
		ezek opcionálisak, általában a compiler képes meghatározni a megfelelő típust.


*/

unsigned int nErtek = 5u; // unsigned int
long nErtek2 = 5L; // long

// alapból a floating point számok double típusúak, az F útótaggal átlehet alakítani őket float-tá.

float fErtek = 5.0F; // float
double d = 6.02e23; // double alapból.

// támogatottak a char-ok és string-ek is:

void funckio3()
{
	char c = 'A'; // char literal
	std::cout << "Hello World!"; // C stílusú string literal
	std::cout << "Hello," " world!"; // a c++ összekapcsolja az egymást követi string literalokat.
}
		// a string literalokat furcsán kezeli a c++, ne próbáld őket értékekekhez kapcsolni, vagy funckiókban használni.

/*

Több számrendszer létezik: 10-es alapú(a rendes), 2-es alapú, 8-as alapú, vagy 16-os alapú.
		lehet számjegyeket szeparálni, elválasztani egymástól a " ' " jellel.

*/

int x = 12; // ez egy 10-es alapú szám
int y = 012; // 8-as
int z = 0xF; // 16-os
int h = 0b1; // 2-es

long value = 2'532'673'462; // sokkal könnyebb olvasni így


/*

mágikus számok: egy olyan beágyazott literal(általában szám) ami ott van a kódban, bármiféle kontextus nélkül.
		lehetőleg kerüld.

*/
