#include "pch.h"
#include <iostream>

/*class A
{
public:
	virtual const char* getName1(int x) { return "A"; }
	virtual const char* getName2(int x) { return "A"; }
};

class B : public A
{
public:
	virtual const char* getName1(short int x) override { return "B"; } // megjegyz�s: param�ter k�l�nb�zik, compile error
	virtual const char* getName2(int x) const override { return "B"; } // megjegyz�s: const funkci�, compile error
};

int main()
{
	B b;
	A &rBase = b;
	std::cout << rBase.getName1(1) << '\n';
	std::cout << rBase.getName2(2) << '\n';

	return 0;
}*/

class Base
{
public:
	virtual Base* getThis() { std::cout << "called Base::getThis().\n"; return this; }
	void printType() { std::cout << "return a Base\n"; }
};

class Derived : public Base
{
public:
	virtual Derived* getThis() { std::cout << "called Derived::getThis().\n"; return this; }
	void printType() { std::cout << "return a Derived\n"; }
};

int main()
{
	Derived d;
	Base *rB = &d;

	d.getThis()->printType(); // leh�vja a Derived::getThis()-t, majd visszaad egy Derived*-ot, �s leh�vja a Derived::printType()-ot
	rB->getThis()->printType(); // leh�vja a Derived::getThis()-t majd visszaad egy Base*t(igaz�b�l Derived*) �s leh�vja a Base::printType()-ot

	return 0;
}

