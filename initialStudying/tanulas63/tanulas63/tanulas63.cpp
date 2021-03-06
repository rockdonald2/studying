#include "stdafx.h"
#include <iostream>

/*

loopok és arrayek,
	
	pl. int scores[] = { 84, 92, 76, 81, 56 };
		const int numStudents = sizeof(scores) / sizeof(scores[0]);
		int totalScore = 0;
 
		// use a loop to calculate totalScore
		for (int student = 0; student < numStudents; ++student)
			totalScore += scores[student];
 
		double averageScore = static_cast<double>(totalScore) / numStudents;


			az előző leckében megtanultad, hogy egy array indexe nem muszáj egy konstans érték legyen, lehet akár egy változó is.
			ebből kifolyólag használhatunk egy loop változót array indexként, ahhoz, hogy végig mennyünk egyesével az elemeken és
			müveleteket hajtsunk végre rajtuk.
				Amikor egy loopot használunk arra, hogy elérjük egy array minden elemét sorjában azt az arrayen keresztüli ismétlésnek
					hívjuk.

	pl. 2: 
	int main()
	{
		int scores[] = { 84, 92, 76, 81, 56 };
		const int numStudents = sizeof(scores) / sizeof(scores[0]);
 
		int maxScore = 0; // keep track of our largest score
		for (int student = 0; student < numStudents; ++student)
			if (scores[student] > maxScore)
				maxScore = scores[student];
 
		std::cout << "The best score was " << maxScore << '\n';
 
		return 0;
	}
		

*/


/*

Loopokat általában array-el három dologra használunk:
	1) Kiszámoljunk egy értéket(pl. átlag érték, össz. érték)
	2) Megkeressünk egy értéket(pl. legmagasabb érték, legalacsonyabb érték)
	3) Ujrarendezni egy arrayt(pl. növekvő sorrend, csökkenő sorrend)

		Amikor kiszámolunk egy értéket, egy változó gyakran arra van használva, hogy tartson egy középső értéket amit arra használunk
			hogy a végső értéket megkapjuk. A fenti példában a totalScore tartja az össz pontszámát az összes addigi elemnek amit megvizsgált.

		Amikor keresünk egy értéket, egy változót gyakran arra használunk, hogy tartsa annak az elemnek az értéket ami addig a legjobb.
			A fenti példában a maxScore tartja az addigi legnagyobb pontszámot amit megvizsgált.
		Egy array rendezése a következő leckében jelenik meg.

*/


/*

Arrayek és off-by-one hibák,
	az egyik legtrükkösebb dolog amikor loopokkal és arrayel dolgozunk, hogy a loop megfelelő alkalommal ismétlödjőn meg.
	off-by-one hibák könnyen keletkeznek(amikor eggyel többször vagy kevesebbszer ismétlődik meg mint kellene), és
	egy olyan elemet elérni ami nagyobb mint az array hossza szörnyű következményekhez vezethet.

		! amikor loopokat használsz array-el kétszer is ellenőrízd le a loop kondíciódat.

*/