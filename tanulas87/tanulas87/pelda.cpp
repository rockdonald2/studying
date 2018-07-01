#include "stdafx.h"
#include <iostream>
#include <cassert>

/*class IntArray
{
private:
	int *m_array;
	int m_length;

public:
	IntArray(int length) // konstruktőr
	{
		assert(length > 0);

		m_array = new int[length];
		m_length = length;
	}

	~IntArray() // destruktőr
	{
		// kitörli a korábbi dinamikusan elosztott arrayt
		delete[] m_array;
	}

	void setValue(int index, int value) { m_array[index] = value; }
	int getValue(int index) { return m_array[index]; }

	int getLength() { return m_length; }
};

int main()
{
	IntArray arr(10);
	for (int index = 0; index < 10; ++index)
	{
		arr.setValue(index, index + 1);
	}

	std::cout << "Az 4.-ik elem erteke: " << arr.getValue(4) << "\n";

	return 0;
} // arr itt semmisül meg, és ekkor hívódik le a destruktőr*/


class Pelda
{
private:
	int m_ertek;

public:
	Pelda(int peldasz)
	{
		std::cout << "Letrejon az " << peldasz << ". szamu pelda.\n";
		m_ertek = peldasz;
	}

	~Pelda()
	{
		std::cout << "Torlodott az " << m_ertek << ". szamu pelda.\n";
	}

	int lekerErtek() { return m_ertek; }
};

int main()
{
	Pelda pelda(1);
	std::cout << pelda.lekerErtek() << '\n';

	Pelda *mPelda = new Pelda(2);
	std::cout << mPelda->lekerErtek() << '\n';
	delete mPelda;

	return 0;
}