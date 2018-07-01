#include "stdafx.h"
#include <iostream>

/*class Valami
{
public:
	int m_ertek = 1;
};

int main()
{
	Valami elso;
	Valami masodik;

	elso.m_ertek = 2;

	std::cout << elso.m_ertek << '\n';
	std::cout << masodik.m_ertek << '\n';

	return 0;
}*/

class Valami
{
public:
	static int s_ertek;
};

int Valami::s_ertek = 1;

int main()
{
	Valami elso;
	Valami masodik;

	elso.s_ertek = 2;

	std::cout << elso.s_ertek << '\n';
	std::cout << masodik.s_ertek << '\n';

	return 0;
}