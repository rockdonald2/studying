#include "stdafx.h"
#include <iostream>

class Szamologep
{
private:
	int m_ertek;

public:
	Szamologep() { m_ertek = 0; }
	Szamologep& osszead(int ertek) { m_ertek += ertek; return *this; }
	Szamologep& kivon(int ertek) { m_ertek -= ertek; return *this; }
	Szamologep& szoroz(int ertek) { m_ertek *= ertek; return *this; }
	Szamologep& oszt(int ertek) { m_ertek /= ertek; return *this; }

	int lekerErtek() { return m_ertek; }
};


int main()
{
	Szamologep eredmeny;
	eredmeny.osszead(5).kivon(3).szoroz(4);
	std::cout << eredmeny.lekerErtek();

	return 0;
}