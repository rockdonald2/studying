#include "stdafx.h"
#include <iostream>

int lekerSzam()
{ // blokk kezdete
	std::cout << "Irj be egy szamot: ";
	int szam;
	std::cin >> szam;

	return szam;
} // blokk v�ge

void vizsgalSzam(int szam)
{ // blokk kezdete
	if (szam > 0)
	{ // bef�szkelt blokk kezdete
		std::cout << "Elfogadhato szam.\n";
		std::cout << "A szamod " << szam << " nagyobb mint nulla.\n";
	} // bef�szkelt blokk v�ge
	else if (szam == 0)
	{ // bef�szkelt blokk kezdete
		std::cout << "Nafene, milyen szam ez.\n";
		std::cout << "A szamod " << szam << "\n";
	} // bef�szkelt blokk v�ge
	else
		std::cout << "Atomtamadast vegrehajtani!\n";
} // blokk v�ge

int main()
{ // blokk kezdete
	int x = lekerSzam();

	vizsgalSzam(x);

	return 0;
} // blokk v�ge