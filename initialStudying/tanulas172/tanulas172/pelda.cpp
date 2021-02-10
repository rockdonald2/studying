#include "pch.h"
#include <iostream>

//

#include <string>
#include <sstream>

template <typename T>
inline std::string ToString(T tX)
{
	std::ostringstream oStream;
	oStream << tX;
	return oStream.str();
}

template <typename T>
inline bool FromString(const std::string& sString, T &tX)
{
	std::istringstream iStream(sString);
	return (iStream >> tX) ? true : false;
}

int main()
{
	// string::string()
	std::string sSource; // alapértelmezett konstruktőr: üres string
	std::cout << sSource << std::endl;

	// string::string(const string& strString)
		// copy konstruktőr, ez egy stringet hoz létre a strString másolataként
	std::string sSource1("my string");
	std::string sOutput1(sSource1);
	std::cout << sOutput1 << std::endl;

	// string::string(const string& strString, size_type unIndex)
	// string::string(const string& strString, size_type unIndex, size_type unLength)
		// ez a konstruktőr egy új stringet hoz létre amely legfeljebb annyi karaktert tartalmaz a strStringből,
		// mint az unLength, az unIndex indextől kezdve
		// ha találkozik egy NULL-al, akkor a string másolás véget ér, akkor is ha unLength-t még nem érte el
		// ha nincs unLength megadva, akkor az összes karakter használva lesz unIndex-től kezdve
		// ha az unIndex nagyobb mint a string mérete, az out_of_range exception lesz dobva
	std::string sSource2("my string");
	std::string sOutput2(sSource2, 3, 6);
	std::cout << sOutput2 << std::endl;

	// string::string(const char *szCString)
		// ez a konstruktőr egy új stringet hoz létre a C-style string szCString-ből, a NULL terminátorig,
		// de az már nem fog beletartozni
		// ha a létrejővő méret meghaladja a string max hosszat, a length_error exception lesz dobva
		// a szCString nem lehet NULL.
	const char* szCString3("my string");
	std::string sOutput3(szCString3);
	std::cout << sOutput3 << std::endl;

	// string::string(const char *szCString, size_type unLength)
		// ez a konstruktőr egy új stringet hoz létre az első unLength karakterekből a szCString-ből.
		// ha a létrejővő string hossza meghaladja a max hosszat, a length_error exception lesz dobva
		// CSAK EBBEN A FUNKCIÓBAN, a NULL nem úgy lesz kezelve mint end-of-string karakter a szCStringben,
		// ez alapján lehetséges leolvasni a string végéről ha az unLength túl nagy, figyelmes kell lenni a buffer
		// overflow-ra
	const char* szCString4("my string");
	std::string sOutput4(szCString4, 4);
	std::cout << sOutput4 << std::endl;

	// string::string(size_type nNum, char chChar)
		// ez egy olyan stringet hoz létre amely incializálva lesz nNum-nyi alkalommal megsokszorozott chChar-al.
		// ha a létrejővő string meghaladja a max hosszat, a length_error exception lesz dobva.
	std::string sOutput5(4, 'Q');
	std::cout << sOutput5 << std::endl;

	// string::~string()
		// string destruktőr, tőrli a stringet, felszabadítja a memóriát.

	// szám string létrehozása, a fenti rendszerrel
	std::string sFour(ToString(4));
	std::string sFivePointSeven(ToString(5.7));
	std::cout << sFour << std::endl;
	std::cout << sFivePointSeven << std::endl;

	// string átalakítása számmá
	double dX;
	if (FromString("3.4", dX))
		std::cout << dX << std::endl;
	if (FromString("ABC", dX))
		std::cout << dX << std::endl; // mivel nem szám sikertelen, így nem íródik ki.

	return 0;
}