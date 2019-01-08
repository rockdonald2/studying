#include "pch.h"
#include <iostream>

// 

#include <string>

int main()
{
	// char& string::operator[] (size_type nIndex)
	// const char& string::operator[] (size_type nIndex) const
		// mindkét funkció visszaadja azt a karaktert amely az nIndex-n van
		// rossz index beadása = undefined behaviour
		// a length() használata az indexben nem ajánlott
		// mivel char& a return típus használhatod karakterek módosítására
	std::string sSource("abcdefg");
	std::cout << sSource[5] << std::endl;
	sSource[5] = 'X';
	std::cout << sSource << std::endl;

	// char& string::at (size_type nIndex)
	// const char& string::at (size_type nIndex) const
		// visszaadja a karaktert az nIndex-ről
		// rossz index beadása = out_of_range exception
		// mivel char& a return típus használhatod karakter módosítására
	std::string sSource1("abcdefg");
	std::cout << sSource1.at(5) << std::endl;
	sSource1.at(5) = 'X';
	std::cout << sSource1 << std::endl;

	// const char* string::c_str () const
		// visszaadja a string tartalmát mint egy const C-style string
		// null terminátor hozzáfüzve !
		// a C-style stringet az std::string birtokolja, és nem szabad azt törölni
	std::string sSource2("abcdefg");
	std::cout << strlen(sSource2.c_str()) << std::endl;

	// const char* string::data () const
		// visszaadja a string tartalmát mint egy const C-style string
		// nincs null terminátor hozzáfüzés !
		// a C-style stringet az std::string birtokolja, és nem szabad azt törölni
	std::string sSource3("abcdefg");
	const char *szString3 = "abcdefg";
	// a memcmp funkció összehasonlítja két string első n karakterét és 0-át ad vissza ha egyeznek
	if (memcmp(sSource3.data(), szString3, sSource3.length()) == 0)
		std::cout << "The strings are equal\n";
	else
		std::cout << "The strings are not equal\n";

	// size_type string::copy (char *szBuf, size_type nLength) const
	// size_type string::copy (char *szBuf, size_type nLength, size_type nIndex) const
		// szóval mindkettő, az szBuf-ba a stringből nLength karakterszámot másol át, kezdve az nIndex indextől.
		// a másolt karakter számát visszaadja
		// nincs null terminátor hozzáfüzés !, a hívó kell bebiztosítsa, hogy az szBuf inicializálva lett NULL-al
		// vagy befejezte a stringet ha visszaadott hosszal.
		// a hívó felelős azért, hogy ne legyen overflowolva az szBuf

	std::string sSource4("sphinx of black quartz, judge my vow");

	char szBuf[20];
	int nLength = sSource4.copy(szBuf, 5, 10);
	szBuf[nLength] = '\0'; // lezárjuk a stringet, használva a visszaadott hosszat és a null terminátort
	std::cout << szBuf << std::endl;

	return 0;
}