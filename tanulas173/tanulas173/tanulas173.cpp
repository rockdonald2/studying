#include "pch.h"
#include <iostream>

/*

Amiután létrehoztál egy stringet sokszor elég hasznos, hogy tudd milyen hosszú.
	Ilyenkor jönnek képbe a length és capacity műveletek
		- ugyanakkor ebben a részben megjelennek olyan módszerek is amiket arra használhatunk, hogy
		std::string-t alakítsunk C-style stringgé, hogy olyan funkciókkal tudd használni ami megköveteli
			a char* típusú stringet 
			

Length of a string,
	egy string hossza nagyon egyszerű - a karakterek száma az adott stringben
	- két azonos funkció áll rendelkezésünk amellyel meghatározhatjuk egy string hosszát: length() és size()
		lásd pl.

Capacity of a string,
	egy string kapacitása megmutatja mekkora memória van lefoglalva a stringnek, hogy a tartalmát birtokolja
	az érték string karakterekben van számolva, kivéve a NULL terminátor, szóval 8 kapacítású string 8 karaktert
		birtokolhat.
		lásd pl.
			- észrevehetted, hogy a 8 hosszúságú stringnek, 15 a kapacítása tehát több mint szükséges
			Miért van ez?
				fontos dolog észrevenni, hogy bármikor amikor a felhasználó új karaktert akar hozzáadni
					a stringhez azt muszáj újraelosztani egy nagyobb kapacításra ha ugyanaz lenne a két érték
					ez által a felhasználó kap egy kis buffer room-t jővőbeli hozzáfűzésekhez
					- két indokból is nagyon rossz az újraelosztás:
						1) nagyon drága az újraelosztás: hiszen új memóriát kell elosztani, majd átmásolni minden
							karaktert a stringből az új memóriára, aztán a régi memóriát felszabadítani
						2) bármikor amikor egy string újraelosztódik, a string tartalmai új memóriacímre változnak,
							ez az jelenti, hogy minden hivatkozás, mutató és iterátor a stringhez helytelenné válik
*/