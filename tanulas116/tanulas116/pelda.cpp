#include "pch.h"
#include <iostream>

class Base
{
protected:
	int m_value;

public:
	Base(int value) : m_value(value)
	{}

	void identify() { std::cout << "I am a base\n"; }
};

class Derived : public Base
{
public:
	Derived(int value) : Base(value)
	{}

	int getValue() { return m_value; }
};