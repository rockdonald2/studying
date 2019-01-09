#include "pch.h"
#include <iostream>
#include <cstdlib> // exit()

int main()
{
	using namespace std;

	// haszn�ljuk az insertion oper�tort cout-on, hogy ki�rjuk a sz�veget a monitorra
	cout << "Enter your age: ";

	// haszn�ljuk az extraction oper�tort cin-en, hogy inputot szerezz�nk a felhaszn�l�t�l
	int nAge{ 0 };
	cin >> nAge;

	if (nAge <= 0)
	{
		// haszn�ljuk az insertion oper�tort cerr-en, hogy ki�rjuk az error sz�veget a monitorra
		cerr << "Oops, you entered an invalid age!" << endl;
		exit(-1);
	}

	// m�sk�pp, haszn�ljuk az insertion oper�tort �jra cout-on
	cout << "You entered " << nAge << " years old" << endl;

	return 0;
}