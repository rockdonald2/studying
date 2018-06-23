#include "stdafx.h"
#include <iostream>

/*
Írj function prototípusokat a következő esetekre: Használj const ha/amikor szükséges.
*/

// a) egy funkciónak aminek a neve max(), használ két double értéket és returnolja a kettő közül a nagyobbat.

double max(const double n1, const double n2);

// b) swap, megcserél két integert.

void swap(int &n1, int &n2);
 
// c) getLargestElement(), dinamikusan elosztott integer array, returnolja a legnagyobb számot olyan módon, hogy a hívó képes legyen
// a visszaadott elem értékén változtatni.

#include <vector>
int& getLargestElement(std::vector<int>, int length);


/*
Mi a baj az alábbi programokkal?
*/

// a) a funkció egy olyan helyi változót ad vissza ami a funkció végén megsemmisül.
// b) nincs terminációs kondicíó
// c) rossz overload, nincs különbség a paraméterek között, a return type nem számit megkülönböztető jelnek.
// valamint a double és a float =, addig amíg nincs kifejezetten sufix-al megerősítve a float type.
// d) túl nagy az array mérete, mivel a rakás csak 1MB memóriát tartalmaz, túlfolyás fog fellépni.
// e) az argv nincs átalakítva számmá, így egy C-style stringet probálnánk hozzárendelni egy int változóhoz.