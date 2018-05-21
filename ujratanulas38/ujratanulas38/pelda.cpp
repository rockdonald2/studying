#include "stdafx.h"
#include <iostream>

int lekerSzam()
{
	std::cout << "Irj be egy szamot: ";
	int szam;
	std::cin >> szam;

	return szam;
}

int csusztatasMerteke()
{
	std::cout << "Ird be hany bittel akarod valtani: ";
	int bit;
	std::cin >> bit;

	return bit;
}

int main()
{
	int x = lekerSzam();
	int y = csusztatasMerteke();

	int csusztatBal = x << y;
	std::cout << "A beirt szamod balra valo valtasa utan: " << csusztatBal << " \n";

	int csusztatJobb = x >> y;
	std::cout << "A beirt szamod jobbra valo valtasa utan: " << csusztatJobb << " \n";

	int notX = ~x; // két kiegészítő szabállyal mükődik.
	std::cout << "A beirt szamod tagadas utan: " << notX << " \n";

	int orX = x | y;
	std::cout << "A ket beird szamod bitwise OR szaballyal: " << orX << " \n";

	int andX = x & y;
	std::cout << "A ket beirt szamod bitwise AND szaballyal: " << andX << " \n";

	int xorX = x ^ y;
	std::cout << "A ket beirt szamod bitwise XOR szaballyal: " << xorX << " \n";

	return 0;
	
}