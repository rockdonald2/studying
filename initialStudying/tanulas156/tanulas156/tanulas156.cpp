#include "pch.h"
#include <iostream>

/*

Nem úgy mint az std::unique_ptr amelyet úgy terveztek, hogy egyedül birtokoljon és kezeljen egy erőforrást,
	az std::shared_ptr azt az esetet oldja meg amikor több smart pointerre van szükséged amelyek közösen birtokolnak
		egy erőforrást
		- ez azt jelenti, hogy elfogadható ha több std::shared_ptr mutat ugyanarra az erőforrásra
		- az std::shared_ptr nyomon követi, hogy hány std::shared_ptr mutat arra az erőforrásra, amíg legalább
			egy std::shared_ptr létezik amelyik arra mutat, az erőforrás nem lesz felszabadítva
		- azonban ahogy az erőforrást kezelő std::shared_ptr kimegy a scopeból (vagy más erőforrásra lesz
			hozzárendelve), az erőforrás felszabadítódik.
		- akárcsak az std::unique_ptr az std::shared_ptr is a "memory" headerben található meg

		lásd pl.

		- fontos észrevenni, hogy a második shared_ptr az első másolataként hoztunk létre, hiszen itt elfogadható
			a copy semantics hiszen több smart pointer kezelheti ugyanazt az erőforrást
			- azonban ha nem így teszünk, és az eredeti Resource objectból hozzuk létre a második shared_ptr-t
			akkor a két shared_ptr nem fog tudni egymásról, így hamarább törlődik a Resource mint kellene
			! szabály, mindig egy meglévő shared_ptr-t másolj le amikor több smart pointerre van szükséged
				ugyanarra az erőforrásra

std::make_shared,
	akárcsak az std::make_unique amelyet a C++14-től arra használunk, hogy std::unique_ptr hozzunk létre,
		az std::make_shared arra lehet (sőt kellene) használni, hogy std::shared_ptr hozzunk létre

		lásd pl, átalakítva

Digging into std::shared_ptr,
	szóval, nem úgy mint a unique_ptr amely egyetlen mutatót használ belsőleg, a shared_ptr-t kettőt használ,
		egy ami tartalmazza az erőforrás címet, egy másik amely egy konstruktőr által létrehozott "control block"-ra
		mutat amely számos tényezőt megfigyel, mint pl. hány shared_ptr mutat ugyanarra az erőforrásra.
		- amikor std::shared_ptr konstruktőrjével létrehozunk egy std::shared_ptr-t az erőforrás memóriája(amit beadunk),
			valamint a control block külön vannak elhelyezve, az std::make_shared ebben segít, mivel egyetlen memória
			elhelyezésre optimalizálja, ezáltal jobb teljesítményt elérve


		- ez magyarázza azt is miért rossz ha két különböző shared_ptr-t hozunk létre úgy, hogy ugyanazt az erőforrást
			adjunk be, és nem egy másik shared_ptr-t, hiszen ekkor két különböző control block jön létre, és mindkettő
			úgy érzékeli mintha ő lenne az egyetlen amely arra az erőforrásra mutat, így vezetve az erőforrás korábbi törléséhez

		- ugyanakkor, ha egy std::shared_ptr klónozunk copy assignmenttel a control blockhoz tartozó adatok
			fríssitve lehetnek elárulva, hogy több shared_ptr kezeli ugyanazt az erőforrást.

Shared pointers can be created from unique pointers,
	lehetséges egy unique_ptr-t átalakítani shared_ptr-ba egy különleges std::shared_ptr konstruktőrrel, amely befogad
		egy std::unique_ptr r-érték paramétert, a unique_ptr tartalma átlesz mozgatva shared_ptr-ba

	! ugyanakkor, nem lehet biztonságosan átalakítani egy shared_ptr-t unique_ptr-á
	- ha készítesz egy funkciót ami egy smart pointert ad vissza, sokkal jobb ha egy unique_ptr-t adsz vissza, majd
		azt hozzárendeled egy shared_ptr-hoz amikor a helyzet megfelelő.

The perils of std::shared_ptr,
	ugyanazokkal a veszélyekkel küszködik mint a unique_ptr
	-- ha egy shared_ptr-tól nem szabadultunk meg rendesen (vagy amiatt mert dinamikusan volt elosztva és soha törölve,
		vagy része volt egy dinamikusan elhelyezett objectnek amelyet nem töröltünk) hát akkor az erőforrás amit
		kezel az sem lesz törölve
		- unique_ptr esetében csak egy mutatóval kell foglalkoznod, míg shared_ptr esetében az összessel,
			ha legalább egy shared_ptr-tól nem szabadultál meg rendesen akkor az erőforrás nem lesz
			felszabadítva.

std::shared_ptr and arrays,
	C++14-ben és korábban nem volt megfelelő támogatása a shared_ptr-nak arrayokhoz és nem lehetett használni
		arra, hogy C-style arrayeket kezeljen
	C++17-ben a shared_ptr már támogatja az arrayeket, de a make_shared-t még mindig nem támogatja megfelelően
		az arrayeket.

*/