#include "stdafx.h"
#include <iostream>

void printErtek(int x, int y = 5)
{
	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';
}

int main()
{
	printErtek(2); // y-nak az alapértelmezett értéke a 5 lesz használva
	printErtek(2, 10); // az y-nak a felhasználó által szolgáltatott 10 lesz használva
}