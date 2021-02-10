#include "stdafx.h"
#include <iostream>

int kerjunkLeSzamokat()
{
	std::cout << "Irj be egy szamot: ";
	int szam;
	std::cin >> szam;

	return szam;
}


void logicalNOTPelda(int a, int b)
{
	if (!(a == b))
		std::cout << "A ket szam nem egyenlo!\n";
	else
		std::cout << "A ket szam egyenlo!\n";

	
}

void logicalORPelda(int a, int b)
{
	if (a == 2 || a == 3 || b == 2 || b == 3)
		std::cout << "Ugyan arra a szamra gondoltunk!\n";
	else
		std::cout << "Nem egy szamra gondoltunk, sss..!\n";
	
	
}

void logicalANDPelda(int a, int b)
{
	if (a < 10 && b > 0)
		std::cout << "Majdnem ugyan arra a szamra gondoltunk!\n";
	else
		std::cout << "Nebah', eszembe se jutott ilyen nagy szam.\n";


}


int main()
{
	int a = kerjunkLeSzamokat();
	int b = kerjunkLeSzamokat();

	logicalNOTPelda(a, b);
	logicalORPelda(a, b);

	std::cout << "A szamok: " << a << b << "\n";

	logicalANDPelda(a, b);
	

	return 0;
}