#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>


/*class Base
{
protected:
	int m_value;

public:
	Base(int value) : m_value(value) {}

	const char* getName() { return "Base"; }
	int getValue() { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value) : Base(value) {}

	const char* getName() { return "Derived"; }
	int getValueDoubled() { return m_value * 2; }
};

int main()
{
	Derived d(5);
	Derived *pD = &d;
	Derived &rD = d;

	std::cout << "A d az egy " << d.getName() << " es az erteke az " << d.getValue() << ".\n";
	std::cout << "A rD az egy " << rD.getName() << " es az erteke az " << rD.getValue() << ".\n";
	std::cout << "A pD az egy " << pD->getName() << " es az erteke az " << pD->getValue() << ".\n";

	Base *pB = &d;
	Base &rB = d;

	std::cout << "A rB az egy " << rB.getName() << " es az erteke az " << rB.getValue() << ".\n";
	std::cout << "A pB az egy " << pB->getName() << " es az erteke az " << pB->getValue() << ".\n";

	return 0;
}*/


class Animal
{
protected:
	std::string m_name;	
	const char* m_speak;

	Animal(std::string name, const char* speak) : m_name(name), m_speak(speak) { }

public:
	std::string getName() { return m_name; }
	const char* speak() { return m_speak; }
};

class Cat : public Animal
{
public:
	Cat(std::string name) : Animal(name, "meow") {  }

	const char* speak() { return "meow"; }
};

class Dog : public Animal
{
public:
	Dog(std::string name) : Animal(name, "woof") {  }

	const char* speak() { return "woof"; }
};


int main()
{
	Cat fred("Fred"), misty("Misty"), zeke("Zeke");
	Dog garbo("Garbo"), pooky("Pooky"), truffle("Truffle");

	// Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
	Animal *animals[] = { &fred, &garbo, &misty, &pooky, &truffle, &zeke };
	for (int iii = 0; iii < 6; iii++)
		std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << '\n';

	return 0;
}