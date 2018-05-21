#include "stdafx.h"
#include <iostream>

//1
/*
unsigned int randomSzam()
{
	static unsigned int seed = 6969;

	seed = 682367 * seed + 7656756;

	return seed % 32768;
}

int main()
{
	for (int count = 1; count <= 100; ++count)
	{
		std::cout << randomSzam() << "\t";

		if (count % 5 == 0)
		{
			std::cout << "\n";
		}
	}

	return 0;
}
*/

//2
/*
int main()
{
	srand(6969);

	for (int count = 1; count <= 100; ++count)
	{
		std::cout << rand() << "\t";

		if (count % 5 == 0)
			std::cout << "\n";
	}

	return 0;
}
*/

//3
/*
#include <ctime>
int main()
{
	srand(static_cast<unsigned int>(time(0)));

	for (int count = 1; count <= 100; ++count)
	{
		std::cout << rand() << "\t";

		if (count % 5 == 0)
			std::cout << "\n";
	}

	return 0;
}
*/

// 4
/*
int randomSzam(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);

	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

int main()
{
	for (int count = 1; count <= 6; ++count)
		std::cout << randomSzam(1, 6);

	return 0;
}
*/

//5
#include <random>
int main()
{
	std::random_device rd;
	std::mt19937 mersenne(rd());

	std::uniform_int_distribution<> die(1, 6);

	for (int count = 1; count <= 48; ++count)
	{
		std::cout << die(mersenne) << "\t";

		if (count % 6 == 0)
			std::cout << "\n";
	}

	return 0;
}