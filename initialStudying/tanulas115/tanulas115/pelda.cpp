#include "pch.h"
#include <iostream>

class Base
{
private:
	int m_private; // csak a Base tagok illetve a friends classok érhetik el

public:
	int m_public; // bárki elérheti

protected:
	int m_protected; // csak a Base tagok, illetve a friends + öröklési classok érhetik el
};


class Derived : public Base
	// public inheritance, megőrzik a hozzáférésüket a Base classból
{
public:
	Derived()
	{
		m_public = 5; // engedélyezett, mivel bárki elérheti
		// m_private = 4; // nem engedélyezett, mivel a privát tag nem érhető el innen
		m_protected = 3; // engedélyezett, mivel öröklési viszony áll fent
	}
};


int main()
{
	Base base;
	base.m_public = 5; // engedélyezett
	//base.m_private = 4; // elérhetetlen
 	//base.m_protected = 3; // elérhetetlen

	Derived der;
	der.m_public = 5; // engedélyezett
	//der.m_private = 4; // elérhetletlen
	//der.m_protected = 3; // elérhetetlen
	return 0;
}