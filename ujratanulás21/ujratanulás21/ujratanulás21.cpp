#include "stdafx.h"
#include <iostream>

/* 

szóval, ide tartoznak a primitív vagy beépített adat típusok
ilyen a boolean(bool), a character(char), floating point (egy szám tizedes számjegyekkel, ilyen pl. a float, double)
integer (egész számok, ilyen pl. az int, vagy a long) vagy a void.

*/

int nValtozoNev; // ahol az int a típus, a nValtozoNev pedig a valtozó neve.

bool bErtek;
char cErtek;
float fErtek;
double dErtek;
int nErtek;

//void vErtek; // ez nem fog mükődni, a void-ot nem lehet adattárolásra használni, nem lehet adattípusként használni, hogy változókat definiáljon.

/*

c++ 3 alap mód van arra, hogy definiáljunk egy változót
az első a 'copy initialization'

*/

int nErtek11 = 5; // ez az = jellel mükődik

/*

a második a 'direct initialization'

*/

int nErtek12(5);

// előnyei vannak ha ezt használjuk, ezért favoráld ezt a 'copy' helyett.

/*

a harmadik, ami csak c++11-ben elérhető a 'uniform initialization'

*/

int nErtek13{ 5 };

// ezzel lehet:

int nErtek14{};
			// ez esetben vagy 0 lesz az értéke, vagy üres, függ az adott típustól.
			// ezt hívjuk default initialization-nak.




/*

Változó hozzárendelés

		egyetlen módja van a 'copy assignment' az egyenlő jellel

*/

void funkcio()
{
	int nErtek15;
	nErtek15 = 5;
}



/*

Lehetséges egy sorban több értéket definiálni, válaszd el őket egy vesszővel

*/

int a, b;

int nErtek17 = 5, nErtek18 = 6;
int nErtek19(5), nErtek20(6);
int nErtek21{ 5 }, nErtek22{ 6 };