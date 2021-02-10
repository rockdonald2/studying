#include "pch.h"
#include <iostream>

class Base
{
public:
	int m_id;

	Base(int id = 0) : m_id(id)
	{
		std::cout << "Base\n";
	}

	int getID() const
	{
		return m_id;
	}
};


class Derived : public Base
{
public:
	double m_cost;

	Derived(int cost = 0.0) : m_cost(cost)
	{
		std::cout << "Derived\n";
	}

	double getCost() const
	{
		return m_cost;
	}
};


int main()
{
	std::cout << "Instantiating Base\n";
	Base cB;

	std::cout << "Instantiating Derived\n";
	Derived cD;

	return 0;
}