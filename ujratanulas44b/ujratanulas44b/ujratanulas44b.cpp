#include "stdafx.h"
#include <iostream>

/*

string,
	a string karakterek sora, amit " " közé helyezünk.

	ahhoz, hogy használjunk a stringeket a c++-ban, először includeolnunk kell a <string> headert, ami tartalmazza a std::string-et.
		string formában a számok szövegként vannak kezelve, nem számokként, így a matematikai számítások rájuk nem vonatkoznak.


		a string outputja normálisan mükődik cout-tal, de az input kissé különbözik.
		input esetén használni kell egy új parancsot, az std::getline()-t.
			std::getline() használata: std::getline(std::cin, stringváltozódneve)

				fontos tanács: amikor beolvasól egy számot std::cin-el, töröld az újsort amit létrehoz a következő paranccsal:
					std::cin.ignore(32767, '\n');


		két stringet össze lehet párosítani a + operátorral, vagy hozzá lehet rendelni az egyiket a másikhoz a += operátorral.

		ha tudni akarjuk hány karakterből áll egy adott string, használhatjuk a stringváltozódneve.lenght() funkciót.

*/