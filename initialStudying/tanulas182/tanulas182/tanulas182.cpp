#include "pch.h"
#include <iostream>

/*

Az iostream library eléggé komplex, ebben a leckében az input class különböző funkcionalítását fogjuk
	megvizsgálni


The extraction operator,
	már sokszor láttuk ezt, az extraction operátor>> használható arra, hogy információt olvassunk egy
		input streamből
		a C++ extraction operátorokat határozott meg minden beépített adattípushoz, a többihez overloadolni kell

		- amikor stringeket olvassunk, egyik gyakori probléma az extraction operátorral az, hogy
			hogyan akadályozzuk meg a buffer overflowját
			lásd pl.

		- a megoldás a manipulatorok használata,
			a manipulator az egy olyan object amit arra használunk, hogy módosítsuk a streamet amikor alkalmazzuk
				az extraction vagy insertion operátorokkal
				- az egyik ilyen amivel dolgoztál az endl -- ami új sort ír ki, valamint "lehúz" bármilyen bufferes
					outputot
				- egy másik ilyen a setw(iomanip.h header), amelyet arra használhatunk, hogy limitáljuk a karakterek
					számát amit beolvas a streamből
						- használjuk a setw() funkciót paraméterként a limittel, beilllesztve az input állításba


Extraction and whitespace,
	az egyik dolog amit kihagytunk, hogy megemlítsünk az, hogy az extraction operátor formatált adattal dolgozik,
		azaz kihagyja a whitespaceket(blanks, tabs, és newlines)
		lásd pl.

	néha, azt akarjuk, hogy az input ne hagyja ki a whitespaceket, ehhez az istream class biztosít sok funkciót
		az egyik leghasznosabb a get() funkció, ami egyszerűen karaktereket szerez az input streamből
		- két fajtája van az első a cin.get(), valamint a cin.get(..., karakterszámlimit)

		- egy fontos dolog a get()-el kapcsolatban, hogy nem olvas be newline karaktert,
			- ennek a megoldására használhatjuk a getline() funkciót ami működik newline karakterrel
			+ ha tudni akarod hány karaktert olvassot be a cin utolsó alkalommal használhatod a gcount() funkciót

		- van egy speciális változata a getline()-nak std::stringre
			- az istream classon kivül él, arra használjuk, hogy adatot olvassunk be az std::stringbe
			- <string> headerbe található
			- getline(cin, stringváltozó)

		- többi hasznos funkciója az istream-nek:
			ignore() kihagyja az első karaktert a streamből
			ignore (int nCount) kihagyja az első nCount karaktert
			peek() lehetővé teszi, hogy beleles a streambe anélkül, hogy adatot törölnél onnan
				- leolvass egy karaktert anélkül, hogy törölnéd azt a streamből
			unget() visszaadja az utolsó olvasott karaktert a streambe, így újra olvasható lesz a következő
				hívásnál
			putback(char ch) lehetővé teszi, hogy visszarakj egy választott karaktert a streambe
*/