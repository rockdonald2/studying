#include "pch.h"
#include <iostream>

/*

Az eddigi összes példa amit láttál I/O kapcsolatban az vagy coutból írt ki, vagy cinből olvasott ki
	ugyanakkor, van egy rakás más class amiket stream classoknak nevezzünk stringekhez amik lehetővé tesznek hasonló
		műveleteket, insertion vagy extraction operátorokkal, stringekkel
	- mint az istream vagy ostream, a string streamek is biztosítanak buffert, hogy adatot tároljanak
		de, nem úgy mint a cin vagy cout, ezek a streamek nincsenek hozzácsatlakoztatva I/O csatornákhoz
			(bill, monitor, stb)
		- az elsődleges használata a string streameknek, hogy buffereljenek outputot kiírásra egy későbbi időre,
			vagy, hogy feldolgozzanak inputot sorról sorra.

	hat különböző stream class van stringekhez: istringstream(istream származtatott), ostringstream(ostream származtatott)
		stringstream(iostream származtatott) ezek mind arra valóak, hogy olvassanak, vagy írjanak normál karakter széles
			stringeket

		a wistringstream, wostringstream, wstringstream pedig széles karakter stringek olvasása/írása

	- ahhoz, hogy használd a stringstreameket <sstream> headerre lesz szükséged

		lásd pl.

Conversion between strings and numbers,
	mivel az insertion és extraction operátorok tudják hogyan kell beépített adattípusokkal dolgozni, használhatjuk
		őket, hogy átalakítsuk a stringeket számokká, vagy fordítva
			lásd pl.

Clearing a stringstream for reuse,
	számos mód van arra, hogy kiüresítsük egy stringstream bufferjét
	1) str()-el beállítunk egy üres stringet használva egy üres C-style stringet
	2) str()-el beállítunk egy üres stringet használva egy üres std::string objectet
	 - használjuk a clear() funkciót is amikor kiüresítsük a stringstreamet, resetelve bármilyen error flaget
		ami bevolt állítva és visszateszi a streamet az OK állapotba

*/