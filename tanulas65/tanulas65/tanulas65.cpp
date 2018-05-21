#include "stdafx.h"
#include <iostream>


/*

Egy array elemei akármelyik adattípusból felépülhetnek, akár más arrayokból is.
	Egy arrayokból felépülő arrayt hívunk többdimenziós arraynek.

		pl. int array[3][5]; // egy 3 elemből felépülő 5 elemű array
				ez kiírva egy 3 soros 5 oszlopos arrayt épít fel.
					így tekinthetünk a bal oldali tagra mint a sor tagra, a jobb oldalira pedig mint az oszlop tagra.

					[0][0]  [0][1]  [0][2]  [0][3]  [0][4] // row 0
					[1][0]  [1][1]  [1][2]  [1][3]  [1][4] // row 1
					[2][0]  [2][1]  [2][2]  [2][3]  [2][4] // row 2

		Ahhoz, hogy elérjük az egyik elemét egy többdimenziós arraynek simán használunk két indexet
			pl. array[2][4] = 7;

*/


/*

Többdimenziós array inicializálása,
	hogy hatékonyan incializáljunk egy többdimenziós arrayt használhatunk fészkelt kapcsoszárójeleket, ahol minden szám készlet
	ábrázol egy sort.

		int array[3][5] =
		{
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 }
		};

	Egy initializer list-el létrehozott kétdimenziós array elhagyhatja a bal oldali tagot, és csakis azt.

	Akárcsak a normál arrayek ezt is lehet 0-val incializálni.
		pl. int array[3][5] = { 0 };
			! vigyázz, itt nem hagyhatod el a bal oldali tagot se, mivel így csak 1 soros kétdimenziós array lesz.

*/


/*

Elemek elérése a kétdimenziós arrayekben,
	minden elem elérése egy kétdimenziós array esetében két loopal lehetséges, egy a sornak, egy az oszlopnak.
		Mivel, a kétdimenziós arrayt általában sorról sorra érjük el, a sor index lesz a külső loop.

			for (int row = 0; row < numRows; ++row) // step through the rows in the array
			for (int col = 0; col < numCols; ++col) // step through each element in the row
				std::cout << array[row][col];

*/



/*

A többdimenziós arrayek lehetnek többek mint kétdimenziósak, akár három is vagy több.
	pl. int array[3][4][5];
		Ezeket nehéz lenne initializer list-el inicializálni, így jobb inicializálni 0-val, majd fészkelt loopokkal értéket hozzárendelni.

*/