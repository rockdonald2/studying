#include "pch.h"
#include <iostream>
#include <cstdlib> // exit()

int main()
{
	using namespace std;

	// használjuk az insertion operátort cout-on, hogy kiírjuk a szöveget a monitorra
	cout << "Enter your age: ";

	// használjuk az extraction operátort cin-en, hogy inputot szerezzünk a felhasználótól
	int nAge{ 0 };
	cin >> nAge;

	if (nAge <= 0)
	{
		// használjuk az insertion operátort cerr-en, hogy kiírjuk az error szöveget a monitorra
		cerr << "Oops, you entered an invalid age!" << endl;
		exit(-1);
	}

	// másképp, használjuk az insertion operátort újra cout-on
	cout << "You entered " << nAge << " years old" << endl;

	return 0;
}