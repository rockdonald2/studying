#include "pch.h"
#include <iostream>

/*
throw -1; // ez dob egy egész szám error kódot
throw ENUM_INVALID_INDEX; // enum értéket dob
throw "Can not take square root of negative number"; // C-style string-t dob
throw dX; // double értéket dob ami már korábban megvolt határozva
throw myExceptional("Fatal Error"); // dob egy objectet a MyException
*/

/*
try
{
	// állítások amelyek kivételt dobhatnak, amiket kezelni akarsz ide kerülne
	throw - 1;// aztán a throw állítás
}
*/

/*
catch (int x)
{
	// az int típusú kivételt kezeli
	std::cerr << "We caught an int exception with value " << x << '\n';
}
*/

/*int main()
{
	try
	{
		throw -1;
	}

	catch (int x)
	{
		std::cerr << "We caught an int exception with value: " << x << '\n';
	}

	catch (double)
	{
		std::cerr << "We caught a double exception" << '\n';
	}

	catch (const std::string &str)
	{
		std::cerr << "We caught a string exception" << '\n';
	}

	std::cout << "Continuing\n";

	return 0;
}*/

int main()
{
	std::cout << "Enter a number: ";
	double x;
	std::cin >> x;

	try // kivételek után néz a try blokkon belül, ha talál a catch blokkhoz irányítja
	{
		// leellenőrzi, hogy az input negatív szám-e
		if (x < 0.0)
			throw "Can not take sqrt of negative number"; // egy throw állítás const char* típusból

		// ha nem kap akkor kiírja a választ.
		std::cout << "The sqrt of " << x << " is " << sqrt(x) << '\n';
	}

	catch (const char* exception) // catch const char* típusból
	{
		std::cerr << "Error: " << exception << '\n';
	}

	return 0;
}