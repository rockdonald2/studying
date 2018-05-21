#include "stdafx.h"
#include <iostream>


/*

C-style string,
	lényegében egy karakterekből felépülő array ami használ egy null terminátort.
		A null terminátor egy speciális karakter ('\0'), amit arra használunk, hogy jelezze egy string végét.

			Ahhoz, hogy meghatározzunk egy C-style stringet simán meghatározunk egy char arrayt amit inicializálunk egy stringgel.
				pl. char peldaString[] = "pelda";
						! fontos, mivel ez a string 5 betüből áll, de az array valódi hossza 6 mivel tartalmazza a null terminátort is.

	tanácsos kihagyni a [] között a string hosszát, így nem kell majd később manuálisan modosítani.
	fontos tudni, hogy a C-style string követi az array-ek minden szabályát, azaz létrehozás után nem lehet hozzárendelni értéket egyenlővel.

			pl. char peldaString[] = "pelda"; // oké
				peldaString = "mas"; // nem oké.
	ugyanakkor, használhatod a [] operátort, hogy kicseréld betükként a stringedet
			pl. peldaString[0] = 'z';

	Amikor a rendszer kiír egy C-style stringet addig írja ki a karaktereket az arrayből amíg el nem éri a null terminátort, ha
		véletlenül átírod ezt a terminátort akkor addig írja ki a határos memóriából az adatokat amíg el nem ér egy 0-át.

		! helyes nagyobb array hosszt megadni egy string mint amilyen hosszú maga a string, mert úgyis a null terminátorral leáll,
			és az array többi része ignorálva lesz.


*/


/*

C-style string és az std::cin,
	általában amikor felhasználó inputot várunk és nem tudjuk meghatározni az input alapján az array hosszát
		jobb hosszabat megadni mint ami szükséges.

			! de, használd az std::cin.getline(CstyleStringNeve, maximumArrayHossz) parancsot, így előzöd meg az overflowt.

*/


/*

C-style string manipulálása,
	a C++ rengeteg funkciót ad a C-style string manipulásához amik a <cstring> headerben találhatok.
		A legfontosabbak: strcpy(), ami lehetőséget ad, hogy egy stringet a másikba másold, de itt nagy veszély van az overflowra.
			Ezért a C++11 elavultá tette a strcyp-t és ujat adott hozzá strcyp_s néven, ami egy új paramétert hoz be ami meghatározza
			a célállomás nagyságát.
				! nem mindegyik compiler támogatja, és ahhoz, hogy használjuk definiálnunk kell egy  __STDC_WANT_LIB_EXT1__  1-el

						  strlen() funkció, ami visszaadja a C-style string hosszát a null terminátor nélkül.

						  további említésre meltók:
					strcat() - hozzáfűzi egyik stringet a másikhoz
					strncat() - hozzáfűzi egyik stringet a másikhoz, de buffer length check-el
					strcmp() - összehasonlít két stringet(ha egyenlők = 0-val.)
					strncmp() - összehasonlít két stringet egy bizonyos karakter számíg (ha egyenlők = 0-val).

*/

/*

NE HASZNÁLD A C-STYLE STRINGET,	
	fontos tudni a hagyományos stringről, mert rengeteg kódban megtalálható, de amikor csak lehetséges használd a sima std::stringet,
		csak akkor használd ha van egy különleges, pontos okod rá.

*/