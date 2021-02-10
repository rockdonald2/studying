#include "pch.h"
#include <iostream>

/*

Messze a standard library leghasznosabb classja az std::string és az std::wstring.
	az std::string az egy string class amely számtalan műveletet biztosít arra, hogy hozzárendeljünk, összehasonlítsunk
	és módosítsunk stringeket.

Motivation for a string class,
	amikor korábban a C-style string dolgoztál rájöhettél, hogy nagyon nehéz helyes dolgozni velük,
		hiszen könnyű elrontani, nehéz debugolni.

		ahhoz, hogy C-style stringet hozzál létre, először buffer-t kell készíts(1), elég nagyot ahhoz, hogy
			tárolni tudja a stringedet, +1 karaktert a null terminátor miatt, aztán a bufferbe kellett másolnod
			a stringet(2), végül ugye felkellett szabadítsd a memóriát magad(3).

			1 - char *newStr = new char[7];
			2 - strcpy(newStr, "hello!")
			3 - delete[] newStr;
				- aztán meg remélhetőleg elég nagy buffert hoztál létre, így elkerülve a buffer overflow-t.

			számtalan probléma a C-style stringgel:
				- a rengeteg C operátor vagy nem működik vele, vagy hibásan, a == operátor sima összhasonlítás
					helyett mutató összehasonlítást végez, a = operátor hozzárendelés helyett mutató shallow copy-t
					készít.
				- ezek nehezen megtalálhatók, és debugolhatok
				- a legalja pedig a nehezen megjegyezhető funkciók amelyekkel dolgozni kell C-style string esetében,
					megjegyezni a rengeteg szabályt, hogy mi biztonságos, és mi nem az, nameg a rengeteg manuális
					memória kezelés

		Szerencsére a C++ és a standard library egy remek megoldást ad: std::string, és std::wstring,
			amely használva a C++ koncepcióit konstruktőr, destruktőr, operátor overload, az std::string
			lehetővé teszi, hogy stringgel dolgozz biztonságosan, és intuitív módon.

String overview,
	minden string funkcionalitás a <string> headerben található

	- igazából 3 különböző string class található ebben a headerben

		 basic_string<>: templated base class
		namespace std
		{
			template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT> >
				class basic_string;
		}

				- nem fontos nekünk mit is jelent a traits, vagy az allocator, a default értékek a lehető legtöbb
					esetben elégséges lesz nekünk
			
			a basic_string<>-nek két változata van a standard library-ben:
				namespace std
				{
					typedef basic_string<char> string;
					typedef basic_string<wchar_t> wstring;
				}

					- a string sima ascii(utf 8) stringeknek van, a wstring pedig a unicode(utf 16) stringekhez,
				beépített utf 32-es nincs, de simán tudsz csinálni a basic_string<>-ből ha szükséged van rá.

				- a legtöbb esetben közvetlenül fogod használni a stringet és wstringet, minden string funkcionalitás
				a basic_string<> classban található
				a string és wstring képes elérni ezeket a funkcionalitásokat hiszen template classok
				- ugyanakkor, mivel a basic_string templated class, a compiler borzalmasan kinéző template errorokat
					fog kidobni ha valamit sémának nem megfelelően csinálsz a stringekkel, vagy wstringekkel
				- nem kell félni ezektől, rosszabul néznek ki mint amennyire súlyosak.

*/