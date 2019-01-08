#include "pch.h"
#include <iostream>

//

#include <string>

int main()
{
	// string& string::insert (size_type index, const string& str)
	// string& string::insert (size_type index, const char* str)
		// mindkét funkció index-re str karaktereit helyezi be
		// *this-t adnak vissza, tehát láncolhatók
		// out_of_range, ha rossz index
		// length_error, ha az eredmény túllépi a max karakterszámot
		// C-style string változatban, a str nem lehet NULL
	std::string sString("aaaa");
	std::cout << sString << std::endl;

	sString.insert(2, std::string("bbbb"));
	std::cout << sString << std::endl;

	sString.insert(4, "cccc");
	std::cout << sString << std::endl;

	// string& string::insert (size_type index, const string&str, size_type startindex, size_type num)
		// ez a funkció behelyez num karaktert str-ből, startIndex-nél kezdve, a stringbe indexre.
		// *this-t ad vissza, tehát láncolható
		// out_of_range, ha rossz index
		// length_error, ha az eredmény túllépi a max karakterszámot
	std::string sString1("aaaa");
	const std::string sInsert1("0123456789");
	sString1.insert(2, sInsert1, 3, 4);

	std::cout << sString1 << std::endl;

	// string& string::insert (size_type index, const char* str, size_type len)
		// len karaktert illeszt be str-ből a stringbe indexre
		// *this-t ad vissza tehát láncolható
		// out_of_range, ha rossz az index
		// length_error, ha az eredmény túllépi a max karakterszámot
		// kihagyja a speciális karaktereket mint "
	std::string sString2("aaaa");
	sString2.insert(2, "bcdef", 3);
	std::cout << sString2 << std::endl;

	// void insert (iterator it, size_type num, char c)
	// iterator string::insert (iterator it, char c)
	// void string::insert (iterator it, InputIterator begin, InputIterator end)
		// az első funkció beilleszt num alkalommal c karaktert az iterator előtt
		// a második beilleszt egyetlen c karaktert az iterator előtt
		// a harmadik funkció beilleszt minden karaktert [begin, end) között, az iterator előtt
		// length_error mind a háromnál, ha az eredmény túllépi a max karakterszámot

	std::string s{ "Hello, world!" };
	std::string::iterator i = s.begin();
	while (i != s.end())
	{
		if (*i == '!')
		{
			s.insert(i, '!');
			break; // inserting may invalidate our iterator so we can't use it again
		}
		++i;
	}

	std::cout << s;

	return 0;
}