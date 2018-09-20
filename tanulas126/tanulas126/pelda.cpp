#include "pch.h"
#include <iostream>

class Animal
{
protected:
	std::string m_name;

	Animal(std::string name) : m_name(name) {} // protected, hogy csak a származtatott classok érhessék el

	std::string getName() { return m_name; }
	virtual const char* speak() = 0; // pure virtual function
};

class Cat : public Animal
{
public:
	Cat(std::string name) : Animal(name) {}

	virtual const char* speak() { return "meow"; }
};

class Dog : public Animal
{
public:
	Dog(std::string name) : Animal(name) {}

	virtual const char* speak() { return "woof"; }
};

class Cow : public Animal
{
public:
	Cow(std::string name) : Animal(name) {}

	// megjegyzés: nincs itt újrahatározva a speak() funckió
	// így ez is abstract base class, azaz nem lehet példázni
};

int main()
{
	Dog d("Murlock");
	Cat c("Samson");
	Cow cw("Kovacs"); // compiler error
	Animal a("Benedek"); // compiler error

	std::cout << d.speak() << '\n' << c.speak() << '\n';

	return 0;
}