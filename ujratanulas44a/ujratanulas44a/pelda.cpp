#include "stdafx.h"
#include <iostream>


int main()
{
	int szam1 = 10;
	int szam2 = 4;

	float f1 = (float)szam1 / (float)szam2;
	std::cout << f1 << "\n";

	float f2 = static_cast<float>(szam1) / static_cast<float>(szam2);
	std::cout << f2 << "\n";

	return 0;
}