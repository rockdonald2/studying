#include "stdafx.h"
#include <iostream>
#include <sstream> // std::stringstream
#include <cstdlib> // exit()

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		// néhány operációs rendszeren, argv[0] akár üres stringként végződhet mintsem a program neveként
		// kondiciónáljuk a válaszunk arra vonatkozóan, hogy argv[0] üres vagy sem.
		if (argv[0])
			std::cout << "Használat: " << argv[0] << " <szam>" << '\n';
		else
			std::cout << "Használat: <programneve> <szam>" << '\n';

		exit(1);
	}

	std::stringstream convert(argv[1]); // felállítunk egy stringstream változót convert néven, inicializáljuk az inputtal
										// az argv[1]-ből

	int myint;
	if (!(convert >> myint)) // elvégzi az átalakítást
		myint = 0; // ha sikertelen, myint-t az alapértékre állítja

	std::cout << "A kapott szam: " << myint << '\n';

	return 0;
}
