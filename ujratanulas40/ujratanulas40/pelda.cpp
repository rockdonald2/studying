#include "stdafx.h"
#include <iostream>

int lekerSzam()
{ // blokk kezdete
	std::cout << "Irj be egy szamot: ";
	int szam;
	std::cin >> szam;

	return szam;
} // blokk vége

void vizsgalSzam(int szam)
{ // blokk kezdete
	if (szam > 0)
	{ // befészkelt blokk kezdete
		std::cout << "Elfogadhato szam.\n";
		std::cout << "A szamod " << szam << " nagyobb mint nulla.\n";
	} // befészkelt blokk vége
	else if (szam == 0)
	{ // befészkelt blokk kezdete
		std::cout << "Nafene, milyen szam ez.\n";
		std::cout << "A szamod " << szam << "\n";
	} // befészkelt blokk vége
	else
		std::cout << "Atomtamadast vegrehajtani!\n";
} // blokk vége

int main()
{ // blokk kezdete
	int x = lekerSzam();

	vizsgalSzam(x);

	return 0;
} // blokk vége