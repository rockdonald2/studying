#include "stdafx.h"
#include <iostream>
#include <string>

/*

�rj egy programot amelyben lek�red a felhaszn�l� teljes nev�t �s kor�t.
	Outputk�nt �rd ki a felhaszn�l�nak h�ny �vet �ltek minden bet��rt a nev�kben.(a whitespace is bet� ez esetben)

*/

std::string lekerNev()
{
	std::cout << "Ird be a teljes nevedet: ";
	std::string nev;
	std::getline(std::cin, nev);

	return nev;
}


double lekerKor()
{
	std::cout << "Ird be a korodat: ";
	double kor;
	std::cin >> kor;

	std::cin.ignore(32767, '\n');

	return kor;
}

int main()
{
	std::string nev = lekerNev();
	double kor = lekerKor();

	//std::cout << nev;
	//std::cout << kor;
	//std::cout << nev.length();

	std::cout << "Te eltel minden betuert korod alapjan: " << kor / nev.length() << "\n";

	return 0;
}