#include "stdafx.h"
#include <iostream>


int main()
{

	// lehet nem const értékekből, constot csinálni.
	std::cout << "Ird be a korodat: ";
	int kor;
	std::cin >> kor;

	const int felhasznaloKora(kor); // ezután nem lehet modosítani
}