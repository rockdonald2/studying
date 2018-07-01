#include "stdafx.h"
#include <iostream>

/*

The hidden "this" pointer,
	az egyik gyakori kérdés a classokról, az, hogy amikor egy tag funkciót lehívnak, a C++ hogyan tartja számon, hogy melyik
		objectre volt az lehívva. A válasz az, hogy a C++ használ egy rejtett mutatót amit "this"-nak hívnak.


		a lenti 'Simple' class használ egy integer privát tag változót, valamint tag funkciót illetve egy konstruktőrt.
			megjegyzés, nincs szükség destruktőrre mert a C++ automatikusan elvégzi az integer tag változók takarítását.

		amikor lehívjuk a simple.setID(2); funkciót a C++ valahogy tudja, hogy a setID()t a simple objecten kell használnia, és az
			m_id pedig a simple.m_id-ra vonatkozik.

*/

class Simple
{
private:
	int m_id;

public:
	Simple(int id)
	{
		setID(id);
	}

	void setID(int id) { m_id = id; }
	int getID() { return m_id; }
};


int main()
{
	Simple simple(1);
	simple.setID(2);
	std::cout << simple.getID() << '\n';

	return 0;
}


/*

The hidden *this pointer 
	vessünk egy pillantást az alábbi kód töredékre a fenti példából:
		simple.setID(2);
			habár, a funkcióhívás a setID()hoz úgy tünik, hogy csak egy érvvel rendelkezik, igazából kettővel. Amikor lecompileol,
				a compiler átalakítja a simple.setID(2)-öt a következővé: setID(&simple, 2);
					megjegyzés, ebben a stádiumban, ez egy standard funkció hívás, és a simple object cím által továbbadott érv a funkcióhoz.
					de ez csak félválasz, mivel most a tag funkció is át kell alakuljon, hogy fogadni tudja ezt az érvet mint paraméter.

					azaz ez a tag funkció: void setID(int id) { m_id = id; }
						átalakul ezzé a compiler által:
							void setID(Simple* const this, int id) { this->m_id = id; }
			amikor a compiler lecompileolja a normál tag funkciót, magától értetődöen hozzáad egy új paramétert a funkcióhoz "this" néven.
			ez a "this" mutató, egy rejtett konstans mutató ami tartalmazza annak az objectnek a címét amelyre a tag funkció levolt hívva.

					továbbá, miután átalakult a funkció hívás, a funkció meghatározás, a funkció bodyjában is megkell változzon minden class tag
					hogy arra az objectre vonatkozzanak amelyre a tag funkciót lehívták.
						ez úgy történik, hogy mindegyik megkapja a "this->" prefixet, és mivel a *this a simple címére mutat, ezért 
							a this->m_id valójában a simple.m_id-re vonatkozik.


*/


/*

*this always points to the object being operated on,
	minden egyes tag funkció tartalmaz egy *this mutató paramétert ami arra az object címre állítódik amelyen dolgozunk.
	
*/


/*

Chaining member functions,
	néha hasznos lehet az, hogy legyen egy class tag funkciónk ami visszaadja az objectet amin dolgozott return értékként.
		az elsődleges indok amiért ezt tennéd, hogy lehetővé tedd tag funkciók sorozatát összeláncolni, szóval több tag funkció hívható
		le egyszerre ugyanazon az objecten.
			pl. ezt teszi az std::cout is amikor több dolgot írsz ki egyszerre.

		de akár mi magunk is előidézhetünk hasonló viselkedést.
			lásd pl.

			ebben az esetben, minden müvelet visszadja a *this mutatót, ami egy hivatkozás az 'eredmeny'-re.

*/


/*

a "this" mutató egy rejtett paraméter ami magától értetődően hozzáadódik minden tag funkcióhoz. Nyomon tartja melyik objecten dolgozunk.

Olyan funkciót létrehozni ami máskép void-ot adna vissza, átírni, hogy *this-t adjon vissza, lehetővé teszed, hogy azok
	a funkció összeláncolhatók legyenek. Ezt akkor használjuk leginkább amikor overloadulunk operátorokat classokhoz.


*/