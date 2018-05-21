#include "stdafx.h"
#include <iostream>

/*

Kézileg mutasd be hogyan mükődik a selection sort a következő array-el: { 30, 60, 20, 50, 40, 10 }.
	Írd le az array-t minden csere után.

	30, 60, 20, 50, 40, 10

	10, 60, 20, 50, 40, 30
	10, 20, 60, 50, 40, 30
	10, 20, 30, 50, 40, 60
	10, 20, 30, 40, 50, 60

*/

/*

Írd át a selection sort-ot, hogy nagytól a kicsiig rendezzen.

*/

/*#include <algorithm>


int main()
{
	const int length = 5;
	int array[length] = { 30, 50, 20, 10, 40 };

	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the largest element is the first element of this iteration
		int largestIndex = startIndex;

		// Then look for a smaller element in the rest of the array
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] > array[largestIndex])
				// then keep track of it
				largestIndex = currentIndex;
		}

		// smallestIndex is now the smallest element in the remaining array
		// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[largestIndex]);
	}

	// Now that the whole array is sorted, print our sorted array as proof it works
	for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';

	return 0;
}*/

/*

Egy másik egyszerű sort a bubble sort.
	A bubble sort úgy mükődik, hogy szomszédos párokat összehasonlít, egy megcseréli őket ha a megadott kritéria teljesül
		Két fajta van nem optimalizált, és optimalizált bubble sort.

			Egy nem optimalizált bubble sort lépései: 
				a) Összehasonlítja az array elem 0-át az array elem 1-el. Ha a 0 nagyobb, akkor megcseréli az 1-el.
				b) Ugyanezt megcsinálja az 1 és 2-vel, és minden soron következő párral, amig a végére nem ér az arraynek.
				c) megismétli az első két lépést amíg az array rendezve lesz.


			Írj egy programot ami bubble sort-al rendezi a következő array-t:
					
					const int length(9);
					int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

					írd ki a végén a rendezett array-t.

					! ha képesek vagyunk egyszerre egy elemet rendezni ismétlésekként, akkor legalább annyi ismétlés kell mint ahány szám
						van az arrayünkben, ahhoz, hogy garantáltan rendezve legyen.
					! amikor összehasonlítasz vigyázz az array skálájára.

			Majd adj hozzá két optimalizálást,
				- észreveheted, hogy minden ismétléssel, a legnagyobb szám az utolsó helyre ugrik, szóval az első ismétléssel az utolsó elem
				is rendezve van. A második ismétlés után az utolsó előtti is rendezve lesz. És folytatva.
				Minden ismétléssel, nincs szükség arra, hogy újraellenőrízzünk egy olyan elemet amit már rendeztünk,
					változtasd meg a loopot, hogy ne ellenőrízze újra a már rendezett elemeket.
				- ha végig megyünk az összes ismétlésen anélkül, hogy cserélnénk akkor már tudjuk, hogy az array rendezve van.
					Iktass be egy ellenőrzést ami megállapítja, hogy volt-e csere végrehajtva ebben az ismétlésben, ha nem,
						állítsa le a loopot, és ha hamarabb állt meg írja ki melyik ismétlésen állt le a rendezés.

*/


/*#include <algorithm>

int main()
{
	const int hossz{ 9 };
	int tomb[hossz] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

	for (int szamlalo = 0; szamlalo < hossz - 1; ++szamlalo)
	{
		// optimalizacio
		int tombVege = hossz - szamlalo; // mivel az utolsó mindig rendezve van minden soronkövetkező ismétléskor

		bool csere{ false };
		for (int kezdoIndex = 0; kezdoIndex < tombVege - 1; ++kezdoIndex)
		{
			int jelenlegiIndex = kezdoIndex + 1;
			if (tomb[kezdoIndex] > tomb[jelenlegiIndex])
			{
				std::swap(tomb[kezdoIndex], tomb[jelenlegiIndex]);
				csere = true;
			}
		}

		// optimalizacio
		if (!csere)
		{
			std::cout << "A rendezes leallt. Nem tortent csere a " << szamlalo + 1 << "-ik ismetleskor.\n";
			break;
		}
	}

	for (int szamlalo = 0; szamlalo < hossz; ++szamlalo)
		std::cout << tomb[szamlalo] << ' ';

	std::cout << "\n";

	return 0;
}*/