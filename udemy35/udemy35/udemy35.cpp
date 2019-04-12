#include "pch.h"
#include <iostream>

//

#include <algorithm> // std::max
#include <cmath> // std::pow
#include <iomanip> // std::setprecision

using namespace std;
int main()
{
	// inicializáljuk az a, b és maximum értékeket
	int a{ 5 }, b{ 7 }, maximum{ 0 };

	// meghatározzuk a max tényleges értékét az std::max függvénnyel
	maximum = max(a, b);

	swap(a, b); // megcseréljük a két értéket

	// !! a = 7;
	double cubic;
	cubic = pow((double)(a), 1.0 / 3);

	cout << cubic << endl;
	cout << setprecision(10) << cubic << endl;
	cout << setprecision(3) << cubic << endl;

	return 0;
}