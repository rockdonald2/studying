#include "stdafx.h"
#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents = 0): m_cents(cents)
	{}

	void setCents(int cents)
	{
		m_cents = cents;
	}

	int getCents()
	{
		return m_cents;
	}

	operator int()
	{
		return m_cents;
	}
};

class Dollars
{
private:
	int m_dollars;

public:
	Dollars(int dollars = 0): m_dollars(dollars)
	{}

	operator Cents()
	{
		return Cents(m_dollars * 100);
	}
};

void printInt(int value)
{
	std::cout << value << '\n';
}

void printCents(Cents cents)
{
	std::cout << cents << '\n';
}

int main(void)
{
	Cents cents(7);
	printInt(cents);

	Dollars dollars(5);
	printCents(dollars);

	return 0;
}