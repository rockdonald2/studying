#include "pch.h"
#include <iostream>

/*

Virtual functions and polymorphism,
	egy virtuális funkció, az egy különleges típusú funkciót ami amikor lehívnak megoldódik a legszármaztatotabb funkcióra ami létezik a származtatott
		class és az alap class között. Ezt a képességet hívjuk polimorfizmusnak.
		- a származtatott funkció párnak minősül ha úgyanaz az aláírása van( azaz, azonos paraméter típus, név, valami const állapot ), illetve
			megegyezik a return típusa az alap classban találhatóval. Ezeket a funkciókat hívjuk overridenak.

			! ahhoz, hogy egy funkciót virtuálissá tegyünk simán a funkció meghatározás elé a virtual kulcsszót tesszük.

			! fontos megjegyezni, hogy egy virtuálisnak jelölt funkció összes overrideja is virtuálisnak tekinthető akkor is ha nincs előtte a kulcsszó.

			! sose hívj le konstruktőrökből vagy destruktőrökből virtuális funkciókat


The downside of virtual functions,
	Ha minden esetben jó a virtuális funkció mért nem használjunk minden esetben?
		- egy virtuális funkció lehívása sokkal több időbe kerül mint egy normális funkció hívás.

*/