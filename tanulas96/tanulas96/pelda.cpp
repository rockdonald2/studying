#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Car
{
private:
	std::string m_make;
	std::string m_model;

public:
	Car(std::string make, std::string model) : m_make(make), m_model(model)
	{}

	friend bool operator==(const Car &c1, const Car &c2);
	friend bool operator!=(const Car &c1, const Car &c2);

	friend bool operator<(const Car &c1, const Car &c2);
	friend std::ostream& operator<<(std::ostream &out, const Car &c);
};

bool operator==(const Car &c1, const Car &c2)
{
	return(c1.m_make == c2.m_make && c1.m_model == c2.m_model);
}

bool operator!=(const Car &c1, const Car &c2)
{
	return !(c1 == c2);
}

bool operator<(const Car &c1, const Car &c2)
{
	if (c1.m_make == c2.m_make)
		return c1.m_model < c2.m_model;
	else
		return c1.m_make < c2.m_make;
}

std::ostream& operator<<(std::ostream &out, const Car &c)
{
	out << "(" << c.m_make << ", " << c.m_model << ")";

	return out;
}


class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) : m_cents(cents)
	{}

	friend bool operator> (const Cents &c1, const Cents &c2);
	friend bool operator<= (const Cents &c1, const Cents &c2);

	friend bool operator< (const Cents &c1, const Cents &c2);
	friend bool operator>= (const Cents &c1, const Cents &c2);
};

bool operator>(const Cents &c1, const Cents &c2)
{
	return c1.m_cents > c2.m_cents;
}

bool operator>=(const Cents &c1, const Cents &c2)
{
	return c1.m_cents >= c2.m_cents;
}

bool operator<(const Cents &c1, const Cents &c2)
{
	return !(c1 > c2);
}

bool operator<=(const Cents &c1, const Cents &c2)
{
	return !(c1 >= c2);
}


int main()
{
	Car corolla("Toyota", "Corolla");
	Car camry("Toyota", "Camry");

	if (corolla == camry)
		std::cout << "A Corolla es a Camry ugyanaz a tipusu jarmu.\n";
	if (corolla != camry)
		std::cout << "A Corolla es a Camry nem ugyanaz a tipusu jarmu.\n";

	Cents dime(10);
	Cents nickel(5);

	if (nickel > dime)
		std::cout << "Egy otcentes nagyobb mint egy tizcentes.\n";
	if (nickel >= dime)
		std::cout << "Egy otcentes nagyobb vagy egyenlo mint egy tizcentes.\n";
	if (nickel < dime)
		std::cout << "Egy otcentes kisebb mint egy tizcentes.\n";
	if (nickel <= dime)
		std::cout << "Egy otcentes kisebb vagy egyenlo mint egy tizcentes.\n";

	std::vector<Car> v;
	v.push_back(Car("Toyota", "Corolla"));
	v.push_back(Car("Honda", "Accord"));
	v.push_back(Car("Toyota", "Camry"));
	v.push_back(Car("Honda", "Civic"));

	std::sort(v.begin(), v.end());

	for (auto &car : v)
		std::cout << car << '\n';

	return 0;
}