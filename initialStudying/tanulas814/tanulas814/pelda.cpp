#include "stdafx.h"
#include <iostream>

/*int osszead(int x, int y)
{
	return x + y; // anonymous object, csak arra van, hogy raktározza és returnolja az x+y értékét.
}

void kiir(int ertek)
{
	std::cout << ertek;
}

int main()
{
	std::cout << osszead(3, 5);

	kiir(5 + 3); // vagy akár ez is anonymous objectnek számit

	return 0;
}*/


class Bani
{
private:
	int m_bani;

public:
	Bani(int bani) { m_bani = bani; }

	int leker() const
	{
		return m_bani;
	}
};

Bani osszead(const Bani &bani1, const Bani &bani2)
{
	return bani1.leker() + bani2.leker();
}


void kiir(const Bani &bani)
{
	std::cout << bani.leker() << " bani.\n";
}

int main()
{
	kiir(Bani(5));

	std::cout << "Van nekem " << osszead(Bani(6), Bani(4)).leker() << " banim.\n";

	return 0;
}