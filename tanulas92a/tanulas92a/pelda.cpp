#include "stdafx.h"
#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0) : m_cents(cents)
	{}

	int getCents() const
	{
		return m_cents;
	}
};


Cents operator+(const Cents &c1, const Cents &c2)
{
	// ez esetben nem szükséges a direkt elérés a privát tag változóhoz
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	Cents c1(5);
	Cents c2(7);
	Cents centSum = c1 + c2;

	std::cout << centSum.getCents() << '\n';

	return 0;
}