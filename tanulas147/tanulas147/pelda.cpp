#include "pch.h"
#include <iostream>

/*class A
{
private:
	int m_x;
public:
	A(int x) : m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	B(int x) : A(x)
	{
		// Mi történik akkor ha az A létrehozása sikertelen és mi kezelni akarjuk itt?
	}
};

int main()
{
	try
	{
		B b(0);
	}

	catch (int)
	{
		std::cout << "Oops!\n";
	}

	return 0;
}*/

class A
{
private:
	int m_x;
public:
	A(int x) : m_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	B(int x) try : A(x) // a try kulcsszó itt jelenik meg, jelzi, hogy ez egy funkció try blokk
	{
		
	}

	catch (...)
	{
		// kivételek a member initializer listból, illetve a konstruktőr bodyból itt lesznek elkapva
		std::cerr << "Construction of A failed\n";

		// ha egy kivétel nincs kifejezetten dobva innen, akkor a jelenlegi kivétel lesz magától értetődően
			//továbbdobva
	}
};

int main()
{
	try
	{
		B b(0);
	}

	catch (int)
	{
		std::cout << "Oops!\n";
	}

	return 0;
}