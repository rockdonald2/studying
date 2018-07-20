#include "stdafx.h"
#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) : m_cents(cents)
	{}

	Cents operator+(int value);
	Cents operator+(Cents &c);
	friend std::ostream& operator<< (std::ostream &out, const Cents &c);

	int getCents() { return m_cents; }
};


Cents Cents::operator+(int value)
{
	return Cents(m_cents + value);
}

Cents Cents::operator+(Cents &c)
{
	return Cents(m_cents + c.m_cents);
}

std::ostream& operator<< (std::ostream &out, const Cents &c)
{
	out << c.m_cents;

	return out;
}


int main()
{
	Cents c1(5);
	Cents c2(7);
	Cents cSum1 = c1 + c2;
	Cents cSum2 = c1 + 5;

	std::cout << "Van nekem: " << cSum1 << " centem.\n";
	std::cout << "Van nekem: " << cSum2 << " centem.\n";


	return 0;
}