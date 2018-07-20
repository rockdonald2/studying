#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int ertek = 10;
	int *fifo = new int[ertek]; // first in, first out, a legelsőként berakott elemet vehetjük ki elsőként

	// ... vektoros megoldás, lásd include fennébb.

	vector<int>fifoV{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	fifoV[0] = 1;

	fifo[0] = 1;
	
	cout << fifo[0];
	cout << "\n--------\n";
	cout << fifoV[0];
	cout << "\n--------\n";

	delete[] fifo;
	// ... a vektoros verziót nem kell manuálisan felszabadítani
	return 0;
}