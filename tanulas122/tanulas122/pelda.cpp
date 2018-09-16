#include "pch.h"
#include <iostream>

/*class Base
{
public:
	virtual const char* getName() { return "Base"; }
};

class Derived : public Base
{
public:
	virtual const char* getName() { return "Derived"; }
};

int main()
{
	Derived d;
	Base &rD = d;

	std::cout << "rD az egy " << rD.getName() << '\n';

	return 0;
}*/

#include <string>

class Animal
{
protected:
	std::string m_name;

	Animal(std::string name) : m_name(name) { }

public:
	std::string getName() { return m_name; }
	virtual const char* speak() { return "???"; }
};

class Cat : public Animal
{
public:
	Cat(std::string name) : Animal(name) { }

	const char* speak() { return "meow"; }
};

class Dog : public Animal
{
public:
	Dog(std::string name) : Animal(name) { }

	const char* speak() { return "woof"; }
};

void report(Animal *animal)
{
	std::cout << animal->getName() << " says " << animal->speak() << ".\n";
}

int main()
{
	Cat fred("Fred"), misty("Misty");
	Dog garbo("Garbo"), pooky("Pooky");

	Animal *animal[] = { &fred, &garbo, &misty, &pooky };
	for (int count = 0; count < 4; ++count)
		report(animal[count]);

	return 0;
}