#include "stdafx.h"
#include <iostream>


/*

void a legegyszerűbb az összes datatípus közül, azt jelenti, hogy nincs típusa

a változókat nem lehet definiálni a void típussal

*/

void ertek; // nem fog mükődni

// legtöbbszőr arra használjuk, hogy mutassuk, hogy az adott funkció nem ad vissza semmilyen értéket

void ertek1(int x)
{
	std::cout << "Az x erteke a következő: " << x << std::endl;
	// nincs return állítás, mert a void típusú.
}

// valamint arra is lehet használni, hogy mutassuk az adott funkció nem igényel semmilyen paramétert

int ertekKeres(void)
{
	int y;
	std::cin >> y;
	return y;
}

 // értelmetlen, ha nem írod oda úgyanaz.