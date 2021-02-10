#include "stdafx.h"
#include <iostream>

/*
Írj funkció prototípusokat mindegyik funkcióhoz. Használd a legmegfelelőbb paramétert és return típust,
	akár konstanst ha szükséges.
*/

// 1. funkció: sumTo(), befogad egy integer paramétert és visszaadja az összegét az összes számnak 1 és a szám között.

int sumTo(const int number);

// 2. funkció: printEmployeeName(), ami befogad egy Employee struct-ot inputként.

void printEmployeeName(const Employee &employee);

// 3. funkció: minmax(), ami befogad két integert inputként, és visszaadja a kisebb és nagyobb értéket különböző paraméterként.

void minmax(const int x, const int y, int &minOut, int &maxOut);

// 4. funkció: getIndexOfLargestValue() ami befogad egy integer array-t(mint mutató) és az array hosszát, majd visszaadja a legnagyobb elem indexét

int getIndexOfLargestValue(int *array, int size);

// 5. funkció: getElement(), ami befogad egy integer array-t(mint mutató) és egy indexet, majd visszaadja az array elemet abban az indexben(nem másolatot).
	// ! feltételezzük, hogy az index érvényes, és a return érték const.

const int& getElement(const int *array, const int index)