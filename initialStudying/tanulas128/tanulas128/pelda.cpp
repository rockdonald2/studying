#include "pch.h"
#include <iostream>
#include <vector>
#include <functional>

class Base
{
protected:
	int m_value;

public:
	Base(int value) : m_value(value) {}

	virtual const char* getName() { return "Base"; }
	int getValue() { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value) : Base(value) {}

	virtual const char* getName() { return "Derived"; }
};

void printName(Base &base) // megjegyzés, vedd észre pass by value érvényesül
{
	std::cout << base.getName() << '\n';
}

/*int main()
{
	Derived d(5);
	Base &ref = d;
	Base *ptr = &d;

	std::cout << d.getName() << ":" << d.getValue() << '\n';
	std::cout << ref.getName() << ":" << ref.getValue() << '\n';
	std::cout << ptr->getName() << ":" << ptr->getValue() << '\n';

	Base b = d; // hozzárendeltünk egy derived objectet egy base objecthez

	std::cout << b.getName() << ":" << b.getValue() << '\n';

	printName(d);

	//std::vector<Base*> v;
	//v.push_back(new Base(5));
	//v.push_back(new Derived(6));

	//for (int count = 0; count < v.size(); ++count)
		//std::cout << v[count]->getName() << ":" << v[count]->getValue() << '\n';
	
	//for (int count = 0; count < v.size(); ++count)
		//delete v[count];

	std::vector<std::reference_wrapper<Base>> v;
	Base b1(5);
	Derived d1(6);
	v.push_back(b1);
	v.push_back(d1);
	for (int count = 0; count < v.size(); ++count)
		std::cout << v[count].get().getName() << ":" << v[count].get().getValue() << '\n';

	return 0;
}*/

int main()
{
	Derived d1(5);
	Derived d2(6);

	Base &b = d2;

	b = d1; // ez a problémás sor

	return 0;
}