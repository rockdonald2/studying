#include "stdafx.h"
#include <iostream>

/*

Inline functions,
	a funkció használata rengeteg előnnyel jár:
		- újrahasználhatók
		- könnyeb modosítani, vagy frissíteni,
		- a kódodat könnyebb olvasni és megérteni,
		- type-checking-et biztosítanak,
		- valamint a programod könnyebb debugolni a funkciók által.
	egyetlen fontos hátránnyal rendelkeznek:
		- minden egyes alkalommal amikor egy funkciót lehívunk, van egy bizonyos 'overhead' teljesítmény mennyiség ami megtörténik.
			ez amiatt jön létre, hogy a CPU muszáj 'észben tartsa' a jelenlegi müvelet címét, együtt más azonosítókkal,
				mint például a funkció paraméterek amik létre kell jöjjenek és az értekek amik hozzárendelődnek,
					valamint a program egy új helyre kell 'ágazzon'.
						Olyan kód amit pont helyre írunk jelentősen gyorsabb.

			olyan funkciók amelyek nagyon, vagy komplex feladatot látnak el, ez a fajta teljesítmény 'overhead' ami
				a funkció lehívás által keletkezik elenyésző ahhoz képest, hogy mennyi idő kell a funkciónak, hogy lefusson.
			de kicsi, gyakran használt funkció esetében lassulást okoz, mert a lehívási idő sokkal hosszabb mint maga az idő
				amialatt a funkció végrehajtódik. Ez egy lényeges teljesítmény büntetést okoz.


		A C++ tartogat egy módot arra, hogy kombináljuk az előnyeit a funkciónak a megfelelő helyre írt kódok gyorsaságával
			ez az INLINE funkció.
				az 'inline' kulcsszót használjuk arra, hogy megmondjuk a compilernek, hogy az a funkció inline funkció.
					amikor a compiler a kódodat compile-olja minden inline funkció kibővül azon a helyen, azaz a funkció hívás
					lecserélődik a funkció tartalmának másolatával, ami így eltávolítja az 'overhead' funkció hívást.
						probléma ezzel, hogy mivel minden inline funkció azon a helyen kibővül ezért a már le compile-olt
						kódod sokkalta hosszabb lehet mint az írott kódod, főleg ha sokszor hívod le, vagy a funkció hosszú.

			! szóval így gyorsabb lesz, az árán, hogy a lecompileolt kód hosszabb.

		Mivel lehetőség van a kód 'duzzanat'-ra, ezért a inline funkció legjobb rövid funkcióknak.
			úgyanakkor az 'inline' csak egy javaslat, a compiler akár meg is tagadhatja a kérésedet, ez általában hosszú
				funkciók esetében áll fent.
			de, modern compilerek már automatikusan végzik az 'inline' funkciók létrehozását, anélkül, hogy te egyáltalán
				'inline' funkciónak jelölted volna
				! akkor végzi el ezt ha úgy nézi teljesítmény javulással jár.

				! szabály, figyelj az 'inline' funkciókra, de a modern rendszerek már automatikusan végzik ezt,
					ezért nincs is szükség arra, hogy te döntsd el, hagyd a rendszer végezze.

*/


/*

Az 'inline' funkció mentesek az egy meghatározás/program szabály alól,
	a normál funkciók ha header fájlba vannak meghatározva, majd includeolva, ez által többször belemásolva a programba,
		amikor megpróbálod lecompileolni egy errort kapsz többszöri meghatározás miatt.

	'inline' funkciók mentesek ez a szabály alól, mivel ez esetben nem a valódi funkció fut le, hanem egy másolat,
		ezért a linker nem fog összeütközni amikor több fájlt kapcsol össze.

		! de, még 'inline' funkció esetében se határozz meg globális funkciókat header fájlokba.

*/