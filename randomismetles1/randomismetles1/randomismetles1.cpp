#include "stdafx.h"
#include <iostream>

/*

hozz létre egy enum class-ot amely tartalmaz állatokat, malac, csirke, kecske, macska, kutya, strucc.
írj egy funkciót amely használja az állatot mint paramétert, majd használ egy switch állítást, hogy visszaadja az állat
nevét mint string.
írj egy másik funkciót amely használ egy switch állítást, hogy kiírja az adott állat hány lábon jár.
	mindkét switch állításnak tartalmaznia kell default labelt, amely ERROR kódot ad vissza.

*/

enum class Allat
{
	MALAC,
	CSIRKE,
	KECSKE,
	MACSKA,
	KUTYA,
	STRUCC,
};

#include <string>

std::string kiIrAllatNeve(Allat allat)
{
	switch (allat)
	{
	case Allat::CSIRKE:
		return "csirke";
	case Allat::KECSKE:
		return "kecske";
	case Allat::MALAC:
		return "malac";
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

int kiIrHanyLabJar(Allat allat)
{
	switch(allat)
	{
	case Allat::KECSKE:
	case Allat::KUTYA:
	case Allat::MACSKA:
	case Allat::MALAC:
		return 4;
	case Allat::CSIRKE:
	case Allat::STRUCC:
		return 2;

	default:
		std::cout << "ERROR";
		return 0;
	}
}

void kiIrMinden(Allat allat)
{
	std::cout << "Ez a " << kiIrAllatNeve(allat) << " mind a " << kiIrHanyLabJar(allat) << " laban jarni kepes.\n";
}

int main()
{
	Allat allat1 = Allat::CSIRKE;
	Allat allat2 = Allat::MACSKA;

	kiIrMinden(allat1);
	kiIrMinden(allat2);

	return 0;
}