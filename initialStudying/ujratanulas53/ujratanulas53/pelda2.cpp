#include "stdafx.h"
#include <iostream>

/*

Határozz meg egy enum class-ot, Allat neven, ami tartalmazza a következő állatokat: DISZNO, CSIRKE, KECSKE, MACSKA, KUTYA, STRUCC.
Irj egy funkciót lekerAllatNeve(), ami fogja az Allat parametert es hasznal egy switch állítást, hogy visszaadja az álatt nevét stringként.
Irj egy másik funkciót ami kiIrHanyLabonJar(), ami használja a switch állítást, hogy kiírja az adott állat hány lábon jár.

	mindkét switchnek kell legyen default case amit errort ír ki.

	példázd egy macskával és egy csirkével.

*/

#include <string>

enum class Allat
{
	DISZNO,
	CSIRKE,
	KECSKE,
	MACSKA,
	KUTYA,
	STRUCC,
};

std::string lekerAllatNeve(Allat allat)
{
	switch (allat)
	{
	case Allat::DISZNO:
		return "diszno";
	case Allat::CSIRKE:
		return "csirke";
	case Allat::KECSKE:
		return "kecske";
	case Allat::MACSKA:
		return "macska";
	case Allat::KUTYA:
		return "kutya";
	case Allat::STRUCC:
		return "strucc";

	default:
		return "ERROR";
	}		
}

int kiIrHanyLabonJar(Allat allat)
{
	switch (allat)
	{
	case Allat::DISZNO:
	case Allat::KECSKE:
	case Allat::KUTYA:
	case Allat::MACSKA:
		return 4;
	case Allat::CSIRKE:
	case Allat::STRUCC:
		return 2;

	default:
		std::cout << "ERROR" << "\n";
		return 0;
	}
}

int main()
{
	Allat allat = Allat::MACSKA;
	Allat allat2 = Allat::CSIRKE;

	std::cout << "A " << lekerAllatNeve(allat) << "nak van " << kiIrHanyLabonJar(allat) << " laba. \n";
	std::cout << "A " << lekerAllatNeve(allat2) << "nek van " << kiIrHanyLabonJar(allat2) << " laba. \n";

	return 0;
}