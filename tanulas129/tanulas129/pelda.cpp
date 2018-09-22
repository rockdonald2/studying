#include "pch.h"
#include <iostream>
#include <string>

class Base
{
protected:
	int m_value;

public:
	Base(int value) : m_value(value) {}

	virtual ~Base() {}
};

class Derived : public Base
{
protected:
	std::string m_name;

public:
	Derived(int value, std::string name) : Base(value), m_name(name) {}

	const std::string& getName() { return m_name; }
};

Base* getObject(bool bReturnDerived)
{
	if (bReturnDerived)
	{
		return new Derived(1, "Apple");
	}
	else
		return new Base(2);
}

int main()
{
	/*Base *b = getObject(false);
	// hogyan �rjuk ki a Derived object nev�t itt, ha csak egy base mutat�nk van?
	Derived *d = dynamic_cast<Derived*>(b); // false eset�ben sikertelen dinamikus cast
	if (d) // d null pointer lesz, ekkor ez a sor kihagy�dik
		std::cout << d->getName() << '\n';

	delete b;*/

	Derived d(1, "Apple");
	Base &b = d;
	Derived &rD = dynamic_cast<Derived&>(b);
	std::cout << rD.getName() << '\n';

	return 0;
}