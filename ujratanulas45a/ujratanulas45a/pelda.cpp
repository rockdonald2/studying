#include "stdafx.h"
#include <iostream>

enum class Szinek
{
	PIROS,
	FEHER,
	ZOLD,
};

enum class Alakzatok
{
	NEGYZET,
	KOR,
	HAROMSZOG,
};

int main()
{
	// Hozzárendelések
	Szinek szin1 = Szinek::PIROS; 
	Szinek szin2 = Szinek::ZOLD; 

	Alakzatok alakzat1 = Alakzatok::KOR;
	Alakzatok alakzat2 = Alakzatok::HAROMSZOG;

	/*if (szin1 == alakzat1)         // error, nem lehet különböző enum class-okat összehasonlítani.
		std::cout << "Az elso alakzat egyenlo a masodikkal.\n";
	else
		std::cout << "???";*/

	// std::cout << szin1;    // nincs számmá alakítás magától. 
	std::cout << static_cast<int>(szin1);

	return 0;


}