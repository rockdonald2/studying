#include "pch.h"
#include <iostream>

class Base
{
public:
	virtual ~Base()
	{
		std::cout << "called ~base\n";
	}

	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
protected:
	int *m_array;

public:
	Derived(int length)
	{
		int *m_array = new int[length];
	}

	virtual ~Derived()
	{
		std::cout << "called ~Derived\n";
		delete[] m_array;
	}

	virtual const char* getName() { return "Derived"; }
};

int main()
{
	Derived *derived = new Derived(5);
	Base *base = derived;
	std::cout << base->Base::getName() << '\n'; // így ignorálja a 'Derived::getName()' funkciót
	delete base;

	return 0;
}