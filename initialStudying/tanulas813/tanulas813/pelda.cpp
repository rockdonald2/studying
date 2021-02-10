#include "stdafx.h"
#include <iostream>

/*class Valami
{
private:
	int m_ertek = 0;

public:
	Valami() { m_ertek = 0; }
	void hozzaad(int ertek) { m_ertek += ertek; }

	friend void visszaallit(Valami &valami);
};

void visszaallit(Valami &valami)
{
	valami.m_ertek = 0;
}

int main()
{
	Valami vlm; // létrehozza a vlm objectet
	vlm.hozzaad(5); // hozzáad 5-t a vlm object értékéhez
	visszaallit(vlm); // visszaallitja a vlm object értékét 0-ra. vigyázz, nincs itt member selection operator(.)

	return 0;
}*/

/*class Homerseklet;

class Paratartalom
{
private:
	int m_paratartalom;

public:
	Paratartalom(int parat = 0) { m_paratartalom = parat; }

	friend void kiirIdojaras(Paratartalom &paratartalom, Homerseklet &homerseklet);
};

class Homerseklet
{
private:
	int m_homerseklet;

public:
	Homerseklet(int homer = 0) { m_homerseklet = homer; }

	friend void kiirIdojaras(Paratartalom &paratartalom, Homerseklet &homerseklet);
};

void kiirIdojaras(Paratartalom &paratartalom, Homerseklet &homerseklet)
{
	std::cout << "A homerseklet jelenleg " << homerseklet.m_homerseklet <<
		" es a paratartalom jelenleg " << paratartalom.m_paratartalom << ".\n";
}

int main()
{
	Paratartalom prt(10);
	Homerseklet hrt(27);

	kiirIdojaras(prt, hrt);

	return 0;
}*/

//QUIZ

/*// megmondjuk a compilernek, hogy később lesz egy class Vector3d néven
// hogy használni tudjuk a következő classban.
class Vector3d;

class Point3d
{
private:
	double m_x, m_y, m_z;

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z)
	{}

	void print()
	{
		std::cout << "Point(" << m_x << "," << m_y << "," << m_z << ")\n";
	}

	// forward deklaráljuk az alábbi funkciót, mivel képtelen vagyunk használni a Vector3d classot mert még nem volt meghatározva.
	void moveByVector(const Vector3d &vector);
};

class Vector3d
{
private:
	double m_x, m_y, m_z;

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z)
	{}

	void print()
	{
		std::cout << "Vector(" << m_x << "," << m_y << "," << m_z << ")\n";
	}

	// baráttá tesszük az alábbi tag funkciót a Vector3d classal.
	friend void Point3d::moveByVector(const Vector3d &vector);
};

// meghatározzuk a tag funkciót.
void Point3d::moveByVector(const Vector3d &vector)
{
	m_x += vector.m_x;
	m_y += vector.m_y;
	m_z += vector.m_z;
}

int main()
{
	Point3d p(1.0, 2.0, 3.0);
	Vector3d v(2.0, 2.0, -3.0);

	p.print();
	p.moveByVector(v);
	p.print();
	
	return 0;
}*/