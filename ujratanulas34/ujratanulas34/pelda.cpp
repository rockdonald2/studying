#include "stdafx.h"
#include <iostream>

int main()
{
	double szam = 5.0;
	std::cout << sizeof(szam) << "\n"; // ez a sizeof oper�tor

	int x = 0;
	int y = 2;
	int z = (++x, ++y); // ez a comma oper�tor
	std::cout << z << "\n";

	/*int nagyobb;
	if (x > y)
		nagyobb = x;           // hosszabb if kifejez�s
	else
		nagyobb = y;*/
	
	const int larger = (x > y) ? x : y;   // r�videbb if kifejez�s.
	std::cout << larger << "\n";


	return 0;
}