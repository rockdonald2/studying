#include "stdafx.h"
#include <iostream>


/*

Why make member variables private?
	Egy hasonlattal könnyű megmagyarázni.
		Nézz magad köré. Autó, TV távírányitója, stb.
		Biztosítanak számodra egy egyszerű interfészt amit használhatsz(gombok, kormány, stb), hogy elvégezz egy cselekvést.
			Ahogyan ezek a tárgyak tulajdonképpen operálnak az rejtve van tőled, és nem is kell nagyon tudnod ahhoz, hogy ezeket
			használd. Ez a elkülönítés az interfész, és a kivitelezés között nagyon hasznos, mivel lehetővé teszi, hogy használjunk
			tárgyakat anélkül hogy ismernénk a tényleges mükődésüket.

			Ez a feltevés a programozásban is nagyon hasznos.

*/


/*

Encapsulation(beágyazás),
	Az OOP-ben, a beágyazás az a folyamat amely során a részletek arra vonatkozóan hogyan van egy adott tárgy kivitelezve el van
		rejtve az adott tárgyat felhasználók elől.
		Ez által a felhasználók képesek használni az adott tárgyat anélkül, hogy ismernék és értenék hogyan van kivitelezve.

	C++-ban beépítjük a beágyazást a hozzáférés pontosítok által. Általában minden tag változó privát, és minden tag funkció
		publikus. Ez által elrejtve a kivitelezési részleteket, és felfedve egy interfészt.

	Encapsulated classes are easier to use and reduce the complexity of your programs,
		így minden tag változó védve van attól, hogy direkt módon érjék el és változtassák meg, valamint
			bebiztosítja, hogy egyik változót se használják félre (pl. rossz array indexet használnak, stb.)
		lásd pl neten.

	Encapsulated classes are easier to change,
		lásd pl neten.
	
	Encapsulated classes are easier to debug,
		lásd pl neten.

*/



/*

Access functions,
	egy elérhetőségi funkció az a rövid funkció aminek az a feladata, hogy lekérjen vagy változtassa az értékét egy privát
		tag változónak.
	Általában két fajtája van: getter és setter.
		Egy getter funkció return-olja az adott privát tag változó értékét.
		Egy setter funkció beállítja az adott privát tag változó értékét.

		! szabály, csak akkor határozz meg hozzáférési funkciót egy taghoz ha szükséges, hogy direkt módon visszaadja vagy beállítsa
			az adott tag értékét a felhasználó.
		! a getter funkció csak érték alapján, vagy const hivatkozás alapján returnoljanak.

*/