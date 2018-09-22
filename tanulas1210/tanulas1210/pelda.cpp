#include "pch.h"
#include <iostream>

class Base
{
public:
	Base() {}

	friend std::ostream& operator<<(std::ostream &out, const Base &b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out) const { out << "Base"; return out; }
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived"; return out;
	}
};

int main()
{
	Derived d;
	Base b;
	Base &b1 = d;

	std::cout << d << '\n';
	std::cout << b << '\n';

	std::cout << "b1 is a " << b << '\n'; 
}