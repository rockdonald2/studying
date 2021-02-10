#include "stdafx.h"
#include <iostream>

/*struct DatumStruct // bármely struct tagjai alapból publikusak
{
	int nap;
	int honap;
	int ev;
};

class DatumClass // bármely class tagjai alapból privátak
{
	int m_nap;
	int m_honap;
	int m_ev;
};

int main()
{
	DatumStruct datum1;
	// ezért ezeket a structon kivülről is el lehet érni.
	datum1.nap = 25;
	datum1.honap = 06;
	datum1.ev = 2018;

	DatumClass datum2;
	// ezért ezeket a classon kivülről nem lehet elérni, csak más tagok képesek elérni.
	datum2.m_nap = 25; // error
	datum2.m_honap = 06; // error 
	datum2.m_ev = 2018; // error

	return 0;
}*/


/*class DatumClass
{
private: // kifejezetten priváttá teszem az alábbi tag változókat, nem lenne szükséges, mert a pontosítás nélkül alapból privát
	int m_ev;
	int m_honap;
	int m_nap;

public: // kifejezetten publikká teszem, ezért kivülről is elérhető.
	void datumAllitas(int ev, int honap, int nap)
	{
		m_ev = ev;
		m_honap = honap;
		m_nap = nap;
	}

	void kiirDatum()
	{
		std::cout << m_ev << "/" << m_honap << "/" << m_nap << '\n';
	}
};

int main()
{
	DatumClass datum;
	
	datum.datumAllitas(2018, 06, 25);
	datum.kiirDatum();

	return 0;
}*/


/*// QUIZ

class Point3d
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	void setValues(double x, double y, double z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void print()
	{
		std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << '\n';
	}

	bool isEqual(const Point3d &p)
	{
		if (m_x == p.m_x && m_y == p.m_y && m_z == p.m_z)
		{
			return true;
		}
		else
			return false;
	}
};

int main()
{
	Point3d point1;
	point1.setValues(1.0, 2.0, 3.0);

	Point3d point2;
	point2.setValues(1.0, 2.0, 3.0);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are not equal\n";

	Point3d point3;
	point3.setValues(3.0, 4.0, 5.0);

	if (point1.isEqual(point3))
		std::cout << "point1 and point3 are equal\n";
	else
		std::cout << "point1 and point3 are not equal\n";


	return 0;
}*/

#include <assert.h>

class Stack
{
private:
	static const int s_maxStackLength{ 10 };
	int stack[s_maxStackLength];
	int m_next;

public:
	void reset()
	{
		m_next = 0;
		for (int index = 0; index < s_maxStackLength; ++index)
			stack[index] = 0;
	}

	bool push(int x)
	{
		if (m_next == s_maxStackLength)
			return false;

		stack[m_next++] = x;
		return true;
	}

	void pop()
	{
		assert(m_next > 0 && "A stack ures");

		stack[--m_next] = 0;
	}

	void print()
	{

		std::cout << "( ";

		for (int index = 0; index < s_maxStackLength; ++index)
		{
			if (stack[index] != 0)
			{
				std::cout << stack[index] << " ";
			}
			else
				break;
		}

		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}