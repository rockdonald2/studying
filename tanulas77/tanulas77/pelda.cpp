#include "stdafx.h"
#include <iostream>

void printErtek(int x, int y = 5)
{
	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';
}

int main()
{
	printErtek(2); // y-nak az alap�rtelmezett �rt�ke a 5 lesz haszn�lva
	printErtek(2, 10); // az y-nak a felhaszn�l� �ltal szolg�ltatott 10 lesz haszn�lva
}