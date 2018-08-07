#include "stdafx.h"


/*

A való életben nagy komplex és bonyolult dolgok gyakran kisebb, és egyszerűbb dolgokból vannak felépítve.
	pl: egy autó úgye felépül egy fém vázból, van egy motra, van sebességváltója, kormánya, kerekei, fékei, stb..

		- ezt a folyamatot hívjuk object kompozíciónak, vagy tárgy összetételnek.
		

	az object kompozíció a "van egy" kapcsolat típust szemlélteti.

	az object kompozíció rendkivül hasznos a class kontextusban, mivel ez által képesek vagyunk bonyolult classokat összerakni,
		kisebb, könnyen kezelhető darabokból, elősegíti a kód újrahasználást, mivel már megírt és bizonyítottan müködő kódot használunk
			fel egy új bonyolult class létrehozására.

*/


/*

Types of object composition,
	két alapvető object kompozíció altípus van, az összetétel, és a összesítés.

*/


/*

Összetétel,
	ahhoz, hogy ez összejöjjön egy classnak és egy tagnak a következő kapcsolata kell legyen:
		- a tag a class része,
		- egyidejűleg a tag csak egy classnak lehet a része,
		- a tagnak a létezése a classtól függ,
		- a tag nem tud a class létezéséről.

		megmagyarázva:
			mint egy ember szíve.
				a szív része az ember testének.
				egy szív egyidejűleg csak egy testnek lehet a részese.
				a test felelős a szív müködőséről, ha a test meghal, a szív is meghal, ha a test létrejön, a szív is létrejön.
				a szív csinálja maga dolgát anélkül, hogy tudna a test létezéséről,
					- itt jön képbe az unidirekcionális kapcsolat, mivel a test tud a szív létezéséről, de a szív fordítva már nem.

				lásd példa 'Fraction' class,
					ahol van a két tag változó, amelyek létrejönnek amikor az object létrejön, és törlődnek amikor megsemmisül.
					léteznek anélkül, hogy tudnának a classról,
					valamit egyidejűleg csak egy classnak lehetnek a tagjai.

	Miközben az object kompozíció a "van egy" kapcsolat típust személteti addig az összetétel sokkal inkább a "része" típust.


Implementing compositions,
	az összetétel az egyik legkönnyebben berakható kapcsolat típus, és típikusan classok vagy structok által van beépítve, normál
		tag változók által.

	olyan összetételek amelyek dinamikusan elosztott memóriával dolgoznak, az összetétel a felelős azért, hogy megfelelően el legyen
		takarítva.


Variants on composition theme,
	miközben a legtöbb összetétel akkor hozza létre részeit amikor az összetétel létrejön, és akkor semmisíti meg azokat amikor
		az összetétel szétbomlik, van amikor ez megváltozhat.

		- néhány összetétel elhalaszthatja a tagok létrehozását addig amíg szükség van rájuk.
		- az összetétel elhagyhatja egy érték használatát amit inputként kapott ahelyett, hogy létrehozná a részt.
		- egy összetétel átadhatja a részeinek a megsemmisítését egy más objectnek.

Composition and subclasses,
	a legjobb szabály az, hogy egy class egy feladatot végezzen el, de azt megfelelően.

*/