#include "stdafx.h"
#include <iostream>

/*

Constructors with overlapping functionality,
	amikor példányozol egy új objectet, az object konstruktőre magától értetődően levan hívva a compiler által.
		Nagyon gyakori, hogy egy class több konstruktőrrel rendelkezzen amelyek atfedő mükődéssel bírnak.

		Az alábbi példában van két konstruktőrünk, egy alapértelmezett, valamint egy ami egy int paramétert fogad be.
			Mivel a "code to do A" konstruktőr rész mind a két konstruktőr által szükséges, a kód duplikálódik mindegyik konstruktőrben.
			Ezt el kellene kerülni.

			Az egyik megoldás erre, hogy létrehozunk egy nem konstruktőr funkciót private-ban, ami elvégzi az alapvető
				inicializálást, majd mindkét konstruktőr által lehívjuk ezt a funkciót.
			Amikor használni akarsz egy tag funkciót arra, hogy újra-inicializáld a classodat az alapértékekre,
				a legjobb megoldás erre, hogy public-ban létrehozol egy 'init()' funkciót amely elvégzi az inicializálást,
				majd lehívod minden konstruktőrben ezt a funkciót.

			Azonban, a C++11-től kezdödően a konstruktőrök képesek lehívni más konstruktőröket, ezt a folyamatot hívjuk
				delegálásnak(delegating).
				Ahhoz, hogy egyik konstruktőr lehívjak a másikat, simán lehívjuk a konstruktőrt a member initializer list-ben.
					Ez az egyik eset amikor közvetlenül lehívni egy másik konstruktőrt elfogadható.

				- bármely konstruktőrt amelyet delegálnak egy másik konstrukthöz nem engedélyezett, hogy maga végezzen bármilyen
					tag inicializálást. Szóval a konstruktőrjeid delegálhatnak vagy inicializálhatnak, de nem egyszerre.
				- lehetséges egy konstruktőrt egy másikhoz delegálni ami vissza delegál az első konstruktőrhöz, ez egy infinite loop,
					és a programod crashelni fog mert kifogy a stack memóriából.
					Elkerülheted ezt az által, hogy bebiztosítod, hogy minden konstruktőröd felbontódik egy nem delegáló konstruktőrbe. 


*/


class Foo
{
public:
	Foo()
	{
		// code to do A
	}

	Foo(int value)
	{
		// code to do A
		// code to do B
	}
};