#include "pch.h"
#include <iostream>

class Base
{
protected:
	int m_value;

private:
	void base() { std::cout << "I am private\n"; }

public:
	Base(int value) : m_value(value)
	{}

	void identify() { std::cout << "I am a base\n"; }

	friend std::ostream& operator<< (std::ostream &out, Base &b)
	{
		out << "In base\n";
		out << b.m_value << '\n';

		return out;
	}
};

class Derived : public Base
{
public:
	Derived(int value) : Base(value)
	{}

	int getValue() { return m_value; }

	void identify() 
	{ 
		Base::identify();
		std::cout << "I am a derived\n"; 
	}

	void base() { std::cout << "I am public\n"; }

	friend std::ostream& operator<< (std::ostream &out, Derived &d)
	{
		out << "In derived";
		out << static_cast<Base>(d);

		return out;
	}
};

int main()
{
	Base base(5);
	base.identify();

	Derived derived(7);
	derived.identify();
	
	derived.base(); // a publikus funkciót hívja le.


	return 1667;

}