#include "stdafx.h"
#include <iostream>

/*

egy array rendezése,
	egy array rendezése az a folyamat amikor az elemeit egy meghatározott sorrendbe állítsuk fel.

	egy array rendezése hatékonyabbá teszi a keresést, nem csak az embereknek, hanem a gépeknek is.

*/

/*

Hogyan mükődik a rendezés?
	a rendezés általában úgy mükődik, hogy egy array elemeit újra és újra összehasonlítjuk páronként, és megcseréljük őket ha
	a megadott kritéria igaznak bizonyul. A sorrend amiben ezek a elempárok össze vannak hasonlítva változik, annak függvényében
	hogy milyen rendezési algoritmust használtunk.

		Ahhoz, hogy megcseréljünk két elemet használhatjuk az std::swap() funkciót a <utility> headerből.

		pl. int main()
			{
				int x = 2;
				int y = 4;
				std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
				std::swap(x, y); // swap the values of x and y
				std::cout << "After swap:  x = " << x << ", y = " << y << '\n';
			}


*/


/*

Rengeteg mód van egy array rendezésére, az egyik ilyen a selection sort,
	egyik legkönnyebb megérteni, de egyike a leglassabb rendezéseknek.

		A selection sort a következő lépéseket hajtja végre, hogy rendezzen egy arrayt a legkisebbtől, a legnagyobbig:
			1) Kezdi a 0-ás indextől, végigkeresi az egész arrayt a legkisebb érték után kutatva
			2) Megcseréli a legkisebb értéket az arrayban a 0-ás index értékével.
			3) Megismétli az 1,2 lépést kezdve a következő indextől.

				Magyarán: megkeresi a legkisebb értéket majd berakja a 0-ás index helyére, majd a második legkisebbet azt meg az
					1-es index helyére, és így tovább.

*/


/*

Selection sort a c++-ban,
	
	#include <algorithm> // for std::swap, use <utility> instead if C++11
	#include <iostream>

	int main()
	{
		const int length = 5;
		int array[length] = { 30, 50, 20, 10, 40 };

		// Step through each element of the array
		// (except the last one, which will already be sorted by the time we get there)
		for (int startIndex = 0; startIndex < length - 1; ++startIndex)
			{
				// smallestIndex is the index of the smallest element we’ve encountered this iteration
				// Start by assuming the smallest element is the first element of this iteration
				int smallestIndex = startIndex;

				// Then look for a smaller element in the rest of the array
				for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
					{
						// If we've found an element that is smaller than our previously found smallest
						if (array[currentIndex] < array[smallestIndex])
						// then keep track of it
						smallestIndex = currentIndex;
					}

		// smallestIndex is now the smallest element in the remaining array
		// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
		}

		// Now that the whole array is sorted, print our sorted array as proof it works
		for (int index = 0; index < length; ++index)
		std::cout << array[index] << ' ';

		return 0;
	}

*/


/*

Mivel a rendezés nagyon gyakori a c++-ban, ezért van saját funkciója is az std::sort()
	De erről majd később.

*/