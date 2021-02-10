#include "stdafx.h"
#include <iostream>

class Gyumolcs
{
public:

	enum Gyumolcstipus
	{
		ALMA,
		BANAN,
		CSERESZNYE,
	};

private:

	Gyumolcstipus m_gyumolcs;
	int m_megevettSzazalek;

public:

	Gyumolcs(Gyumolcstipus gyumolcs) : m_gyumolcs(gyumolcs) {}
	Gyumolcstipus lekerGyumolcs() { return m_gyumolcs; }
	int lekerMegevettSzazalek() { return m_megevettSzazalek; }
};

int main()
{
	Gyumolcs alma(Gyumolcs::ALMA);

	if (alma.lekerGyumolcs() == Gyumolcs::ALMA)
		std::cout << "Ez egy alma.\n";
	else
		std::cout << "Ez nem egy alma.\n";

	return 0;
}