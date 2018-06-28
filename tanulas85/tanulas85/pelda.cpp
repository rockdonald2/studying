#include "stdafx.h"
#include <iostream>
#include <cassert>

/*class Tort
{
private:
	int m_szamlalo;
	int m_nevezo;

public:

	// fölösleges alapértelmezett konstruktőr
	/*Tort() // alapértelmezett konstruktőr
	{
		m_szamlalo = 0;
		m_nevezo = 1;
	}*/ 

	
	/*	// mivel a szamlalohoz is alapértéket biztosítottunk, a fenti konstruktőr fölösleges lett.
	Tort(int szamlalo = 0, int nevezo = 1) // egy konstruktőr két paraméterrel, amelyben egy paraméter alapértékkel rendelkezik.
	{
		assert(nevezo != 0);
		m_nevezo = nevezo;
		m_szamlalo = szamlalo;
	}

	int lekerSzamlalo() { return m_szamlalo; }
	int lekerNevezo() { return m_nevezo; }
	double elvegez() { static_cast<double>(m_szamlalo) / m_nevezo; }
};

int main()
{
	Tort trt1; // mivel nem szolgáltattunk semmilyen érvet, az alapértelmezett konstruktőr lesz lehívva
	std::cout << trt1.lekerSzamlalo() << "/" << trt1.lekerNevezo() << '\n';

	Tort trt2(5, 3); // mivel szolgáltattunk érveket, ezért a paraméteres konstruktőr lesz lehívva.
	std::cout << trt2.lekerSzamlalo() << "/" << trt2.lekerNevezo() << '\n';

	Tort nulla; // a Tort(0,1) lesz lehívva, alapértelmezett
	Tort hat(6); // a Tort(6,1) lesz lehívva, egy paraméter szolgáltatva
	Tort otHarmad(5, 3); // a Tort(5,3) lesz lehívva, két paraméter szolgáltatva.

	return 0;
}*/


/*class A
{
public:
	A() { std::cout << "A\n"; }
	
};

class B
{
private:
	A m_a;

public:
	B() { std::cout << "B\n"; }
};

int main()
{
	B b;

	return 0;
}*/

#include <string>

class Ball
{
private:
	std::string m_color;
	double m_radius;

public:
	//Ball() : m_color("black"), m_radius(10.0)
	//{}

	Ball(std::string color = "black", double radius = 10.0): m_color(color), m_radius(radius)
	{}

	//Ball(std::string color = "black") : m_color(color), m_radius(10.0)
	//{}

	Ball(double radius) : m_radius(radius), m_color("black")
	{}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << "\n";
	}
};


int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

	return 0;
}