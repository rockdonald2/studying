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
			throw b; // direkt változó továbbdobás, helytelen = object slicing
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
			throw ; // indirekt változó továbbdobás, helyes = nincs object slicing
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