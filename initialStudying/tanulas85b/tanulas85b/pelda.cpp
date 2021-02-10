#include "stdafx.h"
#include <iostream>

/*class Teglalap
{
private:
	double m_hossz = 1.0; // m_hossz tartalmaz egy alapértéket ami 1.0
	double m_szelesseg = 1.0; // m_szelesseg tartalmaz egy alapértéket ami 1.0

public:
	Teglalap()
	{
		// ez a konstruktőr az alapértékeket fogja használni, mivel azok itt nem lettek átírva.
	}

	void kiir()
	{
		std::cout << "Hossz: " << m_hossz << ", szelesseg: " << m_szelesseg << "\n";
	}
};

int main()
{
	Teglalap tgl; // tgl.m_hossz = 1.0; tgl.m_szelesseg = 1.0;
	tgl.kiir();

	return 0;
}*/

#include <string>

class Ball
{
private:
	// alap inicializáló értékek
	std::string m_color{ "black" };
	double m_radius{ 10.0 };

public:

	// alapértelmezett konstruktőr
	Ball()
	{}

	Ball(const std::string &color) : m_color(color)
	{
		// a radius az alapértéket fogja használni
	}

	Ball(double radius) : m_radius(radius)
	{
		// a color az alapértéket fogja használni
	}

	Ball(const std::string &color, double radius) : m_color(color), m_radius(radius)
	{}

	void print()
	{
		std::cout << "Color: " << m_color << ", radius: " << m_radius << "\n";
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