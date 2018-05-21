#include "stdafx.h"
#include <iostream>

int main()
{
	double szam = 5.0;
	std::cout << sizeof(szam) << "\n"; // ez a sizeof operátor

	int x = 0;
	int y = 2;
	int z = (++x, ++y); // ez a comma operátor
	std::cout << z << "\n";

	/*int nagyobb;
	if (x > y)
		nagyobb = x;           // hosszabb if kifejezés
	else
		nagyobb = y;*/
	
	const int larger = (x > y) ? x : y;   // rövidebb if kifejezés.
	std::cout << larger << "\n";


	return 0;
}