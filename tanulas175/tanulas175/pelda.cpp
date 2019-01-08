#include "pch.h"
#include <iostream>

//

#include <string>

int main()
{
	// string& string::operator= (const string& str)
	// string& string::assign (const string& str)
	// string& string::operator= (const char* str)
	// string& string::assign (const char* str)
	// string& string::operator= (char c)
		// ezek a funkciók különböző típusú értékek rendelnek hozzá stringekhez
		// *this mutatót adnak vissza, így lehet őket összeláncolnis
		// nincs olyan assign() funkció amely egyetlen char-t vesz be

	std::string sString; // üres

	sString = std::string("One"); // stringet rendel hozzá stringhez
	std::cout << sString << std::endl;

	const std::string sTwo("Two");
	sString.assign(sTwo);
	std::cout << sString << std::endl;

	sString = "Three"; // C-style string
	std::cout << sString << std::endl;

	sString.assign("Four");
	std::cout << sString << std::endl;

	sString = '5'; // egy char
	std::cout << sString << std::endl;

	std::string sOther; // üres
	sString = sOther = "Six"; // összeláncolva
	std::cout << sString << sOther << std::endl;

	// string& string::assign (const string& str, size_type index, size_type len)
		// hozzárendeli az str substringjét, index-től kezdve, len hosszig
		// out_of_range exception rossz index esetén
		// *this-t ad vissza, lehet láncolni
	const std::string sSource1("abcdefg");
	std::string sDest; // üres
	sDest.assign(sSource1, 2, 4);
	std::cout << sDest << std::endl;

	// string& string::assign (const char* chars, size_type len)
		// hozzárendel len karaktert a C-style stringből
		// length_error, ha az eredmény túllépi a max karakter számot
		// *this-t ad vissza, lehet láncolni
	std::string sDest1; // üres
	sDest1.assign("abcdefg", 4);
	std::cout << sDest1 << std::endl;
	// ha lehet ne használd, veszélyes

	// string& string::assign (size_type len, char c)
		// len-szer hozzárendeli a c karaktert
		// length_error, ha az eredmény túllépi a max karakter számot
		// *this-t ad vissza, lehet láncolni
	std::string sDest2; // üres
	sDest2.assign(4, 'g');
	std::cout << sDest2 << std::endl;

	// void string::swap (string &str)
	// void swap (string &str1, string &str2)
		// mindkét funkció felcseréli két string értékeit, a tag funkció a *this és az str,
		// a globális funkció az str1, és str2
		// funkciók hatékonyak, így ezeket kell használni a hozzárendelés helyett cserekor
	std::string str1("red");
	std::string str2("blue");

	std::cout << str1 << " " << str2 << std::endl;
	swap(str1, str2);
	std::cout << str1 << " " << str2 << std::endl;
	str1.swap(str2);
	std::cout << str1 << " " << str2 << std::endl;

	return 0;
}