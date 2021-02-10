#include "stdafx.h"
#include <iostream>

/*struct DatumStruct
{
	int ev;
	int honap;
	int nap;
};

// == a kettő majdnem ugyanaz.

class DatumClass
{
public:
	int m_ev;
	int m_honap;
	int m_nap;

	void kiir() // meghatározunk egy tag funkciót.
	{
		std::cout << m_ev << "/" << m_honap << "/" << m_nap;
	}
};

void kiirDatum(DatumStruct &ma)
{
	std::cout << ma.ev << "/" << ma.honap << "/" << ma.nap;
}

int main()
{
	DatumClass maC{ 2018, 6, 23 }; // meghatározunk egy változót a 'DatumClass' típusból.
	DatumStruct maS{ 2018, 6, 23 };

	maC.kiir(); // használjuk a tag kiválasztó operátort ahhoz, hogy lehívjuk a tag funkciót a classból.
	std::cout << '\n';
	kiirDatum(maS);

	return 0;
}*/


/*
Hozz létre egy classot 'IntPair' néven ami tartlmaz két integert.
	Ez a classnak tartalmaznia kell két tag változót, ami integert tartalmaz.
		Létre kellene hozzál még két tag funkciót is, egyiknek 'set' neve, ami lehetővé teszi, hogy hozzárendelj értékeket az integerekhez,
		és a másik 'print' névvel, ami kiírja a változók értékeit.
*/

class IntPair
{
public:
	int m_n1;
	int m_n2;

	void set(int n1set, int n2set)
	{
		m_n1 = n1set;
		m_n2 = n2set;
	}

	void print()
	{
		std::cout << "Az elso szam " << m_n1 << " , a masodik szam " << m_n2 << 
			"\nAzaz a par a (" << m_n1 << "," << m_n2 << ")" << '\n';
	}
};

int main()
{
	IntPair p1;
	p1.set(1, 1); // p1 értékét (1, 1)-re állítja

	IntPair p2{ 2, 2 }; // inicializálja a p2 értékeit (2, 2)-re

	p1.print();
	p2.print();

	return 0;
}