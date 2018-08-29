#include "pch.h"
#include <iostream>

/*class Base
{
private:
	int m_id;

public:
	Base(int id = 0) : m_id(id)
	{}

	int getId() const
	{
		return m_id;
	}
};


class Derived : public Base
{
private:
	double m_cost;

public:
	Derived(double cost  = 0.0, int id = 0) : Base(id), m_cost(cost)
	{}

	double getCost() const
	{
		return m_cost;
	}
};


int main()
{
	Derived cD(1.7, 9);

	std::cout << "Cost: " << cD.getCost() << '\n';
	std::cout << "Id: " << cD.getId() << '\n';

	return 0;
}*/

#include <string>

class Fruit
{
private:
	std::string m_name;
	std::string m_color;

public:
	Fruit(std::string name="", std::string color="") : m_name(name), m_color(color)
	{}

	std::string getName() const { return m_name; }
	std::string getColor() const { return m_color; }
};


class Apple : public Fruit
{
private:
	double m_fiber;

public:
	Apple(std::string name, std::string color, double fiber) : Fruit(name, color), m_fiber(fiber)
	{}

	friend std::ostream& operator<<(std::ostream &out, const Apple &a)
	{
		out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.m_fiber << ")";

		return out;
	}
};


class Banana : public Fruit
{
public:
	Banana(std::string name, std::string color) : Fruit(name, color)
	{}

	friend std::ostream& operator<<(std::ostream &out, const Banana &b)
	{
		out << "Banana(" << b.getName() << ", " << b.getColor() << ")";

		return out;
	}
};


int main()
{
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a << '\n';

	const Banana b("Cavendish", "yellow");
	std::cout << b << '\n';

	return 0;
}