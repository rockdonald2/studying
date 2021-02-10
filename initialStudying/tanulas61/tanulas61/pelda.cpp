#include "stdafx.h"
#include <iostream>

int main()
{
	int primSzam[5]; // lefoglalunk egy 5 hosszúságú arrayt, amit primSzam-nak hívunk, az első 5 prímszám tartozik bele.
	primSzam[0] = 2; // első elem 0-ás indexel.
	primSzam[1] = 3;
	primSzam[2] = 5;
	primSzam[3] = 7;
	primSzam[4] = 11;

	std::cout << "A legkisebb primszam a " << primSzam[0] << ".\n";
	std::cout << "Az elso ot primszam osszege " << primSzam[0] + primSzam[1] + primSzam[2] + primSzam[3] + primSzam[4] << ".\n";

	return 0;
}