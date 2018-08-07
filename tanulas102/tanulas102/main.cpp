#include "stdafx.h"
#include <iostream>
#include "Point2d.h"
#include "Creature.h"
#include <string>


int main(void)
{
	std::cout << "Enter a name for your creature: ";
	std::string name;
	std::cin >> name;
	Creature creature(name, Point2d(4, 7));

	while (1)
	{
		std::cout << creature << '\n';

		std::cout << "Enter a new X coordinate for your creature(or -1 to quit): ";
		int x;
		std::cin >> x;
		if (x == -1)
			break;

		std::cout << "Enter a new Y coordinate for your creature(or -1 to quit): ";
		int y;
		std::cin >> y;
		if (y == -1)
			break;

		creature.moveTo(x, y);
	}


	return 0;
}