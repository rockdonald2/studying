#include "stdafx.h"
#include <iostream>

// ki�rja a szorz�t�bl�t
int main()
{
	const int tablazatSor = 10;
	const int tablazatOszlop = 10;
	int tablazat[tablazatSor][tablazatOszlop] = { 0 };

	for (int sor = 0; sor < tablazatSor; ++sor)
		for (int oszlop = 0; oszlop < tablazatOszlop; ++oszlop)
			tablazat[sor][oszlop] = sor * oszlop;

	for (int sor = 0; sor < tablazatSor; ++sor)
	{ 
		for (int oszlop = 0; oszlop < tablazatOszlop; ++oszlop)
			std::cout << tablazat[sor][oszlop] << '\t';

		std::cout << '\n';
	}

	return 0;

}