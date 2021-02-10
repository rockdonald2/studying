#include "pch.h"
#include <iostream>

//

#include <string>

int main()
{
	// string& string::operator+= (const string& str)
	// string& string:append (const string& str)
		// mindkét funkció az str-ből hozzáfüz karaktereket a stringhez
		// *this-t adnak vissza, tehát láncolni lehet őket
		// length_error exceptiont dobnak ha az eredmény túllépi a max karakter számot
	std::string sString("one");
	sString += std::string(" two");
	std::string sThree(" three");
	sString.append(sThree);

	std::cout << sString << std::endl;

	// string& string::append (const string& str, size_type index, size_type num)
		// ez a funkció num karaktert füz hozzá str-ből, indextől kezdve, a stringhez
		// *this-t ad vissza, tehát láncolható
		// out_of_range ha rossz az index
		// length_error ha az eredmény túllépi a max karakter számot
	std::string sString1("one ");
	const std::string sTemp1("twothreefour");
	sString1.append(sTemp1, 3, 5);
	std::cout << sString1 << std::endl;

	// string& string::operator+= (const char* str)
	// string& string::append (const char* str)
		// C-style stringgel dolgoznak, hozzáfüzi az str karaktereit a stringhez
		// *this-t adnak vissza, tehát láncolhatók
		// length_error, ha az eredmény túllépi a max karakterszámot
		// str nem lehet NULL
	std::string sString2("one");
	sString2 += " two";
	sString2.append(" three");
	std::cout << sString2 << std::endl;

	// string& string::append (const char* str, size_type len)
		// hozzáfüzi az első len karaktert a str-ből a stringhez
		// *this-t ad vissza, tehát láncolható
		// length_error, ha az eredmény túllépi a max karakterszámot	
		// kihagyja a speciális karaktereket mint a "
	std::string sString3("one ");
	sString3.append("threefour", 5);
	std::cout << sString3 << std::endl;

	// string& string::operator+= (char c)
	// void string::push_back (char c)
		// mindkét funkció hozzáfüzi a c karaktert a stringhez
		// operator+= *this-t ad vissza tehát láncolható
		// length_error, ha az eredmény túllépi a max karakterszámot
	std::string sString4("one");
	sString4 += ' ';
	sString4.push_back('2');
	std::cout << sString4 << std::endl;

	// string& string::append (size_type num, char c)
		// num-szor hozzáfüzi a c karaktert a stringhez
		// *this-t ad vissza, tehát láncolható
		// length_error, ha az eredmény túllépi a max karakterszámot
	std::string sString5("aaa");
	sString5.append(4, 'b');
	std::cout << sString5 << std::endl;

	// string& string::append (InputIterator start, InputIterator end)
		// hozzáfüz minden karaktert a [start, end) halmazból
		// *this-t ad vissza, tehát láncolható
		// length_error, ha az eredmény túllépi a max karakterszámot

	return 0;
}