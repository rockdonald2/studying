#include "stdafx.h"
#include <iostream>

/*

Friend functions,
	egy 'barát' funkció képes elérni egy class privát tagjait, mintha ő is tagja lenne a classnak.
	minden más szempontból, a barát funkció csak egy normális funkció.
		lehet akár egy normális funkció, vagy egy másik class tag funkciója.
	ahhoz, hogy baráttá tegyünk egy funkciót használjuk a 'friend' kulcsszót a funkció prototype előtt,
		nem számit, hogy a funkciót a class publikus vagy privát részén deklaráljuk.
		lásd pl.

			! megjegyzés, fontos továbbadni a Valami &valami objectet, mert a visszaallit() nem egy tag funkció,
				valamint nem is rendelkezik a *this mutatóval, és nincs is Valami objectje, így nekünk kell továbbadni egyet.

*/


/*

Multiple friends,
	egy funkció akár több classnak is barátja lehet egyidejűleg.
		lásd pl.

		 ! megjegyzés, mivel a fenti példában a 'kiirIdojaras()' funkció mindkét class barát, ezért mindkét class privát tag
			változóit elérheti.
			figyeld meg a példa tetején a class prototype-t: class Homerseklet;
				- ez figyelmezteti a compilert, hogy később létre fogunk hozni egy classot Homerseklet neven.
					Szükség van erre, máskép a compiler errort dobna, mert nem ismerné milyen Homerseklet mikor dolgozunk vele.
					Ugyanazt a célt szolgálja mint a function prototype, képesek vagyunk használni valamit most és meghatározni
						később.

*/


/*

Friend classes,
	lehetséges egy teljes class baráttá tenni egy másik classal.
		ez felruházza az összes tagját az adott barát classnak, hogy elérje a másik class privát tagjait.

		 ! megjegyzés, attól mert egyik class barát a másikkal, nem jelenti azt, hogy a másik is barát az elsővel.
					a barát classnak nincs közvetlen hozzáférése a *this mutatóhoz.
					
*/


/*

Friend member functions,
	ahelyett, hogy egy egész classot baráttá tennél egy classal, képes vagy csak tag funkciókat baráttá tenni.
		ez úgyanúgy mükődik mint a sima funkció esetében kivéve azt, hogy a funkció elé oda kell tenni a classNev:: prefixet.

		! ebben az esetben azonban nem elég a forward declaration(prototype) ahhoz, hogy elérje a tag funkciót, hanem az a class
			amelyben található a tag funkciót amit baráttá akarunk tenni a másik classal hamarább kell legyen meghatározva.
			ez esetben azonban a második class prototypet legfelülre kell tenni, hogy ismerje a hivatkozást.

			a séma akkor: class prototype annak a classnak amelyt hivatkozásként használja a tag funkció.
						  class amelyben található a tag funkciót amit baráttá teszünk a másikkal, de csak forward declaration
						  class amelyben található a friend .. rendelkezés
						  tag funkció meghatározása.

		! ez csak akkor ekkora fájdalom ha mindent egy fájlban akarunk megoldani, ha szétosztjuk megfelelő .h és .cpp fájlokra
			nincs szükség rendezésre.
*/