#include "pch.h"
#include <iostream>

/*class Base
{
public:
	Base() {}
	virtual void print() { std::cout << "Base"; }
};

class Derived : public Base
{
public:
	Derived() {}
	virtual void print() { std::cout << "Derived"; }
};

int main()
{
	try
	{
		try
		{
			throw Derived();
		}
		catch (Base &b)
		{
			std::cout << "We caught Base b, which is actually a ";
			b.print();
			std::cout << '\n';
			throw b; // direkt v�ltoz� tov�bbdob�s, helytelen = object slicing
		}
	}
	catch (Base &b)
	{
		std::cout << "We caught Base b, which is actually a ";
		b.print();
		std::cout << '\n';
	}

	return 0;
}*/

class Base
{
public:
	Base() {}
	virtual void print() { std::cout << "Base"; }
};

class Derived : public Base
{
public:
	Derived() {}
	virtual void print() { std::cout << "Derived"; }
};

int main()
{
	try
	{
		try
		{
			throw Derived();
		}
		catch (Base &b)
		{
			std::cout << "We caught Base b, which is actually a ";
			b.print();
			std::cout << '\n';
			throw ; // indirekt v�ltoz� tov�bbdob�s, helyes = nincs object slicing
		}
	}
	catch (Base &b)
	{
		std::cout << "We caught Base b, which is actually a ";
		b.print();
		std::cout << '\n';
	}

	return 0;
}