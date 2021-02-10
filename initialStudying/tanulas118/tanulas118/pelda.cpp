#include "pch.h"
#include <iostream>

class Base
{
private:
	int m_value;

public:
	Base(int value) : m_value(value) {}

protected:
	int getValue() { return m_value; }
};


class Derived : public Base
{
public:
	Derived(int value) : Base(value) {}

	using Base::getValue;
};