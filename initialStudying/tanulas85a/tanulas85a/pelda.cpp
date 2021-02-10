#include "stdafx.h"
#include <iostream>

/*class Valami
{
private:
	int m_a;
	int m_b;
	int m_c;

public:
	Valami() : m_a(1), m_b(2), m_c(3) // direct inicializálás
	{
		// nincs hozzárendelés
	}

	void kiir()
	{
		std::cout << "Valami(" << m_a << ", " << m_b << ", " << m_c << ")\n";
	}
};

int main()
{
	Valami valami;
	valami.kiir();

	return 0;
}*/


/*class Valami
{
private:
	const int m_array[5];

public:
	// array inicializálása uniform initialization-el.
	Valami() : m_array{ 1, 2, 3, 4, 5 }
	{

	}
};*/


/*class A
{
public:
	A(int x)
	{
		std::cout << "A " << x << "\n";
	}
};

class B
{
private:
	A m_a;

public:
	// class tag változó inicializálása initializer list-el
	B(int y) : m_a (y - 1)
	{
		std::cout << "B " << y << "\n";
	}
};

int main()
{
	B b(5);

	return 0;
}*/

#include <cstdint>

class RGBA
{
private:
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;

public:
	RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255)
		: m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{}

	void print()
	{
		std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) << " b=" 
			<< static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << "\n";
	}
};

int main()
{
	RGBA teal(0, 127, 127);
	teal.print();

	return 0;
}